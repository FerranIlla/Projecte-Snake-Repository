#pragma once

#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <unordered_map>
#include "Window.hh"
//#include "Assert.hh"
//#include "Color.hh"
//#include "ID.hh"
//#include "Resource.hh"
//#include "Transform.hh"
using namespace std;

//class renderer

class Renderer {
private:
	//unordered_map<ObjectID,SDL_Texture*> textureData;
	//unordered_map<__,__> fontData;
	SDL_Renderer* renderer = nullptr;
private:
	//constructor
	Renderer() {
		//create renderer for window -- renderer = SDL_CreateRenderer(....);

		//Initialize renderer color

		//Initialize PNG loading
	}
	//Destructor ~Renderer() {};

	//loadTexture(){}

	//coses de fonts --> loadfont, getFont, setFontStyle

	//Push(){} nose ben be què fa

	//clear() -->SDL_RenderClear

	//Render() -->SDL_RenderPresent

};