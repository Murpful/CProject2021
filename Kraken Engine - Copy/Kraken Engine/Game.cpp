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
void openHand() {
	eventHandle.push_back(Event("openHand", {}));

}
void closeHand() {
	eventHandle.push_back(Event("closeHand", {}));
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
void startRound() {
	eventHandle.push_back(Event("startRound", {}));
}
void moveUp() {
	eventHandle.push_back(Event("scrollUp", {}));
}
void moveDown() {
	eventHandle.push_back(Event("scrollDown", {}));
}
void moveLeft() {
	eventHandle.push_back(Event("scrollLeft", {}));
}
void moveRight() {
	eventHandle.push_back(Event("scrollRight", {}));
}
void playCard(int cardNumber) {
	eventHandle.push_back(Event("playCard", { cardNumber }));
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
	creatures = {};
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
void printALLFunc(battleMapTile tile) {
	std::cout << "Battle Map Tile: " << std::endl << "C1: " << tile.c1 << std::endl << "C2: " << tile.c2 << std::endl << "C3: " << tile.c3 << std::endl << "C4: " << tile.c4 << std::endl << "C5: " << tile.c5 << std::endl << "C6: " << tile.c6 << std::endl;
}
void Game::handleEvents()
{
	// this section should be used when you need to access variables within the game class from button actions
	while (eventHandles->size() > 0) {
		//this goes first
		std::string action = eventHandles->at(0).ID;
		
		//define events in here sent by buttons
		if (paused) {
			if (action == "optionScreen") {
				allObjects.deleteAll();
				allObjects.addObject(new DetailObject("optionBack", "assets/tempModeSelect.png", 0, 0, 1536, 864));
				allObjects.addObject(new ButtonObject("classicButton", "assets/tempClassic.png", &startRound, 700, 400, 242, 58));
			}
			else if (action == "loadUpGame") {
				allObjects.deleteAll();
				allObjects.addObject(new DetailObject("optionBack", "assets/classSelect.png", 0, 0, 1536, 864));
			}
			else if (action == "startRound") {
				paused = false;
				int mapsize = 7;
				int currentTile = 0;
				int currentRad = 1;
				int completedRad = 0;
				int totalTiles = 1;

				allObjects.deleteAll();
				allObjects.addObject(new KeyInputObject("moveUp", &moveUp, SDL_SCANCODE_W, true));
				allObjects.addObject(new KeyInputObject("moveDown", &moveDown, SDL_SCANCODE_S, true));
				allObjects.addObject(new KeyInputObject("moveLeft", &moveLeft, SDL_SCANCODE_A, true));
				allObjects.addObject(new KeyInputObject("moveRight", &moveRight, SDL_SCANCODE_D, true));
				allObjects.addObject(new DetailObject("tile0", "assets/RegHexTrees.png", 700, 350, 110, 96));

				allObjects.addObject(new ButtonObject("cardButton", "assets/cardsIcon.png",&openHand,0,814,50,50,false));
				allObjects.addObject(new KeyInputObject("cardKey", &openHand, SDL_SCANCODE_E, false));
				//tells number of cards in deck
				std::cout << std::endl << playerCharacter.deck.size() << std::endl;
				allObjects.addObject(new TextObject("cardsInHand", "ariali.ttf", 20, 255, 255, 255, 50, 815, std::to_string(playerCharacter.deck.size())));
				mapTiles.push_back(battleMapTile(1, -1, -1, -1, -1, -1));
				currentTile += 1;
				for (int i = 1; i < mapsize; i++)
				{

					if (currentTile == 1) {
						mapTiles.push_back(battleMapTile(-1, -1, -1, 0, -1, -1));
					}
					else {

						if (currentRad != mapsize) {
							mapTiles.push_back(battleMapTile(-1, -1, -1, (currentTile)-(((currentRad - 1) * 6)), -1, -1));
						}
						else {
							mapTiles.push_back(battleMapTile(-1, -1, -1, -1, -1, -1));
						}
					}
					std::string tileName = "tile";
					char tex1[] = "assets/RegHexHills.png";
					char tex2[] = "assets/RegHexTrees.png";

					tileName += std::to_string(currentTile);
					allObjects.addObject(new DetailObject(tileName, "assets/RegHexHills.png", 700, (350 - (96 * currentRad)), 110, 96));
					//std::cout << " " << allObjects.detailedObjects.at(allObjects.detailedObjects.size() - 1)->objectID;


					mapTiles.at((currentTile)-(((currentRad - 1) * 6))).c1 = currentTile;
					//std::cout << (currentTile-1) << std::endl;
					totalTiles += 1;
					currentTile += 1;

					int ss = 3;
					int currentx = 700;
					int currenty = (350 - (96 * currentRad));
					for (int k = 0; k < 6; k++)
					{

						totalTiles += 1;
						//std::cout << std::endl << currentTile << std::endl;
						for (int i = 0; i < completedRad; i++)
						{
							std::string ntileName = "tile";
							ntileName += std::to_string(currentTile);
							mapTiles.push_back(battleMapTile(-1, -1, -1, -1, -1, -1));
							if (ss == 3) {
								currenty += 48;
								currentx += 83;
								allObjects.addObject(new DetailObject(ntileName, "assets/RegHexHills.png", currentx, currenty, 110, 96));
								mapTiles.at(mapTiles.size() - 1).c6 = currentTile - 1;
								mapTiles.at(mapTiles.size() - 2).c3 = currentTile;
								//std::cout << "thingy tile: " << (((currentRad-1) * 6) + 1);

								mapTiles.at(mapTiles.size() - 1).c5 = currentTile - (((currentRad - 1) * 6) + 1);
								mapTiles.at(currentTile - (((currentRad - 1) * 6) + 1)).c2 = currentTile;
								mapTiles.at(mapTiles.size() - 1).c4 = currentTile - (((currentRad - 1) * 6));
								mapTiles.at(currentTile - (((currentRad - 1) * 6))).c1 = currentTile;

								currentTile += 1;
							}
							if (ss == 4) {
								currenty += 96;
								//currentx += 83;
								allObjects.addObject(new DetailObject(ntileName, "assets/RegHexHills.png", currentx, currenty, 110, 96));
								mapTiles.at(mapTiles.size() - 1).c1 = currentTile - 1;
								mapTiles.at(mapTiles.size() - 2).c4 = currentTile;

								mapTiles.at(mapTiles.size() - 1).c6 = currentTile - (((currentRad - 1) * 6) + 2); //you were adding thingy direction for side 4, so yeah, finish that it would bew rather nice if you did that, you already did it for one and the code here is for one, just increase c5 and c4 by one value and the +1 to +2 and the +0 to +1
								mapTiles.at(currentTile - (((currentRad - 1) * 6) + 2)).c3 = currentTile;
								mapTiles.at(mapTiles.size() - 1).c5 = currentTile - (((currentRad - 1) * 6) + 1);
								mapTiles.at(currentTile - (((currentRad - 1) * 6) + 1)).c2 = currentTile;

								currentTile += 1;

							}
							if (ss == 5) {
								currenty += 48;
								currentx -= 83;
								allObjects.addObject(new DetailObject(ntileName, "assets/RegHexHills.png", currentx, currenty, 110, 96));
								mapTiles.at(mapTiles.size() - 1).c2 = currentTile - 1;
								mapTiles.at(mapTiles.size() - 2).c5 = currentTile;
								mapTiles.at(mapTiles.size() - 1).c1 = currentTile - (((currentRad - 1) * 6) + 3); //you were adding thingy direction for side 4, so yeah, finish that it would bew rather nice if you did that, you already did it for one and the code here is for one, just increase c5 and c4 by one value and the +1 to +2 and the +0 to +1
								mapTiles.at(currentTile - (((currentRad - 1) * 6) + 3)).c4 = currentTile;
								mapTiles.at(mapTiles.size() - 1).c6 = currentTile - (((currentRad - 1) * 6) + 2);
								mapTiles.at(currentTile - (((currentRad - 1) * 6) + 2)).c3 = currentTile;
								currentTile += 1;
							}
							if (ss == 6) {
								currenty -= 48;
								currentx -= 83;
								allObjects.addObject(new DetailObject(ntileName, "assets/RegHexHills.png", currentx, currenty, 110, 96));
								mapTiles.at(mapTiles.size() - 1).c3 = currentTile - 1;
								mapTiles.at(mapTiles.size() - 2).c6 = currentTile;
								mapTiles.at(mapTiles.size() - 1).c2 = currentTile - (((currentRad - 1) * 6) + 4); //you were adding thingy direction for side 4, so yeah, finish that it would bew rather nice if you did that, you already did it for one and the code here is for one, just increase c5 and c4 by one value and the +1 to +2 and the +0 to +1
								mapTiles.at(currentTile - (((currentRad - 1) * 6) + 4)).c5 = currentTile;
								mapTiles.at(mapTiles.size() - 1).c1 = currentTile - (((currentRad - 1) * 6) + 3);
								mapTiles.at(currentTile - (((currentRad - 1) * 6) + 3)).c4 = currentTile;
								currentTile += 1;
							}
							if (ss == 1) {
								currenty -= 96;
								//currentx -= 83;
								allObjects.addObject(new DetailObject(ntileName, "assets/RegHexHills.png", currentx, currenty, 110, 96));
								mapTiles.at(mapTiles.size() - 1).c4 = currentTile - 1;
								mapTiles.at(mapTiles.size() - 2).c1 = currentTile;
								mapTiles.at(mapTiles.size() - 1).c3 = currentTile - (((currentRad - 1) * 6) + 5); //you were adding thingy direction for side 4, so yeah, finish that it would bew rather nice if you did that, you already did it for one and the code here is for one, just increase c5 and c4 by one value and the +1 to +2 and the +0 to +1
								mapTiles.at(currentTile - (((currentRad - 1) * 6) + 5)).c6 = currentTile;
								mapTiles.at(mapTiles.size() - 1).c2 = currentTile - (((currentRad - 1) * 6) + 4);
								mapTiles.at(currentTile - (((currentRad - 1) * 6) + 4)).c5 = currentTile;
								currentTile += 1;
							}
							if (ss == 2) {
								currenty -= 48;
								currentx += 83;
								//currentx -= 83;
								allObjects.addObject(new DetailObject(ntileName, "assets/RegHexHills.png", currentx, currenty, 110, 96));


								if ((i + 1) == completedRad) {
									//std::cout << "added at: " << (currentTile)-5 - (6 * (currentRad -1)) << "at location " << mapTiles.size()-1 << std::endl;
									mapTiles.at(mapTiles.size() - 1).c2 = (currentTile)-5 - (6 * (currentRad - 1));
									mapTiles.at((currentTile)-5 - (6 * (currentRad - 1))).c5 = currentTile;
									mapTiles.at(mapTiles.size() - 1).c5 = currentTile - 1;
									mapTiles.at(mapTiles.size() - 2).c2 = currentTile;

									//std::cout << "This is wht lok for: " << (((currentRad) * 6)+(currentRad*5)) << std::endl;
									mapTiles.at(mapTiles.size() - 1).c4 = currentTile - (((currentRad - 1) * 6) + 6); //you were adding thingy direction for side 4, so yeah, finish that it would bew rather nice if you did that, you already did it for one and the code here is for one, just increase c5 and c4 by one value and the +1 to +2 and the +0 to +1
									mapTiles.at(currentTile - (((currentRad - 1) * 6) + 6)).c1 = currentTile;
									//ading for last tile the wone before shift
									mapTiles.at(mapTiles.size() - 1).c3 = currentTile - (((currentRad - 1) * 6) + 5) - ((currentRad - 1) * 6);
									mapTiles.at(currentTile - (((currentRad - 1) * 6) + 5) - ((currentRad - 1) * 6)).c6 = currentTile;
								}
								else {
									mapTiles.at(mapTiles.size() - 1).c5 = currentTile - 1;
									mapTiles.at(mapTiles.size() - 2).c2 = currentTile;
									mapTiles.at(mapTiles.size() - 1).c4 = currentTile - (((currentRad - 1) * 6) + 6); //you were adding thingy direction for side 4, so yeah, finish that it would bew rather nice if you did that, you already did it for one and the code here is for one, just increase c5 and c4 by one value and the +1 to +2 and the +0 to +1
									mapTiles.at(currentTile - (((currentRad - 1) * 6) + 6)).c1 = currentTile;
									mapTiles.at(mapTiles.size() - 1).c3 = currentTile - (((currentRad - 1) * 6) + 5);
									mapTiles.at(currentTile - (((currentRad - 1) * 6) + 5)).c6 = currentTile;
								}
								currentTile += 1;
							}
							totalTiles += 1;
						}

						if (ss != 2) {
							std::string ntileName = "tile";
							ntileName += std::to_string(currentTile);
							mapTiles.push_back(battleMapTile(-1, -1, -1, -1, -1, -1));
							if (ss == 3) {
								currenty += 48;
								currentx += 83;
								allObjects.addObject(new DetailObject(ntileName, "assets/RegHexHills.png", currentx, currenty, 110, 96));
								mapTiles.at(mapTiles.size() - 1).c6 = currentTile - 1;
								if (completedRad == 0) {
									mapTiles.at(mapTiles.size() - 1).c5 = 0;
									mapTiles.at(0).c2 = currentTile;
								}
								else {
									mapTiles.at(mapTiles.size() - 1).c5 = currentTile - ((completedRad * 6) + 1);
									mapTiles.at(currentTile - ((completedRad * 6) + 1)).c2 = currentTile;
								}

								mapTiles.at(mapTiles.size() - 2).c3 = currentTile;
							}
							if (ss == 4) {
								currenty += 96;
								//currentx += 83;
								allObjects.addObject(new DetailObject(ntileName, "assets/RegHexHills.png", currentx, currenty, 110, 96));
								mapTiles.at(mapTiles.size() - 1).c1 = currentTile - 1;
								if (completedRad == 0) {
									mapTiles.at(mapTiles.size() - 1).c6 = 0;
									mapTiles.at(0).c3 = currentTile;
								}
								else {
									mapTiles.at(mapTiles.size() - 1).c6 = currentTile - ((completedRad * 6) + 2);
									mapTiles.at(currentTile - ((completedRad * 6) + 2)).c3 = currentTile;
								}
								mapTiles.at(mapTiles.size() - 2).c4 = currentTile;
							}
							if (ss == 5) {
								currenty += 48;
								currentx -= 83;
								allObjects.addObject(new DetailObject(ntileName, "assets/RegHexHills.png", currentx, currenty, 110, 96));
								mapTiles.at(mapTiles.size() - 1).c2 = currentTile - 1;
								if (completedRad == 0) {
									mapTiles.at(mapTiles.size() - 1).c1 = 0;
									mapTiles.at(0).c4 = currentTile;
								}
								else {
									mapTiles.at(mapTiles.size() - 1).c1 = currentTile - ((completedRad * 6) + 3);
									mapTiles.at(currentTile - ((completedRad * 6) + 3)).c4 = currentTile;
								}
								mapTiles.at(mapTiles.size() - 2).c5 = currentTile;
							}
							if (ss == 6) {
								currenty -= 48;
								currentx -= 83;
								allObjects.addObject(new DetailObject(ntileName, "assets/RegHexHills.png", currentx, currenty, 110, 96));
								mapTiles.at(mapTiles.size() - 1).c3 = currentTile - 1;
								if (completedRad == 0) {
									mapTiles.at(mapTiles.size() - 1).c2 = 0;
									mapTiles.at(0).c5 = currentTile;
								}
								else {
									mapTiles.at(mapTiles.size() - 1).c2 = currentTile - ((completedRad * 6) + 4);
									mapTiles.at(currentTile - ((completedRad * 6) + 4)).c5 = currentTile;
								}
								mapTiles.at(mapTiles.size() - 2).c6 = currentTile;
							}
							if (ss == 1) {
								currenty -= 96;
								//currentx -= 83;
								allObjects.addObject(new DetailObject(ntileName, "assets/RegHexHills.png", currentx, currenty, 110, 96));
								mapTiles.at(mapTiles.size() - 1).c4 = currentTile - 1;
								if (completedRad == 0) {
									mapTiles.at(mapTiles.size() - 1).c3 = 0;
									mapTiles.at(0).c6 = currentTile;
								}
								else {
									mapTiles.at(mapTiles.size() - 1).c3 = currentTile - ((completedRad * 6) + 5);
									mapTiles.at(currentTile - ((completedRad * 6) + 5)).c6 = currentTile;
								}
								mapTiles.at(mapTiles.size() - 2).c1 = currentTile;
							}
							currentTile += 1;
							ss += 1;
							if (ss == 7) {
								ss = 1;
							}
						}
						if (completedRad == 0 && ss == 2) {
							mapTiles.at(mapTiles.size() - 1).c2 = 1;
							mapTiles.at(1).c5 = 6;
						}

					}
					completedRad += 1;
					currentRad += 1;

				}


				for (int i = 0; i < 18; i++)
				{
					int pick = rand() % mapTiles.size();
					std::string name = "tile" + std::to_string(pick);
					mapTiles.at(pick).isUnpassable = true;
					allObjects.getDetailObject(name)->objTexture = TextureManager::loadTexture("assets/RegHexL.png");
				}
				allObjects.addObject(new DetailObject("dino", "assets/Dinosaur.Original.png", 0, 0, 74, 41, 740, 410));
				allObjects.addObject(new DetailObject("dino2", "assets/Dinosaur.Original.png", 0, 0, 74, 41, 740, 410));
				//allObjects.addObject(new DetailObject("dino3", "assets/Dinosaur.Original.png", 0, 0, 74, 41, 740, 410));
				//allObjects.addObject(new DetailObject("dino4", "assets/Dinosaur.Original.png", 0, 0, 74, 41, 740, 410));
				std::cout << "total tiles: " << mapTiles.size() << "  ";
				creatures.push_back(Creature(&mapTiles, &allObjects, "dino", "dino", player, 91, { PlayerCard("Wander Small", {CardEvent(move,{1,3})},180,"") }));
				creatures.push_back(Creature(&mapTiles, &allObjects, "dino2", 4, {Component(armor,{2}),Component(health,{10}) }));
				//creatures.push_back(Creature(&mapTiles, &allObjects, "dino3", "dino3", player, 74, { PlayerCard("Wander Small", {CardEvent(move,{1,3})},180,"") }));
				//creatures.push_back(Creature(&mapTiles, &allObjects, "dino4", "dino4", player, 22, { PlayerCard("Wander Small", {CardEvent(move,{1,3})},180,"") }));
				allObjects.addObject(new DetailObject("Phil", "assets/Phil.png", 0, 0, 50, 50));
				playerCharacter = Character(&mapTiles, &allObjects, &creatures, "Phil", 0);//40
				//printALLFunc(mapTiles.at(126));
				//std::cout << " " << mapTiles.at(0).c1 << std::endl;
				//std::cout << "Finals: " << mapTiles.size();
				//playerCharacter.updateTurn();
			}
		}
		else {
			if (action == "scrollUp") {
				allObjects.yoff += 2;
			}
			else if (action == "scrollDown") {
				allObjects.yoff -= 2;
			}
			else if (action == "scrollLeft") {
				allObjects.xoff += 2;
			}
			else if (action == "scrollRight") {
				allObjects.xoff -= 2;
			}
			else if (action == "openHand") {
				std::cout << "handopen" << std::endl;
				allObjects.deleteButtonObject("cardButton");
				std::cout << "Handsize: " << playerCharacter.hand.size() <<std::endl;
				for (int i = 0; i < playerCharacter.hand.size(); i++)
				{
					std::string thaName = "card" + std::to_string(i) + "Button";
					allObjects.addObject(new AdvancedButtonObject(thaName, playerCharacter.hand.at(i).cardImage, &playCard, 100+(200*i), 600, 150, 200, i, false));
				}
				//allObjects.addObject(new AdvancedButtonObject("card1Button", playerCharacter.hand.at(0).cardImage, &playCard, 100, 600, 150, 200, 0,false));
				//allObjects.addObject(new AdvancedButtonObject("card1Button", playerCharacter.hand.at(1).cardImage, &playCard, 300, 600, 150, 200, 1,false));
				//allObjects.addObject(new AdvancedButtonObject("card1Button", playerCharacter.hand.at(2).cardImage, &playCard, 500, 600, 150, 200, 2,false));
				//allObjects.addObject(new AdvancedButtonObject("card1Button", playerCharacter.hand.at(3).cardImage, &playCard, 700, 600, 150, 200, 3,false));
				allObjects.addObject(new ButtonObject("cardButton", "assets/cardsIcon.png", &closeHand, 0, 814, 50, 50, false));
				allObjects.getKeyInputObject("cardKey")->command = &closeHand;
				
			}
			else if (action == "closeHand") {
				allObjects.deleteAllAdvancedButtonObject();
				allObjects.deleteButtonObject("cardButton");
				allObjects.addObject(new ButtonObject("cardButton", "assets/cardsIcon.png", &openHand, 0, 814, 50, 50, false));
				//std::cout << "woah";
				allObjects.getKeyInputObject("cardKey")->command = &openHand;
			}
			else if (action == "playCard") {
				if (playerCharacter.pick.size() == 0) {
					std::cout << "playCard" << std::endl;
					allObjects.deleteAllAdvancedButtonObject();
					allObjects.deleteButtonObject("cardButton");
					allObjects.addObject(new ButtonObject("cardButton", "assets/cardsIcon.png", &openHand, 0, 814, 50, 50, false));
					allObjects.changeText("cardsInHand", std::to_string(playerCharacter.deck.size()));
					allObjects.getKeyInputObject("cardKey")->command = &openHand;

					
					for (int counter = 0; counter < playerCharacter.hand.at(eventHandles->at(0).integers.at(0)).cardEvents.size(); counter++) {
						playerCharacter.pick.push_back(playerCharacter.hand.at(eventHandles->at(0).integers.at(0)).cardEvents.at(counter).action);
						if (playerCharacter.hand.at(eventHandles->at(0).integers.at(0)).cardEvents.at(counter).action == attack) {
							CardEvent thisCardEvent = playerCharacter.hand.at(eventHandles->at(0).integers.at(0)).cardEvents.at(counter);
							Attack createdAttack = Attack(thisCardEvent.data.at(0), thisCardEvent.data.at(1));
							playerCharacter.attackQueue.push_back(createdAttack);
						}
						if (playerCharacter.hand.at(eventHandles->at(0).integers.at(0)).cardEvents.at(counter).action == move) {
							CardEvent thisCardEvent = playerCharacter.hand.at(eventHandles->at(0).integers.at(0)).cardEvents.at(counter);
							Move createdMove = Move(thisCardEvent.data.at(0), thisCardEvent.data.at(1));
							playerCharacter.moveQueue.push_back(createdMove);
						}
					}
					playerCharacter.discard.push_back(playerCharacter.hand.at(eventHandles->at(0).integers.at(0)));
					playerCharacter.hand.erase(playerCharacter.hand.begin() + eventHandles->at(0).integers.at(0));
				}
				

			}
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
	for (int i = creatures.size()-1; i > -1; i--)
	{
		//std::cout << "ran";
		if (creatures.at(i).killed == true) {
			allObjects.deleteDetailObject(creatures.at(i).linkID);
			creatures.erase(creatures.begin() + i);
		}
		else {
			creatures.at(i).runTurn();
		}


		
	}
	if (!paused) {
		playerCharacter.updateTurn();
	}
	





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