#pragma once
#include <vector>
#include <SDL\SDL.h>
#include "Coordinates.hh"

using namespace std;

#define S Snake::Instance()

class Snake {
	vector<COOR> snakePosition;

	Snake() {
		snakePosition.push_back({ 17,18 });
		snakePosition.push_back({ 18,18 });
		snakePosition.push_back({ 19,18 });
		snakePosition.push_back({ 20,18 });

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

	void growSnake(int dir) {
		int lastX = snakePosition.back().x;
		int lastY = snakePosition.back().y;
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
		int lastX = snakePosition.back().x;
		int lastY = snakePosition.back().y;
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

	void renderSnake() {
		SDL_Rect textureSize;
		textureSize.h = textureSize.w = 10;
		if (!snakePosition.empty()) {
			for (int i = 0; i < snakePosition.size() - 1; ++i) {
				textureSize.x = snakePosition[i].x * 10;
				textureSize.y = snakePosition[i].y * 10;
				SDL_RenderCopy(R.GetRenderer(), R.m_textureData[ObjectID::SNAKE_BODY], nullptr, &textureSize);
			}
			textureSize.x = snakePosition[snakePosition.size() - 1].x * 10;
			textureSize.y = snakePosition[snakePosition.size() - 1].y * 10;
			SDL_RenderCopy(R.GetRenderer(), R.m_textureData[ObjectID::SNAKE_HEAD], nullptr, &textureSize);
		}
	}


};