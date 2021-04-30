#include "Creature.h"
Path::Path(std::vector<int> w, int p) {
	weave = w;
	from = p;
}
Creature::Creature(std::vector<battleMapTile>* map,ObjectDataBase* dataBase, std::string named, std::string linkedid, entityFaction fact, int tile, std::vector<PlayerCard> cards) {
	maxHealthPoints = 5;
	currentHealthPoints = 5;
	faction = monster;
	coolDown = 100;
	cardsUsed = { };
	currentTile = 0;
	moveDest = -1;
	mapTiles = map;
	moving = false;
	pathWeave = { };
	allObjects = dataBase;
	std::string objectTag = "tile" + std::to_string(tile);
	std::cout << objectTag << " ";
	goalx = allObjects->getDetailObject(objectTag)->xPos;
	goaly = allObjects->getDetailObject(objectTag)->yPos;
	allObjects->getDetailObject(linkedid)->xPos = goalx;
	allObjects->getDetailObject(linkedid)->yPos = goaly;
	goalSet = false;
	name = named;
	linkID = linkedid;
	currentTile = tile;
	faction = fact;
	cardsReady = cards;

}
void Creature::runTurn() {
	//std::cout << "remaining actions: " << cardsReady.size();
	if (moving) {

		if (goalSet == false) {
			
			if (pathWeave.size() == 0) {
				//std::cout << "Destintation: " << moveDest << "   ";
				path();
			}
			
				if (mapTiles->at(currentTile).c1 == pathWeave.at(0)) {
					goaly -= 96;
				} 
				else if (mapTiles->at(currentTile).c2 == pathWeave.at(0)) {
					goaly -= 48;
					goalx += 83;
				}
				else if (mapTiles->at(currentTile).c3 == pathWeave.at(0)) {
					goaly += 48;
					goalx += 83;
				}
				else if (mapTiles->at(currentTile).c4 == pathWeave.at(0)) {
					goaly += 96;
				}
				else if (mapTiles->at(currentTile).c5 == pathWeave.at(0)) {
					goaly += 48;
					goalx -= 83;
				}
				else if (mapTiles->at(currentTile).c6 == pathWeave.at(0)) {
					goaly -= 48;
					goalx -= 83;
				}
			goalSet = true;
		}
		else {
			bool reached = true;
			//std::cout << "Goalx: " << goalx << "Goaly: " << goaly;
			if (allObjects->getDetailObject(linkID)->yPos < goaly) {
				allObjects->getDetailObject(linkID)->moveObject(0, 1);
				reached = false;
			} 
			else if (allObjects->getDetailObject(linkID)->yPos > goaly) {
				allObjects->getDetailObject(linkID)->moveObject(0, -1);
				reached = false;
			}
			if (allObjects->getDetailObject(linkID)->xPos < goalx) {
				allObjects->getDetailObject(linkID)->moveObject(1, 0);
				reached = false;
			}
			else if (allObjects->getDetailObject(linkID)->xPos > goalx) {
				allObjects->getDetailObject(linkID)->moveObject(-1, 0);
				reached = false;
			}

			if (reached) {
				mapTiles->at(currentTile).isUnpassable = false;
				currentTile = pathWeave.at(0);
				mapTiles->at(currentTile).isUnpassable = true;
				pathWeave.erase(pathWeave.begin() + 0);
				goalSet = false;
				if (pathWeave.size() == 0) {
					moving = false;
				}
				//std::cout << "New current tile: " << currentTile;
			}
		}
		
	} 
	else if (coolDown == 0) {
		if ((cardsReady.size() > 0) && mapTiles->size() > 0) {
			PlayerCard activeCard = cardsReady.at(0);
			cardsUsed.push_back(cardsReady.at(0));
			cardsReady.erase(cardsReady.begin() + 0);
			coolDown = activeCard.coolDown;
			for (int i = 0; i < activeCard.cardEvents.size(); i++)
			{
				if (activeCard.cardEvents.at(i).action == move) {
					if (activeCard.cardEvents.at(i).data.at(0) == 0) {
						int thisTile = currentTile;
						std::vector<int> targets = { };
						
						for (int i = 0; i < activeCard.cardEvents.at(i).data.at(1); i++)
						{
							thisTile = mapTiles->at(thisTile).c1;
							if (mapTiles->at(thisTile).isUnpassable == true) {
								targets.push_back(0); // add a new variable to tiles that stores who/what is in the tile at a given moment.
							}
						}
						
						moving = true;
						coolDown = 600;
					}
					else if (activeCard.cardEvents.at(i).data.at(0) == 1) {
						int currentloc = currentTile;
						int randDirection = rand() % 6;
						for (int k = 0; k < activeCard.cardEvents.at(i).data.at(1); k++)
						{
							//std::cout << "    Current loc at loop start: " << currentloc << "   ";
							
							if (randDirection == 0) {
								if (mapTiles->at(currentloc).c1 == -1 || mapTiles->at(mapTiles->at(currentloc).c1).isUnpassable == true) {
									k--;
									moveDest = currentloc;
								}
								else {
									moveDest = mapTiles->at(currentloc).c1;
									
								}
							}
							else if (randDirection == 1) {
								if (mapTiles->at(currentloc).c2 == -1 || mapTiles->at(mapTiles->at(currentloc).c2).isUnpassable == true) {
									k--;
									moveDest = currentloc;
								}
								else {
									moveDest = mapTiles->at(currentloc).c2;
									
								}
								
							}
							else if (randDirection == 2) {
								if (mapTiles->at(currentloc).c3 == -1 || mapTiles->at(mapTiles->at(currentloc).c3).isUnpassable == true) {
									k--;
									moveDest = currentloc;
								}
								else {
									moveDest = mapTiles->at(currentloc).c3;
									
								}
								
							}
							else if (randDirection == 3) {
								if (mapTiles->at(currentloc).c4 == -1 || mapTiles->at(mapTiles->at(currentloc).c4).isUnpassable == true) {
									k--;
									moveDest = currentloc;
								}
								else {
									moveDest = mapTiles->at(currentloc).c4;
								
								}
								
							}
							else if (randDirection == 4) {
								if (mapTiles->at(currentloc).c5 == -1 || mapTiles->at(mapTiles->at(currentloc).c5).isUnpassable == true) {
									k--;
									moveDest = currentloc;
								}
								else {
									moveDest = mapTiles->at(currentloc).c5;
								
								}
								
							}
							else if (randDirection == 5) {
								if (mapTiles->at(currentloc).c6 == -1 || mapTiles->at(mapTiles->at(currentloc).c6).isUnpassable == true) {
									k--;
									moveDest = currentloc;
								}
								else {
									moveDest = mapTiles->at(currentloc).c6;
									
								}
								
							}
							//std::cout << "    Move destination is currently set to: " << moveDest << "     ";
							currentloc = moveDest;
							if (rand() % 5 == 0) {
								randDirection = rand() % 6;
							}
							
						}
						//std::cout << "   Selecting Destination of: " << moveDest << "  ";
						if (currentTile != moveDest) {
							moving = true;
						}

					}
				}
			}
		}
	}
	else {
	if (cardsReady.size() < 1) {
		int size = cardsUsed.size();
		for (int i = 0; i < size; i++)
		{
			int loc = (rand() % cardsUsed.size());
			cardsReady.push_back(cardsUsed.at(loc));
			cardsUsed.erase(cardsUsed.begin() + loc);
		}
	}
		coolDown -= 1;
	}
}
void Creature::path() {
	//go ahead and make these work starting from any location
	std::vector<Path> paths = { Path({mapTiles->at(currentTile).c1},4),Path({mapTiles->at(currentTile).c2},5),Path({mapTiles->at(currentTile).c3},6),Path({mapTiles->at(currentTile).c4},1),Path({mapTiles->at(currentTile).c5},2),Path({mapTiles->at(currentTile).c6},3) };
	if (mapTiles->at(currentTile).c6 == -1 || mapTiles->at(mapTiles->at(currentTile).c6).isUnpassable) {
		paths.erase(paths.begin() + 5);
	}
	if (mapTiles->at(currentTile).c5 == -1 || mapTiles->at(mapTiles->at(currentTile).c5).isUnpassable) {
		paths.erase(paths.begin() + 4);
	}
	if (mapTiles->at(currentTile).c4 == -1 || mapTiles->at(mapTiles->at(currentTile).c4).isUnpassable) {
		paths.erase(paths.begin() + 3);
	}
	if (mapTiles->at(currentTile).c3 == -1 || mapTiles->at(mapTiles->at(currentTile).c3).isUnpassable) {
		paths.erase(paths.begin() + 2);
	}
	if (mapTiles->at(currentTile).c2 == -1 || mapTiles->at(mapTiles->at(currentTile).c2).isUnpassable) {
		paths.erase(paths.begin() + 1);
	}
	if (mapTiles->at(currentTile).c1 == -1 || mapTiles->at(mapTiles->at(currentTile).c1).isUnpassable) {
		paths.erase(paths.begin() + 0);
	}
	std::cout << "    Paths in list: " << paths.size() << "      ";
	//std::vector<int> currentShortest = { };
	bool going = true;
	int currentLeng = 1;
	while (going) {
		int pathSize = paths.size();
		for (int i = 0; i < pathSize; i++)
		{
			if (paths.at(i).weave.at(paths.at(i).weave.size() - 1) == moveDest) {
				going = false;
				going = false;
				pathWeave = paths.at(i).weave;
				break;
			}
			else {
				if (paths.at(i).from == 4) {
					if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c6)) != -1) && mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c6)).isUnpassable == false) {
						paths.push_back(paths.at(i));
						paths.at(paths.size() - 1).from = 3;
						paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c6);
					}
					
					if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c2)) != -1) && mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c2)).isUnpassable == false) {
						paths.push_back(paths.at(i));
						paths.at(paths.size() - 1).from = 5;
						paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c2);
					}
					
					if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c1)) != -1) && mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c1)).isUnpassable == false) {
						paths.at(i).from = 4;
						paths.at(i).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c1);
					}
					
				} 
				else if (paths.at(i).from == 5) {
					if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c1)) != -1) && mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c1)).isUnpassable == false) {
						paths.push_back(paths.at(i));
						paths.at(paths.size() - 1).from = 4;
						paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c1);
					}
					if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c3)) != -1) && mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c3)).isUnpassable == false) {
						paths.push_back(paths.at(i));
						paths.at(paths.size() - 1).from = 6;
						paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c3);
					}
					if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c2)) != -1) && mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c2)).isUnpassable == false) {
						paths.at(i).from = 5;
						paths.at(i).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c2);
					}
				}
				else if (paths.at(i).from == 6) {
					if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c2)) != -1) && mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c2)).isUnpassable == false) {
						paths.push_back(paths.at(i));
						paths.at(paths.size() - 1).from = 5;
						paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c2);
					}
					if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c4)) != -1) && mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c4)).isUnpassable == false) {
						paths.push_back(paths.at(i));
						paths.at(paths.size() - 1).from = 1;
						paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c4);
					}
					if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c3)) != -1) && mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c3)).isUnpassable == false) {
						paths.at(i).from = 6;
						paths.at(i).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c3);
					}
				}
				else if (paths.at(i).from == 1) {
					if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c3)) != -1) && mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c3)).isUnpassable == false) {
						paths.push_back(paths.at(i));
						paths.at(paths.size() - 1).from = 6;
						paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c3);
					}
					if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c5)) != -1) && mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c5)).isUnpassable == false) {
						paths.push_back(paths.at(i));
						paths.at(paths.size() - 1).from = 2;
						paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c5);
					}
					if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c4)) != -1) && mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c4)).isUnpassable == false) {
						paths.at(i).from = 1;
						paths.at(i).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c4);
					}
				}
				else if (paths.at(i).from == 2) {
					if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c4)) != -1) && mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c4)).isUnpassable == false) {
						paths.push_back(paths.at(i));
						paths.at(paths.size() - 1).from = 1;
						paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c4);
					}
					if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c6)) != -1) && mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c6)).isUnpassable == false) {

						paths.push_back(paths.at(i));
						paths.at(paths.size() - 1).from = 3;
						paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c6);
					}
					if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c5)) != -1) && mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c5)).isUnpassable == false) {
						paths.at(i).from = 2;
						paths.at(i).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c5);
					}
				}
				else if (paths.at(i).from == 3) {
					if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c5)) != -1) && mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c5)).isUnpassable == false) {
						paths.push_back(paths.at(i));
						paths.at(paths.size() - 1).from = 2;
						paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c5);
					}
					if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c1)) != -1) && mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c1)).isUnpassable == false) {
						paths.push_back(paths.at(i));
						paths.at(paths.size() - 1).from = 4;
						paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c1);
					}
					if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c6)) != -1) && mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c6)).isUnpassable == false) {
						paths.at(i).from = 3;
						paths.at(i).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c6);
					}
				}
			}
		}
	}
	for (int i = 0; i < pathWeave.size(); i++)
	{
		std::cout << pathWeave.at(i) << "  ";
	}
}



