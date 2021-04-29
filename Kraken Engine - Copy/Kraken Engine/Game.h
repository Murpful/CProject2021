#pragma once
//

#include <SDL_ttf.h>
#include <SDL_image.h>
#include <vector>
#include <string>
#include <iostream>
#include "ObjectDataBase.h"
#include "testObj.h"
#include "Event.h"
#include "battleMapTile.h"
#include "Creature.h"
//#include "rendererStorage.h"





class Game
{
public:
	Game();
	~Game();

	void init(const char* title, int width, int height, bool fullscreen);

	void handleEvents();
	void update();
	bool running() { return isRunning; }
	void render();
	void clean();
	bool mouseClick;
	static SDL_Renderer* renderer;
	std::vector<Event>* eventHandles = {};
private:
	std::vector<battleMapTile> mapTiles = { };
	std::vector<Creature> creatures;
	
	bool isRunning = false;
	bool paused = true;
	int cnt = 0;
	SDL_Window* window;


	///these variables are for game purposes and a test, nto the enigine



};

