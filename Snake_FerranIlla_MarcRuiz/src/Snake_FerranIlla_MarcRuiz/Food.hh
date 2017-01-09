#pragma once
#include "Coordinates.hh"
#include <SDL\SDL.h>
#include <vector>
#include "Renderer.hh"
#include <stdlib.h>

using namespace std;

#define F Food::Instance()
//TODO
class Food {
	COOR foodCoor;
	int counterFoodLeft;
	Food(int maxFood) {
		foodCoor = { 45,25 };
		counterFoodLeft = maxFood;
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

	//TODO
	void respawnFood(vector<COOR> wall, vector<COOR> snake) {
		cout << "soc a dins la funcio respawnFood" << endl;
		vector<COOR> occupedPositions; //sumar els 2 vectors
		for (int i = 0; i < wall.size(); ++i) {
			occupedPositions.push_back(wall[i]);
		}
		for (int i = 0; i < snake.size(); ++i) {
			occupedPositions.push_back(snake[i]);
		}

		cout << "he omplert tots els valors de occupedPosition" << endl;

		vector<COOR> freePositions;
		for (int i = 0; i < GRID_WIDTH; ++i) {
			for (int j = 0; j < GRID_HEIGHT; ++j) {
				for (int k = 0; k < occupedPositions.size(); ++k) {
					if (i != occupedPositions[k].x || j != occupedPositions[k].y) freePositions.push_back({ i,j });
				}
			}
		}
		int randomNumber = rand() % (freePositions.size()-1);
		foodCoor.x = freePositions[randomNumber].x;
		foodCoor.y = freePositions[randomNumber].y;
		--counterFoodLeft;
	}

	int getFoodCounter() {
		return counterFoodLeft;
	}

	void renderFood() {
		SDL_Rect textureSize;
		textureSize.h = textureSize.w = 10;
		textureSize.x = foodCoor.x*10;
		textureSize.y = foodCoor.y*10;
		SDL_RenderCopy(R.GetRenderer(), R.m_textureData[ObjectID::FOOD], nullptr, &textureSize);

	}
};