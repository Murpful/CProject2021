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
		std::cout << "QueueSize: " << attackQueue.size() << std::endl;
		if (selectedCard.cardEvents.at(i).action == attack) {
			std::cout << "selecting attack" << std::endl;
			attackQueue.push_back(Attack(selectedCard.cardEvents.at(i).data.at(0), selectedCard.cardEvents.at(i).data.at(1), selectedCard.cardEvents.at(i).data.at(2),
							selectedCard.cardEvents.at(i).data.at(3), selectedCard.cardEvents.at(i).data.at(4), selectedCard.cardEvents.at(i).actionAnimation));
			std::cout << "atlFrame: " << attackQueue.at(0).frames << std::endl;
		}
		if (selectedCard.cardEvents.at(i).action == move) {
			moveQueue.push_back(Move(selectedCard.cardEvents.at(i).data.at(0), selectedCard.cardEvents.at(i).data.at(1)));
		}
		if (selectedCard.cardEvents.at(i).action == dodge) {
			dodgeQueue.push_back(Dodge(selectedCard.cardEvents.at(i).data.at(0)));
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
	//std::cout << "animation created: " << allObjects->DetectDetailObject("atkAnimation") << std::endl;
	static int attackTimeCounter = 0;
	//int iFrameCounter = 0;
	//std::cout << targetLoc;
	targetLoc = selectedTile;
	moveLoc = selectedMoveTile;
	if (pick.size() > 0) {
		if (pick.at(0) == attack) {
			if (attackQueue.size() > 0 && !isAttacking && !isMoving && !isDodging) {
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
				if (mapTiles->at(loc).c3 != -1 && mapTiles->at(mapTiles->at(loc).c3).isUnpassable && mapTiles->at(mapTiles->at(loc).c3).creatureLink == "") {
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
							if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c3)) != -1) && (mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c3)).isUnpassable == false || (mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c3)).isUnpassable == true && (mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c3)).creatureLink != ""))) && mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c3)).isShadowed == false) {
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
					allObjects->addObject(new AdvancedHexagonalButtonObject("targetButton", "assets/RegHexBaseTarget5.png", it, &selectTile, allObjects->getDetailObject(name)->xPos, allObjects->getDetailObject(name)->yPos, 48, 110, 96));
				}

			}
			if (isAttacking) {
				if (targetLoc != -1 && atkCounter == 0) {
					allObjects->addObject(new DetailObject("atkAnimation", attackQueue.at(0).animation, allObjects->getDetailObject(className)->xPos,
						allObjects->getDetailObject(className)->yPos, 50, 50, 50, 50, true, attackQueue.at(0).frames, attackQueue.at(0).frameTime, false));
				}
				if (atkCounter < attackQueue.at(0).atkTime) {
					if (targetLoc != -1) {
						allObjects->deleteAllAdvancedHexagonalButtonObject();
						//std::cout << "frameTime: " << attackQueue.at(0).frameTime<< std::endl;
						//std::cout << "atkTime" << attackQueue.at(0).atkTime << std::endl;
						atkCounter++;
						//selectedTile = -1;
						if (atkCounter == attackQueue.at(0).subAtkTime) {
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
						}
						else if (atkCounter == attackQueue.at(0).atkTime){
							attackQueue.erase(attackQueue.begin() + 0);
							pick.erase(pick.begin() + 0);
							selectedTile = -1;
							targetLoc = -1;
							atkCounter = 0;
							allObjects->deleteDetailObject("atkAnimation");
							attackTimeCounter = 300;
							isAttacking = false;
							//deal dammage and effects to the entiteis in the square here, if its an area of effect or somthing of the like you can add that here too.
						}
					}
					else if (attackTimeCounter > 0) {
						attackTimeCounter -= 1;
						if (attackTimeCounter == 240) {
							for (int i = 0; i < allObjects->advancedHexagonalButtonObjects.size(); i++)
							{
								allObjects->advancedHexagonalButtonObjects.at(i)->objTexture = TextureManager::loadTexture("assets/RegHexBaseTarget4.png");
							}
						}
						else if (attackTimeCounter == 180) {
							for (int i = 0; i < allObjects->advancedHexagonalButtonObjects.size(); i++)
							{
								allObjects->advancedHexagonalButtonObjects.at(i)->objTexture = TextureManager::loadTexture("assets/RegHexBaseTarget3.png");
							}
						}
						else if (attackTimeCounter == 120) {
							for (int i = 0; i < allObjects->advancedHexagonalButtonObjects.size(); i++)
							{
								allObjects->advancedHexagonalButtonObjects.at(i)->objTexture = TextureManager::loadTexture("assets/RegHexBaseTarget2.png");
							}
						}
						else if (attackTimeCounter == 60) {
							for (int i = 0; i < allObjects->advancedHexagonalButtonObjects.size(); i++)
							{
								allObjects->advancedHexagonalButtonObjects.at(i)->objTexture = TextureManager::loadTexture("assets/RegHexBaseTarget1.png");
							}
						}

					}
				}
				else {
					allObjects->deleteAllAdvancedHexagonalButtonObject();
					pick.erase(pick.begin() + 0);
					attackQueue.erase(attackQueue.begin() + 0);

					attackTimeCounter = 300;
					isAttacking = false;
				}
			}
		}
		else if (pick.at(0) == move) {
			if (moveQueue.size() > 0 && !isMoving && !isAttacking && !isDodging) {
				isMoving = true;
				std::vector<Path> paths = { Path({mapTiles->at(loc).c1},4),Path({mapTiles->at(loc).c2},5),Path({mapTiles->at(loc).c3},6),Path({mapTiles->at(loc).c4},1),Path({mapTiles->at(loc).c5},2),Path({mapTiles->at(loc).c6},3) };
				if (mapTiles->at(loc).c6 == -1 || (mapTiles->at(mapTiles->at(loc).c6).isUnpassable && mapTiles->at(mapTiles->at(loc).c6).creatureLink == "")) {
					paths.erase(paths.begin() + 5);
				}
				if (mapTiles->at(loc).c5 == -1 || (mapTiles->at(mapTiles->at(loc).c5).isUnpassable && mapTiles->at(mapTiles->at(loc).c5).creatureLink == "")) {
					paths.erase(paths.begin() + 4);
				}
				if (mapTiles->at(loc).c4 == -1 || (mapTiles->at(mapTiles->at(loc).c4).isUnpassable && mapTiles->at(mapTiles->at(loc).c4).creatureLink == "")) {
					paths.erase(paths.begin() + 3);

				}
				if (mapTiles->at(loc).c3 == -1 || (mapTiles->at(mapTiles->at(loc).c3).isUnpassable && mapTiles->at(mapTiles->at(loc).c3).creatureLink == "")) {
					paths.erase(paths.begin() + 2);
				}
				if (mapTiles->at(loc).c2 == -1 || (mapTiles->at(mapTiles->at(loc).c2).isUnpassable && mapTiles->at(mapTiles->at(loc).c2).creatureLink == "")) {
					paths.erase(paths.begin() + 1);
				}
				if (mapTiles->at(loc).c1 == -1 || (mapTiles->at(mapTiles->at(loc).c1).isUnpassable && mapTiles->at(mapTiles->at(loc).c1).creatureLink == "")) {
					paths.erase(paths.begin() + 0);

				}
				//std::cout << "    Paths in list: " << paths.size() << "      ";
				//std::vector<int> currentShortest = { };
				bool going = true;
				int currentLeng = 1;
				for (int f = 0; f < moveQueue.at(0).range; f++)
				{
					std::cout << "ranthepaththistime: " << f << std::endl;
					int pathSize = paths.size();
					for (int i = 0; i < pathSize; i++)
					{
						if (paths.at(i).from == 4) {
							if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c1)) != -1) && (mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c1)).isUnpassable == false || mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c1)).creatureLink != "")) {
								paths.push_back(paths.at(i));
								paths.at(paths.size() - 1).from = 4;
								paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c1);
							}
							if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c6)) != -1) && (mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c6)).isUnpassable == false || mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c6)).creatureLink != "")) {
								paths.push_back(paths.at(i));
								paths.at(paths.size() - 1).from = 3;
								paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c6);
							}

							if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c2)) != -1) && (mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c2)).isUnpassable == false || mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c2)).creatureLink != "")) {
								paths.push_back(paths.at(i));
								paths.at(paths.size() - 1).from = 5;
								paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c2);
							}



						}
						else if (paths.at(i).from == 5) {
							if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c1)) != -1) && (mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c1)).isUnpassable == false || mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c1)).creatureLink != "")) {
								paths.push_back(paths.at(i));
								paths.at(paths.size() - 1).from = 4;
								paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c1);
							}
							if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c3)) != -1) && (mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c3)).isUnpassable == false || mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c3)).creatureLink != "")) {
								paths.push_back(paths.at(i));
								paths.at(paths.size() - 1).from = 6;
								paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c3);
							}
							if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c2)) != -1) && (mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c2)).isUnpassable == false || mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c2)).creatureLink != "")) {
								paths.push_back(paths.at(i));
								paths.at(paths.size() - 1).from = 5;
								paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c2);
							}
						}
						else if (paths.at(i).from == 6) {
							if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c2)) != -1) && (mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c2)).isUnpassable == false || mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c2)).creatureLink != "")) {
								paths.push_back(paths.at(i));
								paths.at(paths.size() - 1).from = 5;
								paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c2);
							}
							if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c4)) != -1) && (mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c4)).isUnpassable == false || mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c4)).creatureLink != "")) {
								paths.push_back(paths.at(i));
								paths.at(paths.size() - 1).from = 1;
								paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c4);
							}
							if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c3)) != -1) && (mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c3)).isUnpassable == false || mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c3)).creatureLink != "")) {
								paths.push_back(paths.at(i));
								paths.at(paths.size() - 1).from = 6;
								paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c3);
							}
						}
						else if (paths.at(i).from == 1) {
							if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c3)) != -1) && (mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c3)).isUnpassable == false || mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c3)).creatureLink != "")) {
								paths.push_back(paths.at(i));
								paths.at(paths.size() - 1).from = 6;
								paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c3);
							}
							if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c5)) != -1) && (mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c5)).isUnpassable == false || mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c5)).creatureLink != "")) {
								paths.push_back(paths.at(i));
								paths.at(paths.size() - 1).from = 2;
								paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c5);
							}
							if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c4)) != -1) && (mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c4)).isUnpassable == false || mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c4)).creatureLink != "")) {
								paths.push_back(paths.at(i));
								paths.at(paths.size() - 1).from = 1;
								paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c4);
							}
						}
						else if (paths.at(i).from == 2) {
							if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c4)) != -1) && (mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c4)).isUnpassable == false || mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c4)).creatureLink != "")) {
								paths.push_back(paths.at(i));
								paths.at(paths.size() - 1).from = 1;
								paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c4);
							}
							if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c6)) != -1) && (mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c6)).isUnpassable == false || mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c6)).creatureLink != "")) {

								paths.push_back(paths.at(i));
								paths.at(paths.size() - 1).from = 3;
								paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c6);
							}
							if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c5)) != -1) && (mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c5)).isUnpassable == false || mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c5)).creatureLink != "")) {
								paths.push_back(paths.at(i));
								paths.at(paths.size() - 1).from = 2;
								paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c5);
							}
						}
						else if (paths.at(i).from == 3) {
							if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c6)) != -1) && (mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c6)).isUnpassable == false || mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c6)).creatureLink != "")) {
								paths.push_back(paths.at(i));
								paths.at(paths.size() - 1).from = 3;
								paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c6);
							}

							if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c5)) != -1) && (mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c5)).isUnpassable == false || mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c5)).creatureLink != "")) {
								paths.push_back(paths.at(i));
								paths.at(paths.size() - 1).from = 2;

								paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c5);
							}
							if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c1)) != -1) && (mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c1)).isUnpassable == false || mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c1)).creatureLink != "")) {
								paths.push_back(paths.at(i));
								paths.at(paths.size() - 1).from = 4;
								paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c1);
							}

						}
					}
				}

				std::vector<int> finalTiles = { loc };
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
					allObjects->addObject(new AdvancedHexagonalButtonObject("targetButton", "assets/RegHexBaseTarget.png", it, &selectMoveTile, allObjects->getDetailObject(name)->xPos, allObjects->getDetailObject(name)->yPos, 48, 110, 96));
				}
			}
			else if (isMoving) {
				//std::cout << "lloopeded";
				if (moveLoc != -1) {
					bool nomove = false;
					if (goalSet == true && pathWeave.size() == 0) {

						std::cout << "goalSet" << std::endl;
						nomove = true;
					}
					if (goalSet == false) {
						std::cout << "Why?" << std::endl;
						if (pathWeave.size() == 0) {
							allObjects->deleteAllAdvancedHexagonalButtonObject();
							//std::cout << "Destintation: " << moveDest << "   ";
							path();
						}

						if (pathWeave.size() > 0) {
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

						}
						else {
							nomove = true;
						}


						goalSet = true;
					}
					else if (!nomove && (goalSet == true && mapTiles->at(pathWeave.at(0)).creatureLink == ""))
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
						if (allObjects->getDetailObject(className)->yPos < goaly - 3) {
							allObjects->getDetailObject(className)->moveObject(0, 1 * (moveQueue.at(0).speed));
							reached = false;
						}
						else if (allObjects->getDetailObject(className)->yPos > goaly + 3) {
							allObjects->getDetailObject(className)->moveObject(0, -1 * (moveQueue.at(0).speed));
							reached = false;
						}
						if (allObjects->getDetailObject(className)->xPos < goalx - 3) {
							allObjects->getDetailObject(className)->moveObject(1 * (moveQueue.at(0).speed), 0);
							reached = false;
						}
						else if (allObjects->getDetailObject(className)->xPos > goalx + 3) {
							allObjects->getDetailObject(className)->moveObject(-1 * (moveQueue.at(0).speed), 0);
							reached = false;
						}
						if (sqrt(pow(abs(goalx - allObjects->getDetailObject(className)->xPos), 2) + pow(abs(goaly - (allObjects->getDetailObject(className)->yPos)), 2)) >= halfGoal - 5 && sqrt(pow(abs(goalx - allObjects->getDetailObject(className)->xPos), 2) + pow(abs(goaly - (allObjects->getDetailObject(className)->yPos)), 2)) <= halfGoal + 5)
						{
							half = true;
						}
						if (half)
						{
							mapTiles->at(loc).characterLink = "";
							mapTiles->at(loc).isUnpassable = false;
							mapTiles->at(pathWeave.at(0)).characterLink = className;
							mapTiles->at(pathWeave.at(0)).isUnpassable = true;
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
						// moving = false;
						// goalSet = false;
						//}
					}
					else if (!nomove && (goalSet == true && mapTiles->at(pathWeave.at(0)).creatureLink != "")) {
						goalSet = false;
						halfGoal = 0;
						pathWeave = { };
						std::string objectTag = "tile" + std::to_string(loc);
						//std::cout << objectTag << " ";
						goalx = allObjects->getDetailObject(objectTag)->xPos + 30;
						goaly = allObjects->getDetailObject(objectTag)->yPos + 20;
						allObjects->getDetailObject(className)->xPos = goalx;
						allObjects->getDetailObject(className)->yPos = goaly;
						moveLoc = -1;
						selectedMoveTile = -1;
						isMoving = false;
						moveQueue.erase(moveQueue.begin() + 0);
						pathWeave = { };
						pick.erase(pick.begin() + 0);
					}
					else if (nomove) {
						goalSet = false;
						halfGoal = 0;
						pathWeave = { };
						std::string objectTag = "tile" + std::to_string(loc);
						//std::cout << objectTag << " ";
						goalx = allObjects->getDetailObject(objectTag)->xPos + 30;
						goaly = allObjects->getDetailObject(objectTag)->yPos + 20;
						allObjects->getDetailObject(className)->xPos = goalx;
						allObjects->getDetailObject(className)->yPos = goaly;
						moveLoc = -1;
						selectedMoveTile = -1;
						isMoving = false;
						moveQueue.erase(moveQueue.begin() + 0);
						pathWeave = { };
						pick.erase(pick.begin() + 0);
					}
				}



			}

		}
		else if (pick.at(0) == dodge) {
			if (dodgeQueue.size() > 0 && !isMoving && !isAttacking && !isDodging) {
				isDodging = true;
				iFrameCounter = 0;
				allObjects->getDetailObject(className)->srcRect.y = allObjects->getDetailObject(className)->height;
				dodgeQueue.erase(dodgeQueue.begin() + 0);

			}
			else if (isDodging) {
				if (iFrameCounter >= 30) {
					std::cout << "Dodge" << std::endl;
					isDodging = false;
					allObjects->getDetailObject(className)->srcRect.y = 0;
					iFrameCounter = 0;
					pick.erase(pick.begin() + 0);
				}
				else iFrameCounter++;
			}
			//
		}
	}
	if (deck.size() == 0) {
		for (int i = 0; i < discard.size(); i++)
		{
			int location = rand() % discard.size();
			deck.push_back(discard.at(location));
			discard.erase(discard.begin() + location);
		}

	}
	if (hand.size() < 4) {
		hand.push_back(deck.at(0));
		deck.erase(deck.begin() + 0);
		std::cout << hand.size();
	}
}
Character::Character() {

}
Character::Character(std::vector<battleMapTile>* map, ObjectDataBase* dataBase, std::vector<Creature>* creat, std::string setClassName, int startingTile) {
	isAttacking = false;
	isMoving = false;
	isDodging = false;
	goalSet = false;
	iFrameCounter = 0;
	atkCounter = 0;
	discard = { };
	deck = { };
	//moveQueue.push_back(Move(1, 2));
	loc = startingTile;
	allObjects = dataBase;
	mapTiles = map;
	className = setClassName;
	map->at(0).characterLink = className;
	creatures = creat;
	targetLoc = -1;
	std::string objectTag = "tile" + std::to_string(startingTile);
	//std::cout << objectTag << " ";
	goalx = allObjects->getDetailObject(objectTag)->xPos + 30;
	goaly = allObjects->getDetailObject(objectTag)->yPos + 20;
	allObjects->getDetailObject(setClassName)->xPos = goalx;
	allObjects->getDetailObject(setClassName)->yPos = goaly;
	discard.push_back(PlayerCard("atk", { CardEvent(attack, {3,1, 150, 100, 4},"assets/atkAnim.png") }, 30, "assets/AtkCard.png"));
	discard.push_back(PlayerCard("atk", { CardEvent(attack, {3,1, 150, 100, 4},"assets/atkAnim.png") }, 30, "assets/AtkCard.png"));
	discard.push_back(PlayerCard("mve", { CardEvent(move, {1,1}) }, 30, "assets/MovCard.png"));
	discard.push_back(PlayerCard("mvenatk", { CardEvent(move, {1,1}),CardEvent(attack, {3,1, 150, 100,4},"assets/atkAnim.png") }, 30, "assets/MovnAtkCard.png"));
	discard.push_back(PlayerCard("mvenatkmov", { CardEvent(move, {2,1}),CardEvent(attack, {2,0, 150, 100,4},"assets/atkAnim.png"),CardEvent(move, {2,1}) }, 30, "assets/moveatkmovCard.png"));
	discard.push_back(PlayerCard("mvefar", { CardEvent(move, {3,2}) }, 30, "assets/LongMovCard.png"));
	discard.push_back(PlayerCard("ddg", { CardEvent(dodge,{30}) }, 30, "assets/DdgCard.png"));
	if (setClassName == "Brute")
	{
		className = setClassName;
		maxHP = 25;
		currentHP = maxHP;
		inventorySize = 25;
		//loc = 1;
		iFrame = 0; weakened = 0;
		for (int counter = 0; counter < inventorySize / 2; counter++) {
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
	int repaeats = discard.size();
	for (int f = 0; f < repaeats; f++)
	{
		//std::cout << "  ASDFASDFASDF";
		int location = rand() % discard.size();
		deck.push_back(discard.at(location));
		discard.erase(discard.begin() + location);
	}
	for (int counter = 0; counter < 4; counter++) {
		hand.push_back(deck.at(0));
		deck.erase(deck.begin() + 0);
	}
	dataBase->changeText("cardsInHand", std::to_string(deck.size()));
}

void Character::path() {
	if (moveLoc != loc) {
		std::vector<Path> paths = { Path({mapTiles->at(loc).c1},4),Path({mapTiles->at(loc).c2},5),Path({mapTiles->at(loc).c3},6),Path({mapTiles->at(loc).c4},1),Path({mapTiles->at(loc).c5},2),Path({mapTiles->at(loc).c6},3) };
		if (mapTiles->at(loc).c6 == -1 || (mapTiles->at(mapTiles->at(loc).c6).isUnpassable && mapTiles->at(mapTiles->at(loc).c6).creatureLink == "")) {
			paths.erase(paths.begin() + 5);
		}
		if (mapTiles->at(loc).c5 == -1 || (mapTiles->at(mapTiles->at(loc).c5).isUnpassable && mapTiles->at(mapTiles->at(loc).c5).creatureLink == "")) {
			paths.erase(paths.begin() + 4);
		}
		if (mapTiles->at(loc).c4 == -1 || (mapTiles->at(mapTiles->at(loc).c4).isUnpassable && mapTiles->at(mapTiles->at(loc).c4).creatureLink == "")) {
			paths.erase(paths.begin() + 3);
		}
		if (mapTiles->at(loc).c3 == -1 || (mapTiles->at(mapTiles->at(loc).c3).isUnpassable && mapTiles->at(mapTiles->at(loc).c3).creatureLink == "")) {
			paths.erase(paths.begin() + 2);
		}
		if (mapTiles->at(loc).c2 == -1 || (mapTiles->at(mapTiles->at(loc).c2).isUnpassable && mapTiles->at(mapTiles->at(loc).c2).creatureLink == "")) {
			paths.erase(paths.begin() + 1);
		}
		if (mapTiles->at(loc).c1 == -1 || (mapTiles->at(mapTiles->at(loc).c1).isUnpassable && mapTiles->at(mapTiles->at(loc).c1).creatureLink == "")) {
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
						if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c6)) != -1) && (mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c6)).isUnpassable == false || mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c6)).creatureLink != "")) {
							paths.push_back(paths.at(i));
							paths.at(paths.size() - 1).from = 3;
							paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c6);
						}

						if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c2)) != -1) && (mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c2)).isUnpassable == false || mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c2)).creatureLink != "")) {
							paths.push_back(paths.at(i));
							paths.at(paths.size() - 1).from = 5;
							paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c2);
						}

						if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c1)) != -1) && (mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c1)).isUnpassable == false || mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c1)).creatureLink != "")) {
							paths.at(i).from = 4;
							paths.at(i).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c1);
						}

					}
					else if (paths.at(i).from == 5) {
						if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c1)) != -1) && (mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c1)).isUnpassable == false || mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c1)).creatureLink != "")) {
							paths.push_back(paths.at(i));
							paths.at(paths.size() - 1).from = 4;
							paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c1);
						}
						if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c3)) != -1) && (mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c3)).isUnpassable == false || mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c3)).creatureLink != "")) {
							paths.push_back(paths.at(i));
							paths.at(paths.size() - 1).from = 6;
							paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c3);
						}
						if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c2)) != -1) && (mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c2)).isUnpassable == false || mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c2)).creatureLink != "")) {
							paths.at(i).from = 5;
							paths.at(i).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c2);
						}
					}
					else if (paths.at(i).from == 6) {
						if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c2)) != -1) && (mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c2)).isUnpassable == false || mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c2)).creatureLink != "")) {
							paths.push_back(paths.at(i));
							paths.at(paths.size() - 1).from = 5;
							paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c2);
						}
						if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c4)) != -1) && (mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c4)).isUnpassable == false || mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c4)).creatureLink != "")) {
							paths.push_back(paths.at(i));
							paths.at(paths.size() - 1).from = 1;
							paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c4);
						}
						if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c3)) != -1) && (mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c3)).isUnpassable == false || mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c3)).creatureLink != "")) {
							paths.at(i).from = 6;
							paths.at(i).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c3);
						}
					}
					else if (paths.at(i).from == 1) {
						if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c3)) != -1) && (mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c3)).isUnpassable == false || mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c3)).creatureLink != "")) {
							paths.push_back(paths.at(i));
							paths.at(paths.size() - 1).from = 6;
							paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c3);
						}
						if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c5)) != -1) && (mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c5)).isUnpassable == false || mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c5)).creatureLink != "")) {
							paths.push_back(paths.at(i));
							paths.at(paths.size() - 1).from = 2;
							paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c5);
						}
						if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c4)) != -1) && (mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c4)).isUnpassable == false || mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c4)).creatureLink != "")) {
							paths.at(i).from = 1;
							paths.at(i).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c4);
						}
					}
					else if (paths.at(i).from == 2) {
						if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c4)) != -1) && (mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c4)).isUnpassable == false || mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c4)).creatureLink != "")) {
							paths.push_back(paths.at(i));
							paths.at(paths.size() - 1).from = 1;
							paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c4);
						}
						if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c6)) != -1) && (mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c6)).isUnpassable == false || mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c6)).creatureLink != "")) {

							paths.push_back(paths.at(i));
							paths.at(paths.size() - 1).from = 3;
							paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c6);
						}
						if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c5)) != -1) && (mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c5)).isUnpassable == false || mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c5)).creatureLink != "")) {
							paths.at(i).from = 2;
							paths.at(i).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c5);
						}
					}
					else if (paths.at(i).from == 3) {
						if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c5)) != -1) && (mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c5)).isUnpassable == false || mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c5)).creatureLink != "")) {
							paths.push_back(paths.at(i));
							paths.at(paths.size() - 1).from = 2;
							paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c5);
						}
						if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c1)) != -1) && (mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c1)).isUnpassable == false || mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c1)).creatureLink != "")) {
							paths.push_back(paths.at(i));
							paths.at(paths.size() - 1).from = 4;
							paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c1);
						}
						if ((((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c6)) != -1) && (mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c6)).isUnpassable == false || mapTiles->at((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c6)).creatureLink != "")) {
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

}