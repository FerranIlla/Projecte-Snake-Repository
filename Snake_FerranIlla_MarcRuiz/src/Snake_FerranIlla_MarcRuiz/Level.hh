#pragma once
#include <vector>
#include <string>
#include <SDL\SDL.h>
#include "Coordinates.hh"
#include "Renderer.hh"

using namespace std;

#define L Level::Instance()

class Level {
	int score;
	float maxTime;
	float startTimeLevel;
	float chrono;
	int lvlCounter;

public:
	int foodCounter;
	int foodGoal;

	Level(float diffTime) {
		score = 0;
		maxTime = diffTime * 20000;
		chrono = 0; //60000 ms
		lvlCounter = 0;
		foodGoal = 5; //x = 5 where x = initial number of food
		foodCounter = 0;

	}
	inline static Level &Instance(float diffTime = 0) {
		static Level level(move(diffTime));
		return level;
	}

	void nextLevel(int foodXML) {
		WA.changeWallStage();
		++lvlCounter;
		foodCounter = 0;
		foodGoal = 5 + (foodXML*lvlCounter);
		restartChrono();
	}

	void gainPoints() {
		score += 100 * (foodCounter); //when called, foodCounter has already increased
	}

	inline void restartPoints() { score = 0; }

	void updateChrono() {
		chrono = SDL_GetTicks()- startTimeLevel;
	}

	void restartChrono() {
		startTimeLevel = SDL_GetTicks();
		chrono = 0;
	}

	void renderChrono() {
		SDL_Color textColor = { 255, 255, 255 };
		SDL_Rect textPos;
		SDL_Surface* tSurface = TTF_RenderText_Solid(R.GetFont<ARIAL>(), "TIME: ", textColor);
		SDL_Texture* TimeTextTexture = SDL_CreateTextureFromSurface(R.GetRenderer(), tSurface);
		textPos.x = 10 * 10, textPos.y = 46 * 10;
		textPos.w = 70, textPos.h = 20;
		SDL_RenderCopy(R.GetRenderer(), TimeTextTexture, nullptr, &textPos);

		SDL_Rect timeBar;
		timeBar.x = textPos.x + 70; timeBar.y = 46.5 * 10;
		timeBar.w = ((maxTime-chrono)/1000)*2; timeBar.h = 10;
		SDL_SetRenderDrawColor(R.GetRenderer(), 255, 255, 255, 255);
		SDL_RenderFillRect(R.GetRenderer(), &timeBar);
		SDL_SetRenderDrawColor(R.GetRenderer(), 20, 5, 168, 255);
	}

	void renderScore() {
		SDL_Color textColor = { 255, 255, 255 };
		SDL_Rect textPos;
		SDL_Surface* tSurface1 = TTF_RenderText_Solid(R.GetFont<ARIAL>(), "SCORE: ", textColor);
		SDL_Texture* scoreTextTexture = SDL_CreateTextureFromSurface(R.GetRenderer(), tSurface1);
		textPos.x = 45 * 10, textPos.y = 0 * 10;
		textPos.w = 70, textPos.h = 20;
		SDL_RenderCopy(R.GetRenderer(), scoreTextTexture, nullptr, &textPos);

		SDL_Surface* tSurface2 = TTF_RenderText_Solid(R.GetFont<ARIAL>(), to_string(score).c_str(), textColor);
		SDL_Texture* scoreNumbTexture = SDL_CreateTextureFromSurface(R.GetRenderer(), tSurface2);
		textPos.x = textPos.x + 75, textPos.y = 0 * 10;
		textPos.w = to_string(score).length() * 10, textPos.h = 20;
		SDL_RenderCopy(R.GetRenderer(), scoreNumbTexture, nullptr, &textPos);
	}

	void renderFoodLeft() {
		SDL_Color textColor = { 255, 255, 255 };
		SDL_Rect textPos;
		SDL_Surface* tSurface1 = TTF_RenderText_Solid(R.GetFont<ARIAL>(), "FOOD: ", textColor);
		SDL_Texture* FoodTextTexture = SDL_CreateTextureFromSurface(R.GetRenderer(), tSurface1);
		textPos.x = 45 * 10, textPos.y = 46 * 10;
		textPos.w = 70, textPos.h = 20;
		SDL_RenderCopy(R.GetRenderer(), FoodTextTexture, nullptr, &textPos);

		int number = foodGoal - foodCounter;
		SDL_Surface* tSurface2 = TTF_RenderText_Solid(R.GetFont<ARIAL>(), to_string(number).c_str(), textColor);
		SDL_Texture* foodNumbTexture = SDL_CreateTextureFromSurface(R.GetRenderer(), tSurface2);
		textPos.x = textPos.x + 75, textPos.y = 46 * 10;
		textPos.w = to_string(number).length() * 10, textPos.h = 20;
		SDL_RenderCopy(R.GetRenderer(), foodNumbTexture, nullptr, &textPos);
	}

	inline float getChrono() { return chrono; }
	inline float getMaxTime() { return maxTime; }
	inline int getScore() { return score; }
};