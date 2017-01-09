//#pragma once
//#include "Coordinates.hh"
//#include <vector>
//using namespace std;
//
//enum gridObjects { EMPTY_BOX, WALL_BOX, FOOD_BOX, SNAKE_BOX};
//
//class Grid {
//	
//	vector <vector <gridObjects> > myGrid;//(10, vector <int> (10, 0));//(63,vector<int>(47,0));
//	
//public:
//	Grid() : myGrid(48, vector<gridObjects>(64, WALL_BOX)) {
//	};
//
//	~Grid() {};
//
//
//	void drawGridInConsole() {
//		for (int i = 0; i < 48; i++) {
//			for (int j = 0; j < 64; j++) {
//				cout << myGrid[i][j];
//			}
//			cout << endl;
//		}
//	}
//
//	void updateGrid() {
//
//	}
//	void renderGrid() {
//		SDL_Rect textureSize;
//		textureSize.h = textureSize.w = 10;
//		for (int i = 0; i < 48; ++i) {
//			for (int j = 0; j < 64; ++j) {
//				textureSize.x = j*10;
//				textureSize.y = i*10;
//				switch (myGrid[i][j]) {
//				case WALL_BOX:
//					SDL_RenderCopy(R.GetRenderer(), R.m_textureData[ObjectID::WALL], nullptr, &textureSize);
//					break;
//				case FOOD_BOX:
//					SDL_RenderCopy(R.GetRenderer(), R.m_textureData[ObjectID::FOOD], nullptr, &textureSize);
//					break;
//				case SNAKE_BOX:
//					SDL_RenderCopy(R.GetRenderer(), R.m_textureData[ObjectID::SNAKE_BODY], nullptr, &textureSize);
//					break;
//				}		
//			}
//		}
//		SDL_RenderPresent(R.GetRenderer());
//	};
//	//more funcitons
//};