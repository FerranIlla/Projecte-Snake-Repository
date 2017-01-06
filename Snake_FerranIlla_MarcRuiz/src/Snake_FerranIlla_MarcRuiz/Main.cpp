#include "GameEngine.hh"
#include "IOManager.hh"

//Screen dimension constants
#define SCREEN_WIDTH  640
#define SCREEN_HEIGHT  480

//Button apple pointer position



//Needed functions
void close();


//enum for menu possibilities
enum ButtonSelection { SELECT_EASY, SELECT_NORMAL, SELECT_HARD, SELECT_EXIT };

int main(int argc, char* args[]) {

	Run(SCREEN_WIDTH, SCREEN_HEIGHT, "Snake by Ferran and Marc");

	close(); //Free resources and close SDL

	//testXml("../res/test.xml", "1");
	return 0;
}



void close() {
	//Free loaded image
	SDL_DestroyTexture(menuButtons);
	menuButtons = nullptr;

	SDL_DestroyTexture(menuPointer);
	menuPointer = nullptr;
	//Free more loades images above...
	
	//Destroy renderer
	SDL_DestroyRenderer(myRenderer);
	myRenderer = nullptr;

	
}

