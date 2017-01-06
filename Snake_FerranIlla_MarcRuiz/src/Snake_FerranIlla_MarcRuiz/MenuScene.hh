#pragma once
#include <SDL\SDL.h>
using namespace std;

#define SCREEN_WIDTH  640
#define SCREEN_HEIGHT  480

const int BUTTON_POINTER_XPOS_RIGHT = 170;
const int BUTTON_POINTER_YPOS = 77;
const int EXIT_BUTTON_POINTER_YPOS = SCREEN_HEIGHT - 120;


void menuLoop(Renderer render, SDL_Texture* options, SDL_Texture* pointer) {
	bool quit = false; //Main loop flag
	SDL_Event e; //Event handler
	int pointerState = SELECT_EASY; //posici� de l'apuntador del menu

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
		SDL_RenderClear(render.myRenderer); //Clear screen
		SDL_RenderCopy(render.myRenderer, menuButtons, nullptr, nullptr); //Render texture to screen

																   //Update apple-pointer yPos.
		pointerScreenPosition.y = BUTTON_POINTER_YPOS * (pointerState + 1);
		if (pointerState == 3) pointerScreenPosition.y = EXIT_BUTTON_POINTER_YPOS;

		SDL_RenderCopy(render.myRenderer, menuPointer, nullptr, &pointerScreenPosition); //Render apple to screen
		SDL_RenderPresent(render.myRenderer); 		//Update the screen
	}
}