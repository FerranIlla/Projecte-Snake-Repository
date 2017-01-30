#pragma once
#include "Coordinates.hh"
#include <SDL\SDL.h>
#include <vector>
#include "Renderer.hh"
#include <stdlib.h>
#include <algorithm>
#include <time.h>

using namespace std;

#define F Food::Instance()
//TODO
class Food {
	COOR foodCoor;
	int counterFoodLeft;

	Food(int maxFood) {
		foodCoor = { 45,25 };
		counterFoodLeft = maxFood;
		srand(time(nullptr));

	}
public:
	inline static Food &Instance(int maxFood = 0) {
		static Food food(move(maxFood));
		return food;
	}
	~Food() {};

	COOR GetPos() {
		return foodCoor;
	}

	void respawnFood(vector<COOR> &wall, vector<COOR> &snake) {
		vector<COOR> occupedPositions;
		occupedPositions.resize(wall.size() + snake.size());
		//add both vectors
		for (int i = 0; i < wall.size(); ++i) {
			occupedPositions[i] = wall[i];
		}
		for (int i = 0; i < snake.size(); ++i) {
			occupedPositions[i+wall.size()] = snake[i];
		}

		sort(occupedPositions.begin(), occupedPositions.end());

		vector<COOR> freePositions;
		bool found = false;
		int it = 0;
		for (int i = 0; i < GRID_HEIGHT; ++i) {
			for (int j = 0; j < GRID_WIDTH; ++j) {
				if (occupedPositions[it].column == j && occupedPositions[it].row == i) {
					++it;
				}
				else {
					freePositions.push_back({ j,i });
				}
			}
		}
		
		int randomNumber = rand() % (freePositions.size()-1);
		foodCoor.column = freePositions[randomNumber].column;
		foodCoor.row = freePositions[randomNumber].row;
		--counterFoodLeft;
	}

	int getFoodCounter() {
		return counterFoodLeft;
	}

	void restartFood() {
		foodCoor = { 45,25 };
		//counterFoodLeft = maxFood;
	}

	void renderFood() {
		SDL_Rect textureSize;
		textureSize.h = textureSize.w = 10;
		textureSize.x = foodCoor.column*10;
		textureSize.y = foodCoor.row*10;
		SDL_RenderCopy(R.GetRenderer(), R.m_textureData[ObjectID::FOOD], nullptr, &textureSize);

	}
};