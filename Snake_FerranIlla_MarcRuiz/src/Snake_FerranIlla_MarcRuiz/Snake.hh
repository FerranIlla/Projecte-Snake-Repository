#pragma once
#include <vector>
#include <string>
#include <SDL\SDL.h>
#include "Coordinates.hh"

using namespace std;

#define S Snake::Instance()

class Snake {
	vector<COOR> snakePosition; //last element is the snake head
	int lives;
	

	Snake() {
		snakePosition.push_back({ 25,18 }); //tail
		snakePosition.push_back({ 26,18 });
		snakePosition.push_back({ 27,18 });
		snakePosition.push_back({ 28,18 }); //head
		lives = 3;
	}
public:
	inline static Snake &Instance(void) {
		static Snake snake;
		return snake;
	}
	~Snake() {
		while (!snakePosition.empty()) {
			snakePosition.erase(snakePosition.begin());
		}
	}

	vector<COOR> getSnakeCoor() {
		return snakePosition;
	}

	int getLives() { return lives; }

	void growSnake(int dir) {
		int lastX = snakePosition.back().column;
		int lastY = snakePosition.back().row;
		COOR c;
		switch (dir) {
		case RIGHT:
			c = { lastX + 1,lastY };
			snakePosition.emplace_back(c);
			break;
		case DOWN:
			c = { lastX,lastY + 1 };
			snakePosition.emplace_back(c);
			break;
		case LEFT:
			c = { lastX - 1,lastY };
			snakePosition.emplace_back(c);
			break;
		case UP:
			c = { lastX,lastY - 1 };
			snakePosition.emplace_back(c);
			break;
		}
	}

	void moveSnake(int dir) {
		snakePosition.erase(snakePosition.begin());
		int lastX = snakePosition.back().column;
		int lastY = snakePosition.back().row;
		COOR c;
		switch (dir){
		case RIGHT:
			c = { lastX + 1,lastY };
			snakePosition.emplace_back(c);
			break;
		case DOWN:
			c = { lastX,lastY + 1 };
			snakePosition.emplace_back(c);
			break;
		case LEFT:
			c = { lastX - 1,lastY };
			snakePosition.emplace_back(c);
			break;
		case UP:
			c = { lastX,lastY - 1 };
			snakePosition.emplace_back(c);
			break;
		}
	}

	void restartSnake() {
		Snake tempSnake;
		snakePosition = tempSnake.getSnakeCoor();
	}
	void loseLife(){
		--lives;
	}

	void renderSnake() {
		SDL_Rect textureSize;
		textureSize.h = textureSize.w = 10;
		if (!snakePosition.empty()) {
			for (int i = 0; i < snakePosition.size() - 1; ++i) {
				textureSize.x = snakePosition[i].column * 10;
				textureSize.y = snakePosition[i].row * 10;
				SDL_RenderCopy(R.GetRenderer(), R.m_textureData[ObjectID::SNAKE_BODY], nullptr, &textureSize);
			}
			textureSize.x = snakePosition[snakePosition.size() - 1].column * 10;
			textureSize.y = snakePosition[snakePosition.size() - 1].row * 10;
			SDL_RenderCopy(R.GetRenderer(), R.m_textureData[ObjectID::SNAKE_HEAD], nullptr, &textureSize);
		}
	}

	void renderLives() {
		SDL_Rect textureSize;
		textureSize.w = textureSize.h = 20;
		textureSize.y = 0;
		if (lives >= 1) textureSize.x = 10 * 10;	SDL_RenderCopy(R.GetRenderer(), R.m_textureData[ObjectID::HEART], nullptr, &textureSize);
		if (lives >= 2) textureSize.x = 13 * 10; SDL_RenderCopy(R.GetRenderer(), R.m_textureData[ObjectID::HEART], nullptr, &textureSize);
		if(lives >=3) textureSize.x = 16 * 10; SDL_RenderCopy(R.GetRenderer(), R.m_textureData[ObjectID::HEART], nullptr, &textureSize);


	}


	void renderEndText() {
		SDL_Color textColor = { 255, 255, 255 };
		SDL_Rect textPos;
		SDL_Surface* textSurface = TTF_RenderText_Solid(R.GetFont<ARIAL>(), "GAME OVER", textColor);
		SDL_Texture* scoreTextTexture = SDL_CreateTextureFromSurface(R.GetRenderer(), textSurface);
		textPos.x = 21 * 10, textPos.y = 16 * 10;
		textPos.w = 215, textPos.h = 16 * 10;
		SDL_RenderCopy(R.GetRenderer(), scoreTextTexture, nullptr, &textPos);
	}
};