#include "Character.h"
//#include<iostream>
int selectedTile = -1;
int selectedMoveTile = -1;
void selectTile(int inf) {
	selectedTile = inf;
	std::cout << "info: " << inf << "    ";
}
void selectMoveTile(int inf) {
	selectedMoveTile = inf;
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
	moveLoc = selectedMoveTile;
	if (pick.size() > 0) {
		if (pick.at(0) == attack) {
			if (attackQueue.size() > 0 && !isAttacking && !isMoving) {
			isAttacking = true;
			attackTimeCounter = 300;
			std::vector<Path> paths = { Path({mapTiles->at(loc).c1},4),Path({mapTiles->at(loc).c2},5),Path({mapTiles->at(loc).c3},6),Path({mapTiles->at(loc).c4},1),Path({mapTiles->at(loc).c5},2),Path({mapTiles->at(loc).c6},3) };
			if (mapTiles->at(loc).c6 != -1 && mapTiles->at(mapTiles->at(loc).c6).isUnpassable && mapTiles->at(mapTiles->at(loc).c6).creatureLink == "") {
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
			else if (mapTiles->at(loc).c6 == -1) {
				paths.erase(paths.begin() + 5);
			}
			if (mapTiles->at(loc).c5 != -1 && mapTiles->at(mapTiles->at(loc).c5).isUnpassable && mapTiles->at(mapTiles->at(loc).c5).creatureLink == "") {
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
			else if (mapTiles->at(loc).c5 == -1) {
				paths.erase(paths.begin() + 4);
			}
			if (mapTiles->at(loc).c4 != -1 && mapTiles->at(mapTiles->at(loc).c4).isUnpassable && mapTiles->at(mapTiles->at(loc).c4).creatureLink == "") {
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
			else if (mapTiles->at(loc).c4 == -1) {
				paths.erase(paths.begin() + 3);
			}
			if (mapTiles->at(loc).c3 != -1&&mapTiles->at(mapTiles->at(loc).c3).isUnpassable && mapTiles->at(mapTiles->at(loc).c3).creatureLink == "") {
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
			else if (mapTiles->at(loc).c3 == -1) {
				paths.erase(paths.begin() + 2);
			}
			if (mapTiles->at(loc).c2 != -1 && mapTiles->at(mapTiles->at(loc).c2).isUnpassable && mapTiles->at(mapTiles->at(loc).c2).creatureLink == "") {
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
			else if (mapTiles->at(loc).c2 == -1) {
				paths.erase(paths.begin() + 1);
			}
			if (mapTiles->at(loc).c1 != -1 && mapTiles->at(mapTiles->at(loc).c1).isUnpassable && mapTiles->at(mapTiles->at(loc).c1).creatureLink == "") {
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
			else if (mapTiles->at(loc).c1 == -1) {
				paths.erase(paths.begin() + 0);
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
						if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c1)) != -1) && (mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c1)).isUnpassable == false || (mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c1)).isUnpassable == true && (mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c1)).creatureLink != "")) && mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c1)).isShadowed == false)) {
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
						if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c6)) != -1) && (mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c6)).isUnpassable == false || (mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c6)).isUnpassable == true && (mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c6)).creatureLink != ""))) && mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c6)).isShadowed == false) {
							paths.push_back(paths.at(i));
							paths.at(paths.size() - 1).from = 3;
							paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c6);
						}

						if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c2)) != -1) && (mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c2)).isUnpassable == false || (mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c2)).isUnpassable == true && (mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c2)).creatureLink != ""))) && mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c2)).isShadowed == false) {
							paths.push_back(paths.at(i));
							paths.at(paths.size() - 1).from = 5;
							paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c2);
						}



					}
				
				
					else if (paths.at(i).from == 5) {
						if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c1)) != -1) && (mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c1)).isUnpassable == false || (mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c1)).isUnpassable == true && (mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c1)).creatureLink != ""))) && mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c1)).isShadowed == false) {
							paths.push_back(paths.at(i));
							paths.at(paths.size() - 1).from = 4;
							paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c1);
						}
						if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c3)) != -1) && (mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c3)).isUnpassable == false || (mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c3)).isUnpassable == true && (mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c3)).creatureLink != "")))&&  mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c3)).isShadowed == false) {
							paths.push_back(paths.at(i));
							paths.at(paths.size() - 1).from = 6;
							paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c3);
						}
						if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c2)) != -1) && (mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c2)).isUnpassable == false || (mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c2)).isUnpassable == true && (mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c2)).creatureLink != ""))) && mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c2)).isShadowed == false) {
							paths.push_back(paths.at(i));
							paths.at(paths.size() - 1).from = 5;
							paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c2);
						}
					}
					else if (paths.at(i).from == 6) {
						if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c2)) != -1) && (mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c2)).isUnpassable == false || (mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c2)).isUnpassable == true && (mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c2)).creatureLink != ""))) && mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c2)).isShadowed == false) {
							paths.push_back(paths.at(i));
							paths.at(paths.size() - 1).from = 5;
							paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c2);
						}
						if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c4)) != -1) && (mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c4)).isUnpassable == false || (mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c4)).isUnpassable == true && (mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c4)).creatureLink != ""))) && mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c4)).isShadowed == false) {
							paths.push_back(paths.at(i));
							paths.at(paths.size() - 1).from = 1;
							paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c4);
						}
						if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c3)) != -1) && (mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c3)).isUnpassable == false || (mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c3)).isUnpassable == true && (mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c3)).creatureLink != ""))) && mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c3)).isShadowed == false) {
							paths.push_back(paths.at(i));
							paths.at(paths.size() - 1).from = 6;
							paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c3);
						}
					}
					else if (paths.at(i).from == 1) {
						if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c3)) != -1) && (mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c3)).isUnpassable == false || (mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c3)).isUnpassable == true && (mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c3)).creatureLink != ""))) && mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c3)).isShadowed == false) {
							paths.push_back(paths.at(i));
							paths.at(paths.size() - 1).from = 6;
							paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c3);
						}
						if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c5)) != -1) && (mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c5)).isUnpassable == false || (mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c5)).isUnpassable == true && (mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c5)).creatureLink != ""))) && mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c5)).isShadowed == false) {
							paths.push_back(paths.at(i));
							paths.at(paths.size() - 1).from = 2;
							paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c5);
						}
						if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c4)) != -1) && (mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c4)).isUnpassable == false || (mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c4)).isUnpassable == true && (mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c4)).creatureLink != ""))) && mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c4)).isShadowed == false) {
							paths.push_back(paths.at(i));
							paths.at(paths.size() - 1).from = 1;
							paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c4);
						}
					}
					else if (paths.at(i).from == 2) {
						if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c4)) != -1) && (mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c4)).isUnpassable == false || (mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c4)).isUnpassable == true && (mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c4)).creatureLink != ""))) && mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c4)).isShadowed == false) {
							paths.push_back(paths.at(i));
							paths.at(paths.size() - 1).from = 1;
							paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c4);
						}
						if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c6)) != -1) && (mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c6)).isUnpassable == false || (mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c6)).isUnpassable == true && (mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c6)).creatureLink != ""))) && mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c6)).isShadowed == false) {
							paths.push_back(paths.at(i));
							paths.at(paths.size() - 1).from = 3;
							paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c6);
						}
						if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c5)) != -1) && (mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c5)).isUnpassable == false || (mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c5)).isUnpassable == true && (mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c5)).creatureLink != ""))) && mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c5)).isShadowed == false) {
							paths.push_back(paths.at(i));
							paths.at(paths.size() - 1).from = 2;
							paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c5);
						}
					}
					else if (paths.at(i).from == 3) {
					if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c6)) != -1) && (mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c6)).isUnpassable == false || (mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c6)).isUnpassable == true && (mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c6)).creatureLink != ""))) && mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c6)).isShadowed == false) {
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
					if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c5)) != -1) && (mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c5)).isUnpassable == false || (mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c5)).isUnpassable == true && (mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c5)).creatureLink != ""))) && mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c5)).isShadowed == false) {
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
				allObjects->addObject(new AdvancedButtonObject("targetButton", "assets/RegHexBaseTarget5.png", &selectTile, allObjects->getDetailObject(name)->xPos, allObjects->getDetailObject(name)->yPos, 110, 96, it));
			}

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
				else { std::cout << "???" << std::endl; }
				attackQueue.erase(attackQueue.begin() + 0);
				pick.erase(pick.begin() + 0);
				selectedTile = - 1;
				targetLoc = -1;
				attackTimeCounter = 300;
				isAttacking = false;
				//deal dammage and effects to the entiteis in the square here, if its an area of effect or somthing of the like you can add that here too.
			}
			else if (attackTimeCounter > 0) {
				attackTimeCounter -= 1;
				if (attackTimeCounter == 240) {
					for (int i = 0; i < allObjects->advancedButtonObjects.size(); i++)
					{
						allObjects->advancedButtonObjects.at(i)->objTexture = TextureManager::loadTexture("assets/RegHexBaseTarget4.png");
					}
				}
				else if (attackTimeCounter == 180) {
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
				pick.erase(pick.begin() + 0);
				attackQueue.erase(attackQueue.begin() + 0);
				attackTimeCounter = 300;
				isAttacking = false;
			}
		}
	}
		else if (pick.at(0) == move) {
			if (moveQueue.size() > 0 && !isMoving && !isAttacking) {
				isMoving = true;
				std::vector<Path> paths = { Path({mapTiles->at(loc).c1},4),Path({mapTiles->at(loc).c2},5),Path({mapTiles->at(loc).c3},6),Path({mapTiles->at(loc).c4},1),Path({mapTiles->at(loc).c5},2),Path({mapTiles->at(loc).c6},3) };
				if (mapTiles->at(loc).c6 == -1 || mapTiles->at(mapTiles->at(loc).c6).isUnpassable) {
					paths.erase(paths.begin() + 5);
				}
				if (mapTiles->at(loc).c5 == -1 || mapTiles->at(mapTiles->at(loc).c5).isUnpassable) {
					paths.erase(paths.begin() + 4);
				}
				if (mapTiles->at(loc).c4 == -1 || mapTiles->at(mapTiles->at(loc).c4).isUnpassable) {
					paths.erase(paths.begin() + 3);

				}
				if (mapTiles->at(loc).c3 == -1 || mapTiles->at(mapTiles->at(loc).c3).isUnpassable) {
					paths.erase(paths.begin() + 2);
				}
				if (mapTiles->at(loc).c2 == -1 || mapTiles->at(mapTiles->at(loc).c2).isUnpassable) {
					paths.erase(paths.begin() + 1);
				}
				if (mapTiles->at(loc).c1 == -1 || mapTiles->at(mapTiles->at(loc).c1).isUnpassable) {
					paths.erase(paths.begin() + 0);
					
				}
				//std::cout << "    Paths in list: " << paths.size() << "      ";
				//std::vector<int> currentShortest = { };
				bool going = true;
				int currentLeng = 1;
				for (int f = 0; f < moveQueue.at(0).range; f++)
				{
					int pathSize = paths.size();
					for (int i = 0; i < pathSize; i++)
					{
						if (paths.at(i).from == 4) {
							if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c1)) != -1) && mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c1)).isUnpassable == false ) {
								paths.push_back(paths.at(i));
								paths.at(paths.size() - 1).from = 4;
								paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c1);
							}
							if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c6)) != -1) && mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c6)).isUnpassable == false ) {
								paths.push_back(paths.at(i));
								paths.at(paths.size() - 1).from = 3;
								paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c6);
							}

							if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c2)) != -1) && mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c2)).isUnpassable == false ) {
								paths.push_back(paths.at(i));
								paths.at(paths.size() - 1).from = 5;
								paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c2);
							}



						}
						else if (paths.at(i).from == 5) {
							if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c1)) != -1) && mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c1)).isUnpassable == false ) {
								paths.push_back(paths.at(i));
								paths.at(paths.size() - 1).from = 4;
								paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c1);
							}
							if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c3)) != -1) && mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c3)).isUnpassable == false ) {
								paths.push_back(paths.at(i));
								paths.at(paths.size() - 1).from = 6;
								paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c3);
							}
							if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c2)) != -1) && mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c2)).isUnpassable == false ) {
								paths.push_back(paths.at(i));
								paths.at(paths.size() - 1).from = 5;
								paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c2);
							}
						}
						else if (paths.at(i).from == 6) {
							if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c2)) != -1) && mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c2)).isUnpassable == false ) {
								paths.push_back(paths.at(i));
								paths.at(paths.size() - 1).from = 5;
								paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c2);
							}
							if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c4)) != -1) && mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c4)).isUnpassable == false ) {
								paths.push_back(paths.at(i));
								paths.at(paths.size() - 1).from = 1;
								paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c4);
							}
							if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c3)) != -1) && mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c3)).isUnpassable == false ) {
								paths.push_back(paths.at(i));
								paths.at(paths.size() - 1).from = 6;
								paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c3);
							}
						}
						else if (paths.at(i).from == 1) {
							if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c3)) != -1) && mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c3)).isUnpassable == false ) {
								paths.push_back(paths.at(i));
								paths.at(paths.size() - 1).from = 6;
								paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c3);
							}
							if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c5)) != -1) && mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c5)).isUnpassable == false ) {
								paths.push_back(paths.at(i));
								paths.at(paths.size() - 1).from = 2;
								paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c5);
							}
							if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c4)) != -1) && mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c4)).isUnpassable == false ) {
								paths.push_back(paths.at(i));
								paths.at(paths.size() - 1).from = 1;
								paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c4);
							}
						}
						else if (paths.at(i).from == 2) {
							if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c4)) != -1) && mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c4)).isUnpassable == false ) {
								paths.push_back(paths.at(i));
								paths.at(paths.size() - 1).from = 1;
								paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c4);
							}
							if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c6)) != -1) && mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c6)).isUnpassable == false ) {

								paths.push_back(paths.at(i));
								paths.at(paths.size() - 1).from = 3;
								paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c6);
							}
							if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c5)) != -1) && mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c5)).isUnpassable == false ) {
								paths.push_back(paths.at(i));
								paths.at(paths.size() - 1).from = 2;
								paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c5);
							}
						}
						else if (paths.at(i).from == 3) {
							if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c6)) != -1) && mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c6)).isUnpassable == false ) {
								paths.push_back(paths.at(i));
								paths.at(paths.size() - 1).from = 3;
								paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c6);
							}
							
							if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c5)) != -1) && mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c5)).isUnpassable == false ) {
								paths.push_back(paths.at(i));
								paths.at(paths.size() - 1).from = 2;

								paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c5);
							}
							if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c1)) != -1) && mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c1)).isUnpassable == false ) {
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
					allObjects->addObject(new AdvancedButtonObject("targetButton", "assets/RegHexBaseTarget5.png", &selectMoveTile, allObjects->getDetailObject(name)->xPos, allObjects->getDetailObject(name)->yPos, 110, 96, it));
				}
			}
			if (isMoving) {
				//std::cout << "lloopeded";
				if (moveLoc != -1) {
					allObjects->deleteAllAdvancedButtonObject();
					if (goalSet == false) {

						if (pathWeave.size() == 0) {
							//std::cout << "Destintation: " << moveDest << "   ";
							path();
						}

						if (mapTiles->at(loc).c1 == pathWeave.at(0)) {
							goaly -= 96;
						}
						else if (mapTiles->at(loc).c2 == pathWeave.at(0)) {
							goaly -= 48;
							goalx += 83;
						}
						else if (mapTiles->at(loc).c3 == pathWeave.at(0)) {
							goaly += 48;
							goalx += 83;
						}
						else if (mapTiles->at(loc).c4 == pathWeave.at(0)) {
							goaly += 96;
						}
						else if (mapTiles->at(loc).c5 == pathWeave.at(0)) {
							goaly += 48;
							goalx -= 83;
						}
						else if (mapTiles->at(loc).c6 == pathWeave.at(0)) {
							goaly -= 48;
							goalx -= 83;
						}
						goalSet = true;
					}
					else if (goalSet == true)
					{

						if (halfGoal == 0)
						{
							halfGoal = sqrt(pow(goalx - allObjects->getDetailObject(className)->xPos, 2) + pow(goaly - (allObjects->getDetailObject(className)->yPos), 2)) / 2;

						}
						int tilenumb = pathWeave.at(0);
						bool reached = true;
						bool half = false;
						//std::cout << "Goalx: " << goalx << "Goaly: " << goaly;
						//if (mapTiles->at(tilenumb).isUnpassable == false) {
						if (allObjects->getDetailObject(className)->yPos < goaly) {
							allObjects->getDetailObject(className)->moveObject(0, 1);
							reached = false;
						}
						else if (allObjects->getDetailObject(className)->yPos > goaly) {
							allObjects->getDetailObject(className)->moveObject(0, -1);
							reached = false;
						}
						if (allObjects->getDetailObject(className)->xPos < goalx) {
							allObjects->getDetailObject(className)->moveObject(1, 0);
							reached = false;
						}
						else if (allObjects->getDetailObject(className)->xPos > goalx) {
							allObjects->getDetailObject(className)->moveObject(-1, 0);
							reached = false;
						}
						if (sqrt(pow(abs(goalx - allObjects->getDetailObject(className)->xPos), 2) + pow(abs(goaly - (allObjects->getDetailObject(className)->yPos)), 2)) >= halfGoal - 5 && sqrt(pow(abs(goalx - allObjects->getDetailObject(className)->xPos), 2) + pow(abs(goaly - (allObjects->getDetailObject(className)->yPos)), 2)) <= halfGoal + 5)
						{
							half = true;
						}
						if (half)
						{
							mapTiles->at(loc).characterLink = className;
							mapTiles->at(loc).isUnpassable = true;
							halfGoal = -6;
							std::cout << "reached half" << std::endl;
						}
						if (reached) {
							mapTiles->at(loc).isUnpassable = false;
							mapTiles->at(loc).characterLink = "";
							loc = pathWeave.at(0);

							pathWeave.erase(pathWeave.begin() + 0);
							goalSet = false;
							halfGoal = 0;
							std::cout << "reached full" << std::endl;
							if (pathWeave.size() == 0) {
								moveLoc = -1;
								selectedMoveTile = -1;
								isMoving = false;
								moveQueue.erase(moveQueue.begin() + 0);
								pathWeave = { };
								pick.erase(pick.begin() + 0);
							}
							//std::cout << "New current tile: " << loc;
						}
						//}
						//else {
						//	moving = false;
						//	goalSet = false;
						//}
					}
				}



			}

		}
	}
}
Character::Character() {

}
Character::Character(std::vector<battleMapTile>* map, ObjectDataBase* dataBase, std::vector<Creature>* creat, std::string setClassName, int startingTile) {
	isAttacking = false;
	isMoving = false;
	goalSet = false;
	//moveQueue.push_back(Move(1, 2));
	loc = startingTile;
	allObjects = dataBase;
	mapTiles = map;
	className = setClassName;
	map->at(0).characterLink = className;
	creatures = creat;
	targetLoc = -1;
	std::string objectTag = "tile" + std::to_string(startingTile);
	std::cout << objectTag << " ";
	goalx = allObjects->getDetailObject(objectTag)->xPos + 30;
	goaly = allObjects->getDetailObject(objectTag)->yPos + 20;
	allObjects->getDetailObject(setClassName)->xPos = goalx;
	allObjects->getDetailObject(setClassName)->yPos = goaly;
	deck.push_back(PlayerCard("atk", { CardEvent(attack, {3,1}) }, 30, "assets/AtkCard.png"));
	deck.push_back(PlayerCard("atk", { CardEvent(attack, {3,1}) }, 30, "assets/AtkCard.png"));
	deck.push_back(PlayerCard("mve", { CardEvent(move, {2,1}) }, 30, "assets/MovCard.png"));
	deck.push_back(PlayerCard("mvenatk", { CardEvent(move, {2,1}),CardEvent(attack, {3,1}) }, 30, "assets/MovnAtkCard.png"));
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
	for (int counter = 0; counter < 4; counter++) {
		hand.push_back(deck.at(0));
		deck.erase(deck.begin() + 0);
	}
}

