#include "Character.h"
//#include<iostream>
int selectedTile = -1;
void selectTile(int inf) {
	selectedTile = inf;
	std::cout << "info: " << inf << "    ";
}


void Character::playCard() {
	for (int i = 0; i < selectedCard.cardEvents.size(); i++)
	{
		if (selectedCard.cardEvents.at(i).action == attack) {
			attackQueue.push_back(Attack(selectedCard.cardEvents.at(i).data.at(0), selectedCard.cardEvents.at(i).data.at(1)));
		}
		if (selectedCard.cardEvents.at(i).action == move) {
			moveQueue.push_back(Move(selectedCard.cardEvents.at(i).data.at(0), selectedCard.cardEvents.at(i).data.at(1)));
		}
		
	}
	
}

bool doesContain(std::vector<int> list, int val) {

	bool retu = false;
	for (int i = 0; i < list.size(); i++)
	{
		if (list.at(i) == val) {
			retu = true;
			//std::cout << "peat";
		}
	}
	return retu;
}
void Character::updateTurn() {
	static int attackTimeCounter = 0;
	//std::cout << targetLoc;
	targetLoc = selectedTile;
	if (attackQueue.size() > 0 && !isAttacking && !isMoving) {
		isAttacking = true;
		attackTimeCounter = 300;
		std::vector<Path> paths = { Path({mapTiles->at(loc).c1},4),Path({mapTiles->at(loc).c2},5),Path({mapTiles->at(loc).c3},6),Path({mapTiles->at(loc).c4},1),Path({mapTiles->at(loc).c5},2),Path({mapTiles->at(loc).c6},3) };
		if (mapTiles->at(loc).c6 == -1 || mapTiles->at(mapTiles->at(loc).c6).isUnpassable) {
			paths.erase(paths.begin() + 5);
			int marked = mapTiles->at(mapTiles->at(loc).c6).c5;
			for (int l = 0; l < attackQueue.at(0).range; l++)
			{
				if (marked != -1) {
					mapTiles->at(marked).isShadowed = true;
					marked = mapTiles->at(marked).c5;
				}
			}
			marked = mapTiles->at(mapTiles->at(loc).c6).c1;
			for (int l = 0; l < attackQueue.at(0).range; l++)
			{
				if (marked != -1) {
					mapTiles->at(marked).isShadowed = true;
					marked = mapTiles->at(marked).c1;
				}
			}
		}
		if (mapTiles->at(loc).c5 == -1 || mapTiles->at(mapTiles->at(loc).c5).isUnpassable) {
			paths.erase(paths.begin() + 4);
			int marked = mapTiles->at(mapTiles->at(loc).c5).c6;
			for (int l = 0; l < attackQueue.at(0).range; l++)
			{
				if (marked != -1) {
					mapTiles->at(marked).isShadowed = true;
					marked = mapTiles->at(marked).c6;
				}
			}
			marked = mapTiles->at(mapTiles->at(loc).c5).c4;
			for (int l = 0; l < attackQueue.at(0).range; l++)
			{
				if (marked != -1) {
					mapTiles->at(marked).isShadowed = true;
					marked = mapTiles->at(marked).c4;
				}
			}
		}
		if (mapTiles->at(loc).c4 == -1 || mapTiles->at(mapTiles->at(loc).c4).isUnpassable) {
			paths.erase(paths.begin() + 3);
			int marked = mapTiles->at(mapTiles->at(loc).c4).c5;
			for (int l = 0; l < attackQueue.at(0).range; l++)
			{
				if (marked != -1) {
					mapTiles->at(marked).isShadowed = true;
					marked = mapTiles->at(marked).c5;
				}
			}
			marked = mapTiles->at(mapTiles->at(loc).c4).c3;
			for (int l = 0; l < attackQueue.at(0).range; l++)
			{
				if (marked != -1) {
					mapTiles->at(marked).isShadowed = true;
					marked = mapTiles->at(marked).c3;
				}
			}

		}
		if (mapTiles->at(loc).c3 == -1 || mapTiles->at(mapTiles->at(loc).c3).isUnpassable) {
			paths.erase(paths.begin() + 2);
			int marked = mapTiles->at(mapTiles->at(loc).c3).c4;
			for (int l = 0; l < attackQueue.at(0).range; l++)
			{
				if (marked != -1) {
					mapTiles->at(marked).isShadowed = true;
					marked = mapTiles->at(marked).c4;
				}
			}
			marked = mapTiles->at(mapTiles->at(loc).c3).c2;
			for (int l = 0; l < attackQueue.at(0).range; l++)
			{
				if (marked != -1) {
					mapTiles->at(marked).isShadowed = true;
					marked = mapTiles->at(marked).c2;
				}
			}
		}
		if (mapTiles->at(loc).c2 == -1 || mapTiles->at(mapTiles->at(loc).c2).isUnpassable) {
			paths.erase(paths.begin() + 1);
			int marked = mapTiles->at(mapTiles->at(loc).c2).c1;
			for (int l = 0; l < attackQueue.at(0).range; l++)
			{
				if (marked != -1) {
					mapTiles->at(marked).isShadowed = true;
					marked = mapTiles->at(marked).c1;
				}
			}
			marked = mapTiles->at(mapTiles->at(loc).c2).c3;
			for (int l = 0; l < attackQueue.at(0).range; l++)
			{
				if (marked != -1) {
					mapTiles->at(marked).isShadowed = true;
					marked = mapTiles->at(marked).c3;
				}
			}
		}
		if (mapTiles->at(loc).c1 == -1 || mapTiles->at(mapTiles->at(loc).c1).isUnpassable) {
			paths.erase(paths.begin() + 0);
			int marked = mapTiles->at(mapTiles->at(loc).c1).c6;
			for (int l = 0; l < attackQueue.at(0).range; l++)
			{
				if (marked != -1) {
					mapTiles->at(marked).isShadowed = true;
					marked = mapTiles->at(marked).c6;
				}
			}
			marked = mapTiles->at(mapTiles->at(loc).c1).c2;
			for (int l = 0; l < attackQueue.at(0).range; l++)
			{
				if (marked != -1) {
					mapTiles->at(marked).isShadowed = true;
					marked = mapTiles->at(marked).c2;
				}
			}
		}
		//std::cout << "    Paths in list: " << paths.size() << "      ";
		//std::vector<int> currentShortest = { };
		bool going = true;
		int currentLeng = 1;
		for (int f = 0; f < attackQueue.at(0).range; f++)
		{
			int pathSize = paths.size();
			for (int i = 0; i < pathSize; i++)
			{
					if (paths.at(i).from == 4) {
						if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c1)) != -1) && mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c1)).isUnpassable == false && mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c1)).isShadowed == false) {
							paths.push_back(paths.at(i));
							paths.at(paths.size() - 1).from = 4;
							paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c1);
						}
						/*
						else if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c1)) != -1) && mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c1)).isUnpassable == true) {
							int marked = mapTiles->at(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c1).c6;
							for (int l = 0; l < attackQueue.at(0).range; l++)
							{
								if (marked != -1) {
									mapTiles->at(marked).isShadowed = true;
									marked = mapTiles->at(marked).c6;
								}
							}
							marked = mapTiles->at(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c1).c2;
							for (int l = 0; l < attackQueue.at(0).range; l++)
							{
								if (marked != -1) {
									mapTiles->at(marked).isShadowed = true;
									marked = mapTiles->at(marked).c2;
								}
							}
						}*/
						if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c6)) != -1) && mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c6)).isUnpassable == false && mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c6)).isShadowed == false) {
							paths.push_back(paths.at(i));
							paths.at(paths.size() - 1).from = 3;
							paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c6);
						}

						if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c2)) != -1) && mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c2)).isUnpassable == false && mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c2)).isShadowed == false) {
							paths.push_back(paths.at(i));
							paths.at(paths.size() - 1).from = 5;
							paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c2);
						}

					

					}
					else if (paths.at(i).from == 5) {
						if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c1)) != -1) && mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c1)).isUnpassable == false && mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c1)).isShadowed == false) {
							paths.push_back(paths.at(i));
							paths.at(paths.size() - 1).from = 4;
							paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c1);
						}
						if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c3)) != -1) && mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c3)).isUnpassable == false && mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c3)).isShadowed == false) {
							paths.push_back(paths.at(i));
							paths.at(paths.size() - 1).from = 6;
							paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c3);
						}
						if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c2)) != -1) && mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c2)).isUnpassable == false && mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c2)).isShadowed == false) {
							paths.push_back(paths.at(i));
							paths.at(paths.size() - 1).from = 5;
							paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c2);
						}
					}
					else if (paths.at(i).from == 6) {
						if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c2)) != -1) && mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c2)).isUnpassable == false && mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c2)).isShadowed == false) {
							paths.push_back(paths.at(i));
							paths.at(paths.size() - 1).from = 5;
							paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c2);
						}
						if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c4)) != -1) && mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c4)).isUnpassable == false && mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c4)).isShadowed == false) {
							paths.push_back(paths.at(i));
							paths.at(paths.size() - 1).from = 1;
							paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c4);
						}
						if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c3)) != -1) && mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c3)).isUnpassable == false && mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c3)).isShadowed == false) {
							paths.push_back(paths.at(i));
							paths.at(paths.size() - 1).from = 6;
							paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c3);
						}
					}
					else if (paths.at(i).from == 1) {
						if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c3)) != -1) && mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c3)).isUnpassable == false && mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c3)).isShadowed == false) {
							paths.push_back(paths.at(i));
							paths.at(paths.size() - 1).from = 6;
							paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c3);
						}
						if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c5)) != -1) && mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c5)).isUnpassable == false && mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c5)).isShadowed == false) {
							paths.push_back(paths.at(i));
							paths.at(paths.size() - 1).from = 2;
							paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c5);
						}
						if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c4)) != -1) && mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c4)).isUnpassable == false && mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c4)).isShadowed == false) {
							paths.push_back(paths.at(i));
							paths.at(paths.size() - 1).from = 1;
							paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c4);
						}
					}
					else if (paths.at(i).from == 2) {
						if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c4)) != -1) && mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c4)).isUnpassable == false && mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c4)).isShadowed == false) {
							paths.push_back(paths.at(i));
							paths.at(paths.size() - 1).from = 1;
							paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c4);
						}
						if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c6)) != -1) && mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c6)).isUnpassable == false && mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c6)).isShadowed == false) {

							paths.push_back(paths.at(i));
							paths.at(paths.size() - 1).from = 3;
							paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c6);
						}
						if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c5)) != -1) && mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c5)).isUnpassable == false && mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c5)).isShadowed == false) {
							paths.push_back(paths.at(i));
							paths.at(paths.size() - 1).from = 2;
							paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c5);
						}
					}
					else if (paths.at(i).from == 3) {
					if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c6)) != -1) && mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c6)).isUnpassable == false && mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c6)).isShadowed == false) {
						paths.push_back(paths.at(i));
						paths.at(paths.size() - 1).from = 3;
						paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c6);
					}
					/*else if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c6)) != -1) && mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c6)).isUnpassable == true) {
						int marked = mapTiles->at(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c6).c1;
						for (int l = 0; l < attackQueue.at(0).range; l++)
						{
							if (marked != -1) {
								mapTiles->at(marked).isShadowed = true;
								marked = mapTiles->at(marked).c1;
							}
						}
						marked = mapTiles->at(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c6).c5;
						for (int l = 0; l < attackQueue.at(0).range; l++)
						{
							if (marked != -1) {
								mapTiles->at(marked).isShadowed = true;
								marked = mapTiles->at(marked).c5;
							}
						}
					}
					*/
						if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c5)) != -1) && mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c5)).isUnpassable == false && mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c5)).isShadowed == false) {
							paths.push_back(paths.at(i));
							paths.at(paths.size() - 1).from = 2;

							paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c5);
						}
						if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c1)) != -1) && mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c1)).isUnpassable == false && mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c1)).isShadowed == false) {
							paths.push_back(paths.at(i));
							paths.at(paths.size() - 1).from = 4;
							paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c1);
						}
						
				}
			}
		}
		
		std::vector<int> finalTiles = { };
		for (int i = 0; i < paths.size(); i++)
		{
			int it = paths.at(i).weave.at(paths.at(i).weave.size() - 1);
			if (!(doesContain(finalTiles, it)) && it != loc) {
				finalTiles.push_back(it);
			}
			
		}
		for (int i = 0; i < finalTiles.size(); i++)
		{
			int it = finalTiles.at(i);
			std::string name = "tile" + std::to_string(it);
			//std::cout << "  asdf        " << name << "      "  ;
			allObjects->addObject(new AdvancedButtonObject("targetButton", "assets/RegHexBaseTarget5.png",&selectTile, allObjects->getDetailObject(name)->xPos, allObjects->getDetailObject(name)->yPos, 110, 96, it));
		}














		
		//startingTileOfCreation = mapTiles->at(loc).c1;
		/*
		int currentSide = 0;
		if (mapTiles->at(loc).c1 != -1) {
			startingTileOfCreation = mapTiles->at(loc).c1;
			
		}
		else {
			int revertedLocation = loc;
				if (mapTiles->at(loc).c2 != -1) {
					startingTileOfCreation = mapTiles->at(loc).c2;
					currentSide += 1;
				}
				else if (mapTiles->at(loc).c3 != -1) {
					startingTileOfCreation = mapTiles->at(loc).c3;
					currentSide += 2;
					
				}
				else {
					startingTileOfCreation = mapTiles->at(loc).c4;
					currentSide += 3;
				}
		}
		int distReduct = 0;
		for (int i = 0; i < attackQueue.at(0).range; i++)
		{
			std::string firstTileLink = "tile" + std::to_string(startingTileOfCreation);
			allObjects->addObject(new AdvancedButtonObject("targetButton", "assets/RegHexBaseTarget.png",&selectTile, allObjects->getDetailObject(firstTileLink)->xPos, allObjects->getDetailObject(firstTileLink)->yPos, 110, 96, startingTileOfCreation));
			for (int k = 0; k < i+1; k++)
			{
				if (currentSide == 0) {
					
					
					startingTileOfCreation = mapTiles->at(startingTileOfCreation).c3;
					//std::cout << "Creating tile at: " << startingTileOfCreation << "    ";
					firstTileLink = "tile" + std::to_string(startingTileOfCreation);
					
					if (k== i) {
						currentSide += 1;
					}
					
					allObjects->addObject(new AdvancedButtonObject("targetButton", "assets/RegHexBaseTarget.png", &selectTile, allObjects->getDetailObject(firstTileLink)->xPos, allObjects->getDetailObject(firstTileLink)->yPos, 110, 96, startingTileOfCreation));
				}
				
			}
			for (int k = 0; k < i + 1 - distReduct; k++)
			{
				if (currentSide == 1) {
					
					startingTileOfCreation = mapTiles->at(startingTileOfCreation).c4;
					firstTileLink = "tile" + std::to_string(startingTileOfCreation);
					if (k == i - distReduct) {
						currentSide += 1;
					}
					allObjects->addObject(new AdvancedButtonObject("targetButton", "assets/RegHexBaseTarget.png", &selectTile, allObjects->getDetailObject(firstTileLink)->xPos, allObjects->getDetailObject(firstTileLink)->yPos, 110, 96, startingTileOfCreation));
				}
				
			}
			for (int k = 0; k < i + 1; k++)
			{
				if (currentSide == 2) {
					startingTileOfCreation = mapTiles->at(startingTileOfCreation).c5;
					firstTileLink = "tile" + std::to_string(startingTileOfCreation);
					if (k == i) {
						currentSide += 1;
					}
					allObjects->addObject(new AdvancedButtonObject("targetButton", "assets/RegHexBaseTarget.png", &selectTile, allObjects->getDetailObject(firstTileLink)->xPos, allObjects->getDetailObject(firstTileLink)->yPos, 110, 96, startingTileOfCreation));
				}
				
			}
			for (int k = 0; k < i + 1; k++)
			{
				if (currentSide == 3) {
					if (k == i) {
						currentSide += 1;
					}
					startingTileOfCreation = mapTiles->at(startingTileOfCreation).c6;
					firstTileLink = "tile" + std::to_string(startingTileOfCreation);
					allObjects->addObject(new AdvancedButtonObject("targetButton", "assets/RegHexBaseTarget.png", &selectTile, allObjects->getDetailObject(firstTileLink)->xPos, allObjects->getDetailObject(firstTileLink)->yPos, 110, 96, startingTileOfCreation));
				}
			}
			for (int k = 0; k < i + 1; k++)
			{
				if (currentSide == 4) {
					if (k == i) {
						currentSide += 1;
					}
					startingTileOfCreation = mapTiles->at(startingTileOfCreation).c1;
					firstTileLink = "tile" + std::to_string(startingTileOfCreation);
					allObjects->addObject(new AdvancedButtonObject("targetButton", "assets/RegHexBaseTarget.png", &selectTile, allObjects->getDetailObject(firstTileLink)->xPos, allObjects->getDetailObject(firstTileLink)->yPos, 110, 96, startingTileOfCreation));
				}
			}
			for (int k = 0; k < i; k++)
			{
				if (currentSide == 5) {
					
					//std::cout << "side 5 starter: " << startingTileOfCreation << "    ";
					if (mapTiles->at(startingTileOfCreation).c2 != -1) {
						startingTileOfCreation = mapTiles->at(startingTileOfCreation).c2;
						firstTileLink = "tile" + std::to_string(startingTileOfCreation);
						allObjects->addObject(new AdvancedButtonObject("targetButton", "assets/RegHexBaseTarget.png", &selectTile, allObjects->getDetailObject(firstTileLink)->xPos, allObjects->getDetailObject(firstTileLink)->yPos, 110, 96, startingTileOfCreation));
					}
					else {
						std::cout << "ASDFASDFASDF";
						currentSide = -1;
					}
					
				}
			}

			
			if (attackQueue.at(0).range > i + 1 ) {
				//startingTileOfCreation = mapTiles->at(startingTileOfCreation).c2;
				//startingTileOfCreation = mapTiles->at(startingTileOfCreation).c1;
				//currentSide = 0;
				if (currentSide != -1) {
					currentSide = 0;
					if (mapTiles->at(startingTileOfCreation).c2 != -1) {
						startingTileOfCreation = mapTiles->at(startingTileOfCreation).c2;
						if (mapTiles->at(startingTileOfCreation).c1 != -1) {

							startingTileOfCreation = mapTiles->at(startingTileOfCreation).c1;

						}
						else {
							for (int s = 0; s < i + 2; s++)
							{
								distReduct = i;
								startingTileOfCreation = mapTiles->at(startingTileOfCreation).c3;
								//std::cout << "yeah this was used so not go well for matt";
								currentSide = 1;
								//std::cout << "New starting location: " << startingTileOfCreation << "   ";
							}
						}

					}
					else {
						startingTileOfCreation = loc;
						startingTileOfCreation += (i + (2*(i+1)));
						//std::cout << "New starting location: " << startingTileOfCreation << "   ";
					}
					std::cout << "New starting location: " << startingTileOfCreation << "   ";
				}
				else {
					startingTileOfCreation = 100;
					currentSide = 0;
				}
				
			
			
			}
		}
		*/
	}
	if (isAttacking) {

		if (targetLoc != -1) {
			allObjects->deleteAllAdvancedButtonObject();
			selectedTile = -1;

			if (mapTiles->at(targetLoc).creatureLink != "") {
				int creatureDataLoc;
				for (int counter = 0; counter < creatures->size(); counter++) {
					if (creatures->at(counter).name == mapTiles->at(targetLoc).creatureLink) {
						creatureDataLoc = counter;
					}
				}
				std::cout << creatures->at(creatureDataLoc).currentHealthPoints << std::endl;
				creatures->at(creatureDataLoc).currentHealthPoints -= attackQueue.at(0).damagePoints;
				std::cout << creatures->at(creatureDataLoc).currentHealthPoints << std::endl;
			}
			else {std::cout << "???" << std::endl; }
			
			//deal dammage and effects to the entiteis in the square here, if its an area of effect or somthing of the like you can add that here too.
		}
		else if (attackTimeCounter > 0) {
			attackTimeCounter -= 1;
			if (attackTimeCounter == 240) {
				for (int i = 0; i < allObjects->advancedButtonObjects.size(); i++)
				{
					allObjects->advancedButtonObjects.at(i)->objTexture = TextureManager::loadTexture("assets/RegHexBaseTarget4.png");
				}
			} else if (attackTimeCounter == 180) {
				for (int i = 0; i < allObjects->advancedButtonObjects.size(); i++)
				{
					allObjects->advancedButtonObjects.at(i)->objTexture = TextureManager::loadTexture("assets/RegHexBaseTarget3.png");
				}
			}
			else if (attackTimeCounter == 120) {
				for (int i = 0; i < allObjects->advancedButtonObjects.size(); i++)
				{
					allObjects->advancedButtonObjects.at(i)->objTexture = TextureManager::loadTexture("assets/RegHexBaseTarget2.png");
				}
			}
			else if (attackTimeCounter == 60) {
				for (int i = 0; i < allObjects->advancedButtonObjects.size(); i++)
				{
					allObjects->advancedButtonObjects.at(i)->objTexture = TextureManager::loadTexture("assets/RegHexBaseTarget1.png");
				}
			}
			
		}
		else {
			allObjects->deleteAllAdvancedButtonObject();
		}
	}
	if (moveQueue.size() > 0 && !isMoving && !isAttacking) {
		isMoving = true;
	}
	if (isMoving) {

	}
}
Character::Character() {

}
Character::Character(std::vector<battleMapTile>* map, ObjectDataBase* dataBase, std::vector<Creature>* creat, std::string setClassName, int startingTile) {
	isAttacking = false;
	isMoving = false;
	attackQueue.push_back(Attack(1, 2));
	loc = startingTile;
	allObjects = dataBase;
	mapTiles = map;
	creatures = creat;
	targetLoc = -1;
	if (setClassName == "Brute")
	{
		className = setClassName;
		maxHP = 25;
		currentHP = maxHP;
		inventorySize = 25;
		//loc = 1;
		iFrame = 0; weakened = 0;
		for (int counter = 0; counter < inventorySize/2; counter++) {
			deck.push_back(PlayerCard("atk", { CardEvent(attack, {3,1}) }, 30, ""));
		}
		for (int counter = 0; counter < inventorySize / 2; counter++) {
			deck.push_back(PlayerCard("mve", { CardEvent(move, {2,1}) }, 30, ""));
		}
	}
	if (setClassName == "Knight")
	{
		className = setClassName;
		maxHP = 20;
		currentHP = maxHP;
		inventorySize = 20;
		//loc = 2;
		iFrame = 0; weakened = 0;
	}

}

