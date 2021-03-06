#pragma once
#include <string>
#include <SDL/SDL.h>
#include <SDL\SDL_ttf.h>

#define W Window::Instance()

// Window class to store the whole info related to the game screen interface
class Window {
	Window(const std::string &&name, int &&screenWidth, int &&screenHeight) : m_name(name), m_screenWidth(screenWidth), m_screenHeight(screenHeight) {
		//Initialize SDL & Set texture filtering to linear
		SDL_Init(SDL_INIT_EVERYTHING);
		SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
		//Create window
		m_SDLWindow = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
	}

public:
	inline static Window &Instance(std::string &&name = "", int &&screenWidth = 0, int &&screenHeight = 0) {
		static Window window(std::move(name), std::move(screenWidth), std::move(screenHeight));
		return window;
	}
	~Window() {
		SDL_DestroyWindow(m_SDLWindow), m_SDLWindow = nullptr; //Destroy window
		SDL_Quit(); //Quit SDL subsystems
	}
	inline SDL_Window* GetWindow() const { return m_SDLWindow; }
	inline int GetWidth() const { return m_screenWidth; };
	inline int GetHeight() const { return m_screenHeight; };
	inline const std::string &GetName() const { return m_name; };
private:
	SDL_Window* m_SDLWindow{ nullptr };
	const int m_screenWidth, m_screenHeight;
	const std::string m_name;
};