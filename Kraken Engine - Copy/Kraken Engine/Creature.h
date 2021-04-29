#pragma once
#include "PlayerCard.h"
#include "battleMapTile.h"
#include "ObjectDataBase.h"
enum entityFaction
{
	player,monster
};
class Creature
{
public:
	std::vector<PlayerCard> cardsReady;
	std::vector<PlayerCard> cardsUsed;
	int maxHealthPoints;
	int currentHealthPoints;
	int coolDown;
	int currentTile;
	int moveDest;
	ObjectDataBase* allObjects;
	std::vector<battleMapTile>* mapTiles;
	bool moving;
	std::vector<int> pathWeave;
	std::string linkID;
	int goalx;
	int goaly;
	bool goalSet;
	
	entityFaction faction;
	Creature(std::vector<battleMapTile>*,ObjectDataBase*);
	void runTurn();
	void path();
};
class Path {
public:
	std::vector<int> weave;
	int from;
	Path(std::vector<int>, int);
};

