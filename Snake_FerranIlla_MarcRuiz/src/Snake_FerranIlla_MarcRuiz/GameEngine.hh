#pragma once
//#include "System.hh"
//#include "GameScene.hh"

#include <SDL\SDL.h>
#include <SDL\SDL_image.h>
#include <iostream>
#include <string>
#include <stdio.h>
#include "Window.hh"
#include "Renderer.hh"
#include "MenuScene.hh"
using namespace std;


void loadMedia(Renderer renderer) {
	//Load PNG texture
	SDL_Texture* menuButtons = renderer.loadTexture("../../res/gfx/menu_snake.png");
	SDL_Texture* menuPointer = renderer.loadTexture("../../res/gfx/apple.png");
	//load more images above...
	//SDL_Texture* snakeHead = r.loadTexture("...../.png");
	//SDL_Texture* snakeHead = loadTexture("...../.png");
	//SDL_Texture* snakeHead = loadTexture("...../.png");

	//Load Fonts

}
//addScenes(){} function ----easy, normal, hard 

void Run(const int screenWidth, const int screenHeight, string name) {
	
	Window w(name, screenWidth, screenHeight); //Initialize window and SDL
	Renderer r(w.myWindow); //Initialize renderer to the window

	loadMedia(r); //load Media
	//addScenes();


	menuLoop(r, menuButtons, menuPointer);
	bool isRunning = true; // Decides if the game loop is running
	//(class)Scene currentScene(getScene) Defines a reference to a pointer that points to the current scene pointer

	/* game loop
	while (!HasQuit && isRunning) { //Checks while game is still playable
		//Time manager something. Calculates the time difference for deltaTime and FPS limiting purposes
		
		//Game_Update
		
		//Game_Draw

	}
	*/
}

