#pragma once
//#include "System.hh"

#include <SDL\SDL.h>
#include <SDL\SDL_image.h>
#include <iostream>
#include <string>
#include <stdio.h>
#include "Window.hh"
#include "Renderer.hh"
#include "MenuScene.hh"
#include "InputManager.hh"
#include "IOManager.hh"
#include "Grid.hh"
#include "Snake.hh"
#include "GameLoop.hh"
#include "Wall.hh"
#include "Food.hh"
using namespace std;



void LoadMedia(void) {
	/*R.LoadFont<FontID::ARIAL>("fnt/arial.ttf", 40);
	R.LoadFont<FontID::CANDY>("fnt/candy.ttf", 50);
	R.LoadFont<FontID::FACTORY>("fnt/candsb.ttf", 80);*/
	R.LoadTexture<ObjectID::FOOD>("../../res/gfx/apple.png");
	R.LoadTexture<ObjectID::MENU>("../../res/gfx/menu.png");
	R.LoadTexture<ObjectID::SNAKE_BODY>("../../res/gfx/snakeBody.png");
	R.LoadTexture<ObjectID::SNAKE_HEAD>("../../res/gfx/snakeHead.png");
	R.LoadTexture<ObjectID::WALL>("../../res/gfx/wall.png");
	R.LoadTexture<ObjectID::HEART>("../../res/gfx/life.png");
}
//addScenes(){} function ----easy, normal, hard 


void Run(string name, int screenWidth, int screenHeight) {

	Window::Instance(move(name), move(screenWidth), move(screenHeight)); // Initialize window Singleton instance for the first time
	LoadMedia(); // Initialize renderer Singleton instance for the first time and load images
	//addScenes();


	int gameScene; //0=easy, 1=normal, 2=hard, 3=exit;


	menuLoop(gameScene); //entra al menu
	readDifficultyXml(gameScene); //agafa les dades de xml
	//timeXML, speedXML, foodXML, numColumnsXML, numRowsXML, incrementXML);

	Wall::Instance(wallXML);

	


	//gameLoop
	Uint32 lastUpdateTime = SDL_GetTicks();
	int lastInput = 0; //RIGHT
	int prohibitedDirection = 2; //LEFT

	while (lastInput != EXIT) { //EXIT = 4;
		keyboardInput(lastInput, prohibitedDirection); //InputManager.hh

		//UPDATE
		if (SDL_GetTicks() - lastUpdateTime > 1000 / speedXML) { 
			//check collisions
			if (snakeCollides()) {
				cout << "snake has collided" << endl;
				SDL_Delay(2000);
				S.restartSnake();
				F.restartFood();
				lastInput = RIGHT;
			}
			else if (snakeEats()) {
				S.growSnake(lastInput);
				F.respawnFood(WA.getWallCoor(),S.getSnakeCoor());
			}
			else {
				S.moveSnake(lastInput);
			}
			lastUpdateTime = SDL_GetTicks();
			switch (lastInput) {
			case RIGHT: prohibitedDirection = LEFT; break;
			case DOWN: prohibitedDirection = UP; break;
			case LEFT: prohibitedDirection = RIGHT; break;
			case UP: prohibitedDirection = DOWN; break;
			}
		}

		//DRAW

		SDL_RenderClear(R.GetRenderer());
		F.renderFood();
		S.renderSnake();
		WA.renderWall();
		S.renderLives();
		SDL_RenderPresent(R.GetRenderer());



	}
	/*
	Grid g;
	cout << "AFTER GRID " << endl;
	SDL_RenderClear(R.GetRenderer());
	//g.renderGrid();
	S.renderSnake();
	SDL_Delay(2000);
	for (int i = 0; i < 20; ++i) {
		SDL_Delay(50);
		SDL_RenderClear(R.GetRenderer());
		S.moveSnake(RIGHT);
		S.renderSnake();
	}
	SDL_Delay(2000);
	*/


}

