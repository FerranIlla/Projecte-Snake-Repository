#pragma once
#include <string>
#include <SDL\SDL.h>
//#include "Assert.hh" Crec que no cal que la fem. Crea una macro per fer saltar errors
using namespace std;

//window class

class Window {
private:
	const int screenWidth, screenHeight;
	const string name;
	SDL_Window* myWindow = nullptr;

public:
	//constructor window
	//Window (name, screenwidth, screenHeight){
		//Initialize SDL & Set texture filtering to linear (SDL_Init and SDL_SetHint)

		//Create window
	//}

	//Destructor ~Window(){};

	//GetWidth()
	//GetHeight()
	//GetName()


};