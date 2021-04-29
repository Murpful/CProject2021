#include "Creature.h"
Path::Path(std::vector<int> w, int p) {
	weave = w;
	from = p;
}
Creature::Creature(std::vector<battleMapTile>* map,ObjectDataBase* dataBase) {
	maxHealthPoints = 5;
	currentHealthPoints = 5;
	faction = monster;
	coolDown = 100;
	cardsReady = { PlayerCard("wander",{CardEvent(move,{0,5})}," ") };
	cardsUsed = { };
	currentTile = 0;
	moveDest = -1;
	mapTiles = map;
	moving = false;
	pathWeave = { };
	allObjects = dataBase;
	linkID = "dino";
	goalx = 700;
	goaly = 350;
	goalSet = false;

}
void Creature::runTurn() {
	
	if (moving) {

		if (goalSet == false) {
			
			if (pathWeave.size() == 0) {
				std::cout << "Destintation: " << moveDest << "   ";
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
			if (allObjects->getDetailObject("dino")->yPos < goaly) {
				allObjects->getDetailObject("dino")->moveObject(0, 1);
				reached = false;
			} 
			else if (allObjects->getDetailObject("dino")->yPos > goaly) {
				allObjects->getDetailObject("dino")->moveObject(0, -1);
				reached = false;
			}
			if (allObjects->getDetailObject("dino")->xPos < goalx) {
				allObjects->getDetailObject("dino")->moveObject(1, 0);
				reached = false;
			}
			else if (allObjects->getDetailObject("dino")->xPos > goalx) {
				allObjects->getDetailObject("dino")->moveObject(-1, 0);
				reached = false;
			}

			if (reached) {
				currentTile = pathWeave.at(0);
				pathWeave.erase(pathWeave.begin() + 0);
				goalSet = false;
				if (pathWeave.size() == 0) {
					moving = false;
				}
			}
		}
		
	} 
	else if (coolDown == 0) {
		if ((cardsReady.size() > 0) && mapTiles->size() > 0) {
			PlayerCard activeCard = cardsReady.at(0);
			cardsReady.erase(cardsReady.begin() + 0);
			for (int i = 0; i < activeCard.cardEvents.size(); i++)
			{
				if (activeCard.cardEvents.at(i).action == move) {
					if (activeCard.cardEvents.at(i).data.at(0) == 0) {
						int randDirection = rand() % 6;
						int currentloc = currentTile;
						for (int k = 0; k < activeCard.cardEvents.at(i).data.at(1); k++)
						{
							if (randDirection == 0) {
								if (mapTiles->at(currentloc).c1 == -1) {
									break;
								}
								moveDest = mapTiles->at(currentloc).c1;
								
							}
							else if (randDirection == 1) {
								if (mapTiles->at(currentloc).c2 == -1) {
									break;
								}
								moveDest = mapTiles->at(currentloc).c2;
							}
							else if (randDirection == 2) {
								if (mapTiles->at(currentloc).c3 == -1) {
									break;
								}
								moveDest = mapTiles->at(currentloc).c3;
							}
							else if (randDirection == 3) {
								if (mapTiles->at(currentloc).c4 == -1) {
									break;
								}
								moveDest = mapTiles->at(currentloc).c4;
							}
							else if (randDirection == 4) {
								if (mapTiles->at(currentloc).c5 == -1) {
									break;
								}
								moveDest = mapTiles->at(currentloc).c5;
							}
							else if (randDirection == 5) {
								if (mapTiles->at(currentloc).c6 == -1) {
									break;
								}
								moveDest = mapTiles->at(currentloc).c6;
							}
							currentloc = moveDest;
							moveDest = rand()%mapTiles->size();
						}
						
						moving = true;
					}
				}
			}
		}
	}
	else {
		coolDown -= 1;
	}
}
void Creature::path() {
	std::vector<Path> paths = { Path({1},4),Path({2},5),Path({3},6),Path({4},1),Path({5},2),Path({6},3) };
	if (mapTiles->at(6).isUnpassable) {
		paths.erase(paths.begin() + 5);
	}
	if (mapTiles->at(5).isUnpassable) {
		paths.erase(paths.begin() + 4);
	}
	if (mapTiles->at(4).isUnpassable) {
		paths.erase(paths.begin() + 3);
	}
	if (mapTiles->at(3).isUnpassable) {
		paths.erase(paths.begin() + 2);
	}
	if (mapTiles->at(2).isUnpassable) {
		paths.erase(paths.begin() + 1);
	}
	if (mapTiles->at(1).isUnpassable) {
		paths.erase(paths.begin() + 0);
	}
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



