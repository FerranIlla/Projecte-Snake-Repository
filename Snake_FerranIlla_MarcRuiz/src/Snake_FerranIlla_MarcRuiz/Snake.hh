#pragma once
#include <vector>
#include <SDL\SDL.h>
#include "Coordinates.hh"

using namespace std;

#define S Snake::Instance()

class Snake {
	vector<COOR> snakePosition; //last element is the snake head
	int lives;

	Snake() {
		snakePosition.push_back({ 17,18 });
		snakePosition.push_back({ 18,18 });
		snakePosition.push_back({ 19,18 });
		snakePosition.push_back({ 20,18 });
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
		textureSize.y = 3;
		if (lives >= 1) textureSize.x = 5 * 10;	SDL_RenderCopy(R.GetRenderer(), R.m_textureData[ObjectID::HEART], nullptr, &textureSize);
		if (lives >= 2) textureSize.x = 8 * 10; SDL_RenderCopy(R.GetRenderer(), R.m_textureData[ObjectID::HEART], nullptr, &textureSize);
		if(lives >=3) textureSize.x = 11 * 10; SDL_RenderCopy(R.GetRenderer(), R.m_textureData[ObjectID::HEART], nullptr, &textureSize);


	}


};