void Character::path() {
	std::vector<Path> paths = { Path({mapTiles->at(loc).c1},4),Path({mapTiles->at(loc).c2},5),Path({mapTiles->at(loc).c3},6),Path({mapTiles->at(loc).c4},1),Path({mapTiles->at(loc).c5},2),Path({mapTiles->at(loc).c6},3) };
	if (mapTiles->at(loc).c6 == -1 || mapTiles->at(mapTiles->at(loc).c6).isUnpassable) {
		paths.erase(paths.begin() + 5);
	}
	if (mapTiles->at(loc).c5 == -1 || mapTiles->at(mapTiles->at(loc).c5).isUnpassable) {
		paths.erase(paths.begin() + 4);
	}
	if (mapTiles->at(loc).c4 == -1 || mapTiles->at(mapTiles->at(loc).c4).isUnpassable) {
		paths.erase(paths.begin() + 3);
	}
	if (mapTiles->at(loc).c3 == -1 || mapTiles->at(mapTiles->at(loc).c3).isUnpassable) {
		paths.erase(paths.begin() + 2);
	}
	if (mapTiles->at(loc).c2 == -1 || mapTiles->at(mapTiles->at(loc).c2).isUnpassable) {
		paths.erase(paths.begin() + 1);
	}
	if (mapTiles->at(loc).c1 == -1 || mapTiles->at(mapTiles->at(loc).c1).isUnpassable) {
		paths.erase(paths.begin() + 0);
	}
	//std::cout << "    Paths in list: " << paths.size() << "      ";
	//std::vector<int> currentShortest = { };
	bool going = true;
	int currentLeng = 1;
	while (going) {
		std::cout << "Patthsloop";
		int pathSize = paths.size();
		for (int i = 0; i < pathSize; i++)
		{
			if (paths.at(i).weave.at(paths.at(i).weave.size() - 1) == moveLoc) {
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
		//std::cout << pathWeave.at(i) << "  ";
	}
}



