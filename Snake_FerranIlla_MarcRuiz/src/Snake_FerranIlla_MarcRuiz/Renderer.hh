#pragma once

#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <unordered_map>
#include "Window.hh"
//#include "Color.hh"
#include "ID.hh"
//#include "Resource.hh"
#include "Transform.hh"
using namespace std;

#define R Renderer::Instance()

// Enum to store text font style
//enum FontStyle {
//	FONT_STYLE_BOLD = TTF_STYLE_BOLD,
//	FONT_STYLE_ITALIC = TTF_STYLE_ITALIC,
//	FONT_STYLE_UNDERLINE = TTF_STYLE_UNDERLINE,
//	FONT_STYLE_NORMAL = TTF_STYLE_NORMAL
//};

// Renderer class
class Renderer {
	Renderer() {
		//Create renderer for window
		m_SDLRenderer = SDL_CreateRenderer(W.GetWindow(), -1, SDL_RENDERER_ACCELERATED);
		//Initialize renderer color
		SDL_SetRenderDrawColor(m_SDLRenderer, 20, 5, 168, 255); //20, 5, 168 = blau mari dels sprites
		//Initialize PNG loading
		constexpr int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
		(IMG_Init(imgFlags) & imgFlags);
		TTF_Init();
	}

public:
	inline static Renderer &Instance(void) {
		static Renderer renderer;
		return renderer;
	}
	~Renderer() {
		if (!m_textureData.empty()) {
			for (auto &t : m_textureData) SDL_DestroyTexture(t.second), t.second = nullptr;
		}
		for (auto &f : m_fontData) TTF_CloseFont(f.second), f.second = nullptr;
		SDL_DestroyRenderer(m_SDLRenderer), m_SDLRenderer = nullptr;
		IMG_Quit();
		TTF_Quit();
	}
	template<ObjectID objectID>
	void LoadTexture(string &&filename) {
		//Load image at specified path
		SDL_Surface* loadedSurface = IMG_Load(filename.c_str());
		if (loadedSurface == nullptr)
		{
			printf("Unable to load image %s! SDL_image Error: %s\n", filename.c_str(), IMG_GetError());
		}
		//Create texture from surface pixels
		m_textureData.emplace(objectID, SDL_CreateTextureFromSurface(m_SDLRenderer, loadedSurface));
		if (m_textureData[objectID] == nullptr) cout << "Unable to create texture from " << filename << endl;

		SDL_FreeSurface(loadedSurface); //Get rid of loaded surface
	}
	
	#pragma region
	template<FontID fontID> void LoadFont(string &&filename, int size) {
		m_fontData.emplace(fontID, TTF_OpenFont(filename.c_str(), size)).second;
	}
	template<FontID fontID> inline TTF_Font *GetFont() {
		return m_fontData[fontID];
	}
	template<FontID fontID, int style> void SetFontStyle() {
		TTF_SetFontStyle(m_fontData[fontID], style);
	}
	#pragma endregion fonts
	

	inline SDL_Renderer* GetRenderer() const { return m_SDLRenderer; }
	void Clear() const { SDL_RenderClear(m_SDLRenderer); };
	void Render() const { SDL_RenderPresent(m_SDLRenderer); };

	unordered_map<ObjectID, SDL_Texture*> m_textureData;

private:
	unordered_map<FontID, TTF_Font*> m_fontData;
	SDL_Renderer* m_SDLRenderer{ nullptr };
};