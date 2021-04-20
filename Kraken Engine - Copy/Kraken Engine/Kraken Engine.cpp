#include <iostream>
#include "Game.h"
#include <chrono>
//declare the game
Game* game = nullptr;
int main(int argc, char* argv[])
{
	//set random seed
	srand(time(NULL));
	// set the frame rate of the game here
	double FPS = 120; 
	//frame calculations
	double frameDelay = 1000 / FPS;
	//declerations
	Uint32 frameStart; 
	double frameTime;
	game = new Game();
	//initialize
	game->init("Kraken Engine", 1536, 864, false); //

	while (game->running())
	{
		//frame calculations
		frameDelay = 1000 / FPS;
		frameStart = SDL_GetTicks();
		//run game details and updates
		game->handleEvents();
		game->update();
		game->render();
		//frame time calculation
		frameTime = SDL_GetTicks() - frameStart;
		//set frame delay
		if (frameDelay > frameTime) {
			SDL_Delay(frameDelay - frameTime);
		}
	}
	//clean up and clear all pointers
	game->clean();
	return 0;
}

//Current Engine Contents and Capabilities:
//Game loop and controll
//create Detail Objects with animations
//create text objects
//create button objects with animations and commands to insert into an action command line