#pragma once
#include "Coordinates.hh"
#include <SDL\SDL.h>
#include <vector>
#include "Renderer.hh"
using namespace std;


#define WA Wall::Instance()

class Wall {
	vector<COOR> wallPosition;
	vector<COOR> wallStage1;
	vector<COOR> wallStage2;

	int sizeOfWall;
	int StageWheel = 0;
	Wall(int wSize) {
		for (int i = 0; i < GRID_WIDTH; ++i) {
			for (int j = 0; j < GRID_HEIGHT; ++j) {
				if (i < wSize || i >= GRID_WIDTH - wSize || j < wSize || j >= GRID_HEIGHT - wSize) {
					wallPosition.push_back({ i,j });
				}
			}
		}
		sizeOfWall = wSize;
	}


	void restartWall() {
		Wall tempWall(sizeOfWall);
		wallPosition = tempWall.getWallCoor();
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

	void changeWallStage() {
		restartWall();
		StageWheel++;
		if (StageWheel == 3) StageWheel = 0;
		//add walls according to stage
		switch (StageWheel) {
		case 0:
			break;
		case 1:
			wallPosition.insert(wallPosition.end(), wallStage1.begin(), wallStage1.end());
			break;
		case 2:
			wallPosition.insert(wallPosition.end(), wallStage2.begin(), wallStage2.end());
			break;
		}
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

	void loadStages() {
	#pragma region Stage1
		for (int i = 19; i <= 44; ++i) {
			wallStage1.push_back({ i,15 });
			wallStage1.push_back({ i,32 });
		}	

	#pragma endregion

	#pragma region Stage2
		for (int i = 13; i <= 34; ++i) {
			if (i <= 19 || i >= 28) {
				wallStage2.push_back({ 23,i });
				wallStage2.push_back({ 40,i });
			}
		}
	#pragma endregion

	}
};