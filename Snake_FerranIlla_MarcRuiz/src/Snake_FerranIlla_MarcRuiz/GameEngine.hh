#pragma once
//#include "System.hh"

#include <SDL\SDL.h>
#include <SDL\SDL_image.h>
#include <iostream>
#include <string>
#include "Window.hh"
#include "Renderer.hh"
#include "MenuScene.hh"
#include "InputManager.hh"
#include "IOManager.hh"
#include "Snake.hh"
#include "GameLoop.hh"
#include "Wall.hh"
#include "Food.hh"
using namespace std;



void LoadMedia(void) {
	R.LoadFont<FontID::ARIAL>("../../res/fnt/arial.ttf", 40);
	R.SetFontStyle<ARIAL, 1>();
	R.LoadTexture<ObjectID::FOOD>("../../res/gfx/apple.png");
	R.LoadTexture<ObjectID::MENU>("../../res/gfx/menu.png");
	R.LoadTexture<ObjectID::SNAKE_BODY>("../../res/gfx/snakeBody.png");
	R.LoadTexture<ObjectID::SNAKE_HEAD>("../../res/gfx/snakeHead.png");
	R.LoadTexture<ObjectID::WALL>("../../res/gfx/wall.png");
	R.LoadTexture<ObjectID::HEART>("../../res/gfx/life.png");
}



void Run(string name, int screenWidth, int screenHeight) {

	Window::Instance(move(name), move(screenWidth), move(screenHeight)); // Initialize window Singleton instance for the first time
	LoadMedia(); // Initialize renderer Singleton instance for the first time and load images

	int gameScene; //0=easy, 1=normal, 2=hard, 3=exit;
	menuLoop(gameScene); //menu scene
	if (gameScene != 3) {
		
		readDifficultyXml(gameScene); //read data from xml -->timeXML, speedXML, foodXML, wallXML, incrementXML (some of these are not used)

		Wall::Instance(wallXML); //Initialize Wall Singleton instance for the first time
		
		//gameLoop
		Uint32 lastUpdateTime = SDL_GetTicks();
		int lastInput = RIGHT; //enum moveDirection with RIGHT, DOWN, LEFT, UP, EXIT as value
		int prohibitedDirection = LEFT; 
		bool gameOver = false;

		while (lastInput != EXIT) {
			keyboardInput(lastInput, prohibitedDirection);

			//UPDATE
			if ((SDL_GetTicks() - lastUpdateTime) > 1000 / speedXML) { //the FPS varies with the speeedXML value
				//check collisions
				if (snakeCollides()) {
					if (S.getLives() <= 1) {
						S.renderEndText();
						SDL_RenderPresent(R.GetRenderer());
						SDL_Delay(2700);
						S.score = 0;
						lastInput = EXIT;
						gameOver = true;

					}
					if (!gameOver) {
						SDL_Delay(2000);
						S.restartSnake();
						F.restartFood();
						lastInput = RIGHT;
					}
				}
				//check if snake eats an apple
				else if (snakeEats()) {
					S.growSnake(lastInput);
					S.score += 5;
					F.respawnFood(WA.getWallCoor(), S.getSnakeCoor());
				}
				//move snake normally
				else {
					S.moveSnake(lastInput);
				}
				lastUpdateTime = SDL_GetTicks(); //update time flag
				switch (lastInput) { //snake can't turn around through itself
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
			S.renderScore();
			SDL_RenderPresent(R.GetRenderer());

		}
	}


}

