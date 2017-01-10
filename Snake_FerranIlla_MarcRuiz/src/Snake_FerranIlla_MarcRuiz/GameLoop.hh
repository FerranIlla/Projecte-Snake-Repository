#pragma once
#include <SDL\SDL.h>
#include "MenuScene.hh"
#include "Snake.hh"
#include "Wall.hh"
#include "Food.hh"
using namespace std;

//some gameLoop functions

bool snakeCollides() {
	//snakes collides with wall
	for (int i = 0; i < WA.getWallCoor().size(); ++i) {
		if (S.getSnakeCoor().back() == WA.getWallCoor()[i]) {
			cout << "with wall" << endl;
			return true;
		}
	}

	//snakes collides with snake
	for (int j = 0; j < S.getSnakeCoor().size() - 4; ++j) {
		if (S.getSnakeCoor().back() == S.getSnakeCoor()[j]) {
			cout << "with snake" << endl;
			return true;
		}
	}
	return false;
}

bool snakeEats() {
	//snake collides with food
	return (S.getSnakeCoor().back() == F.GetPos());
}