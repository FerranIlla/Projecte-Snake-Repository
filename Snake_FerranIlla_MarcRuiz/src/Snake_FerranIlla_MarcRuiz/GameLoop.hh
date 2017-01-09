//#pragma once
//#include <SDL\SDL.h>
//#include "MenuScene.hh"
//using namespace std;
//
//void gameLoop() {
//
//	bool quit = false; //Main loop flag
//	SDL_Event e; //Event handler
//	int pointerState = SELECT_EASY; //posició de l'apuntador del menu
//
//	SDL_Rect pointerScreenPosition; //Info about the pointer position
//	pointerScreenPosition.h = 40;
//	pointerScreenPosition.w = 40;
//	pointerScreenPosition.x = SCREEN_WIDTH / 2 - BUTTON_POINTER_XPOS_RIGHT;
//	pointerScreenPosition.y = BUTTON_POINTER_YPOS;
//
//	//While application is running
//	while (!quit) {
//		//Handle events on queue
//		while (SDL_PollEvent(&e) != 0) {
//			//User requests quit
//			if (e.type == SDL_QUIT || e.key.keysym.sym == SDLK_ESCAPE) {
//				quit = true;
//			}
//			//User presses a key
//			else if (e.type == SDL_KEYDOWN) {
//				if (e.key.keysym.sym == SDLK_DOWN) {
//					++pointerState;
//					if (pointerState == 4) pointerState = SELECT_EASY;
//				}
//				else if (e.key.keysym.sym == SDLK_UP) {
//					--pointerState;
//					if (pointerState == -1) pointerState = SELECT_EXIT;
//				}
//				else if (acceptKeyDown) {
//					quit = true;
//				}
//			}
//		}
//		SDL_RenderClear(R.GetRenderer()); //Clear screen
//		SDL_RenderCopy(R.GetRenderer(), R.m_textureData[ObjectID::MENU], nullptr, nullptr); //Render texture to screen
//
//																							//Update apple-pointer yPos.
//		pointerScreenPosition.y = BUTTON_POINTER_YPOS * (pointerState + 1);
//		if (pointerState == 3) pointerScreenPosition.y = EXIT_BUTTON_POINTER_YPOS;
//
//		SDL_RenderCopy(R.GetRenderer(), R.m_textureData[ObjectID::FOOD], nullptr, &pointerScreenPosition); //Render apple to screen
//		SDL_RenderPresent(R.GetRenderer()); 		//Update the screen
//	}
//}
