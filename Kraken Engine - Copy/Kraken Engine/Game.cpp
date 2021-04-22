#include "Game.h"
//#include "ObjectDataBase.h"



//important global variables declared and insantiated.
ObjectDataBase allObjects;

SDL_Renderer* Game::renderer = nullptr;
SDL_Event event;
std::vector<Event> eventHandle = {};
void sayHi() {
	std::cout << "hi";
}
void sayno() {
	eventHandle.push_back(Event("deleteShip", {}));
	std::cout << "no";
}
void optionScreen() {
	eventHandle.push_back(Event("optionScreen", {}));
}
void loadUpGame() {
	eventHandle.push_back(Event("loadUpGame", {}));
}

//Game class consturctor and destructor
Game::Game()
{
}
Game::~Game()
{
}
//initializes the game, only mess with this if you have to
void Game::init(const char* title, int width, int height, bool fullscreen)
{
	//renderer = rendererStorage::renderer;
	int flags = 0;
	mouseClick = false;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		}

		isRunning = true;
	}
	//
	TTF_Init();

	//allObjects.addObject(new TextObject("title", "arial.ttf", 40, 178, 34, 34, 650, 0, "Viking Raids!"));
	rendererStorage::renderer = renderer;
	eventHandles = &eventHandle;
	//allObjects.addObject(new TextObject("title", "arial.ttf", 40, 178, 34, 34, 650, 0, "Viking Raids!"));
	allObjects.addObject(new KeyInputObject("hello", &sayHi, SDL_SCANCODE_SPACE));
	allObjects.addObject(new KeyInputObject("test", &sayno, SDL_SCANCODE_W));
	//allObjects.addObject(new DetailObject("Homeisland", "assets/otherblueisland2.png", 639, 415, 100, 100));
	allObjects.addObject(new DetailObject("homeBack", "assets/tempHome.png", 0, 0, 1536, 864));
	allObjects.addObject(new ButtonObject("playButton", "assets/tempPlay.png", &optionScreen, 700, 400, 139, 63));




	//set all startup items after this



}
//event handler for SDL events and user created button events
void Game::handleEvents()
{
	// this section should be used when you need to access variables within the game class from button actions
	while (eventHandles->size() > 0) {
		//this goes first
		std::string action = eventHandles->at(0).ID;
		
		//define events in here sent by buttons
		if (action == "optionScreen") {
			std::cout << "ran";
			allObjects.deleteButtonObject("playButton");
			allObjects.deleteDetailObject("homeBack");
			allObjects.addObject(new DetailObject("optionBack", "assets/tempModeSelect.png", 0, 0, 1536, 864));
			allObjects.addObject(new ButtonObject("classicButton", "assets/tempClassic.png", &loadUpGame, 700, 400, 242, 58));
		}
		else if (action == "loadUpGame") {
			allObjects.deleteButtonObject("classicButton");
			allObjects.deleteDetailObject("optionBack");
			allObjects.addObject(new DetailObject("optionBack", "assets/classSelect.png", 0, 0, 1536, 864));
		}

		//this goes last
		eventHandles->erase(eventHandles->begin() + 0);
	}
	

	//this is SDL's event handling section
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}
}
//runs every frame, where most of your code in this file should take place aside from buttons and event handles
void Game::update()
{







	allObjects.updateObjects();
}
//this is where objects are generated on the screen, there is little work you should be doing here unless you are declaring new objects that are not part of the object database
void Game::render()
{
	SDL_RenderClear(renderer);
	allObjects.renderObjects();
	SDL_RenderPresent(renderer); //make sure this goes last
}
//this is run when the game closes, leave this as is.
void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	TTF_Quit();
	SDL_Quit();
}