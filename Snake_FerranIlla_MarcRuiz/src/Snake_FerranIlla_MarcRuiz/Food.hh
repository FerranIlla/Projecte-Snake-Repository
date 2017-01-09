#pragma once
#include "Coordinates.hh"
#include <SDL\SDL.h>
#include <vector>
#include "Renderer.hh"
using namespace std;

#define F Food::Instance()
//TODO
class Food {
	COOR foodCoor;
	int counterFoodLeft;
	Food(int maxFood) {
		foodCoor = { 50,30 };
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
	void rerspawnFood(vector<COOR> wall, vector<COOR> snake) {
		vector<COOR> occupedPositions; //sumar els 2 vectors
		vector<COOR> freePositions;
		for (int i = 0; i < GRID_WIDTH; ++i) {
			for (int j = 0; j < GRID_HEIGHT; ++j) {
				for (int k = 0; k < occupedPositions.size(); ++k) {
					if (i != occupedPositions[k].x || j != occupedPositions[k].y) freePositions.push_back({ i,j });
				}
			}
		}
		//fer random entre 0 i freePositions.size();
		--counterFoodLeft;
	}

	int getFoodCounter() {
		return counterFoodLeft;
	}

	void renderFood() {
		SDL_Rect textureSize;
		textureSize.h = textureSize.w = 10;
		textureSize.x = foodCoor.x;
		textureSize.y = foodCoor.y;
		SDL_RenderCopy(R.GetRenderer(), R.m_textureData[ObjectID::FOOD], nullptr, &textureSize);

	}
};