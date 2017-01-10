#pragma once
#include "Coordinates.hh"
#include <SDL\SDL.h>
#include <vector>
#include "Renderer.hh"
using namespace std;


#define WA Wall::Instance()

class Wall {
	vector<COOR> wallPosition;

	Wall(int wallSize) {
		for (int i = 0; i < GRID_WIDTH; ++i) {
			for (int j = 0; j < GRID_HEIGHT; ++j) {
				if (i < wallSize || i >= GRID_WIDTH - wallSize || j < wallSize || j >= GRID_HEIGHT - wallSize) {
					wallPosition.push_back({ i,j });
				}
			}
		}
	}
	
public:
	inline static Wall &Instance(int wallSize = 0) {
		static Wall wall(move(wallSize));
		return wall;
	}
	~Wall() {
		while (!wallPosition.empty()) {
			wallPosition.erase(wallPosition.begin());
		}
	}

	vector<COOR> getWallCoor() {
		return wallPosition;
	}

	void renderWall() {
		SDL_Rect textureSize;
		textureSize.h = textureSize.w = 10;
		if (!wallPosition.empty()) {
			for (int i = 0; i < wallPosition.size(); ++i) {
				textureSize.x = wallPosition[i].column * 10;
				textureSize.y = wallPosition[i].row * 10;
				SDL_RenderCopy(R.GetRenderer(), R.m_textureData[ObjectID::WALL], nullptr, &textureSize);
			}
		}
	}

};