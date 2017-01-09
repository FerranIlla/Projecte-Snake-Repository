#pragma once
#include <SDL\SDL.h>

using namespace std;

enum moveDirection { RIGHT, DOWN, LEFT, UP, EXIT};

void keyboardInput(int &direction, int prohibDirection) { 

	SDL_Event e; //Event handler
	int lastDirection = direction;
	//Handle events on queue
	while (SDL_PollEvent(&e) != 0) {
		//User requests quit
		if (e.type == SDL_QUIT || e.key.keysym.sym == SDLK_ESCAPE) {
			direction = EXIT;
		}
		//User presses a key
		else if (e.type == SDL_KEYDOWN) {
			switch (e.key.keysym.sym) {
			case SDLK_RIGHT:
				if (prohibDirection != RIGHT) direction = RIGHT; break;
			case SDLK_DOWN:
				if (prohibDirection != DOWN) direction = DOWN; break;
			case SDLK_LEFT:
				if(prohibDirection != LEFT) direction = LEFT; break;
			case SDLK_UP:
				if(prohibDirection != UP) direction = UP; break;
			}
		}
	}
}