#include "GameEngine.hh"


//Screen dimension constants
#define SCREEN_WIDTH  640
#define SCREEN_HEIGHT  480

//Button apple pointer position

const int BUTTON_POINTER_XPOS_RIGHT = 170;
const int BUTTON_POINTER_YPOS = 77;
const int EXIT_BUTTON_POINTER_YPOS = SCREEN_HEIGHT - 120;

//Needed functions
void init();
void loadMedia();
SDL_Texture* loadTexture(string path);
void close();
void gameLoop();

//Declare window, renderer and textures
SDL_Window* myWindow = nullptr;
SDL_Renderer* myRenderer = nullptr;
SDL_Texture* menuButtons = nullptr;
SDL_Texture* menuPointer = nullptr;

//enum for menu possibilities
enum ButtonSelection { SELECT_EASY, SELECT_NORMAL, SELECT_HARD, SELECT_EXIT };

int main(int argc, char* args[]) {

	init(); //Start up SDL and create window, renderer. Init png loading
	loadMedia(); //load images

	gameLoop();
	close(); //Free resources and close SDL
	return 0;
}

void init() {
	//Start up SDL and create window, renderer. Init png loading
	SDL_Init(SDL_INIT_VIDEO);
	myWindow = SDL_CreateWindow("Snake Menu", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	myRenderer = SDL_CreateRenderer(myWindow, -1, SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(myRenderer, 20, 5, 168, 255); //20, 5, 168 = dark blue
	int imgFlags = IMG_INIT_PNG;
	IMG_Init(imgFlags) & imgFlags;
}

void loadMedia() {
	//Load PNG texture
	menuButtons = loadTexture("../../res/gfx/menu_snake.png");
	menuPointer = loadTexture("../../res/gfx/apple.png");
	//load more images above...
}

SDL_Texture* loadTexture(string path) {
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL) {
		cout << "Unable to load image " << path.c_str() << "! SDL_image Error: " << IMG_GetError() << endl;
	}
	else {
		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(myRenderer, loadedSurface);
		if (newTexture == NULL) {
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}
		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}
	return newTexture;
}

void close() {
	//Free loaded image
	SDL_DestroyTexture(menuButtons);
	menuButtons = nullptr;

	SDL_DestroyTexture(menuPointer);
	menuPointer = nullptr;
	//Free more loades images above...

	//Destroy window
	SDL_DestroyRenderer(myRenderer);
	SDL_DestroyWindow(myWindow);
	myWindow = nullptr;
	myRenderer = nullptr;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

void gameLoop() {
	bool quit = false; //Main loop flag
	SDL_Event e; //Event handler
	int pointerState = SELECT_EASY; //posició de l'apuntador del menu

	SDL_Rect pointerScreenPosition; //Info about the pointer position
	pointerScreenPosition.h = 40;
	pointerScreenPosition.w = 40;
	pointerScreenPosition.x = SCREEN_WIDTH / 2 - BUTTON_POINTER_XPOS_RIGHT;
	pointerScreenPosition.y = BUTTON_POINTER_YPOS;

	//While application is running
	while (!quit) {
		//Handle events on queue
		while (SDL_PollEvent(&e) != 0) {
			//User requests quit
			if (e.type == SDL_QUIT || e.key.keysym.sym == SDLK_ESCAPE) {
				quit = true;
			}
			//User presses a key
			else if (e.type == SDL_KEYDOWN) {
				if (e.key.keysym.sym == SDLK_DOWN) {
					++pointerState;
					if (pointerState == 4) pointerState = SELECT_EASY;
				}
				else if (e.key.keysym.sym == SDLK_UP) {
					--pointerState;
					if (pointerState == -1) pointerState = SELECT_EXIT;
				}
			}
		}
		SDL_RenderClear(myRenderer); //Clear screen
		SDL_RenderCopy(myRenderer, menuButtons, nullptr, nullptr); //Render texture to screen

																   //Update apple-pointer yPos.
		pointerScreenPosition.y = BUTTON_POINTER_YPOS * (pointerState + 1);
		if (pointerState == 3) pointerScreenPosition.y = EXIT_BUTTON_POINTER_YPOS;

		SDL_RenderCopy(myRenderer, menuPointer, nullptr, &pointerScreenPosition); //Render apple to screen
		SDL_RenderPresent(myRenderer); 		//Update the screen
	}
}