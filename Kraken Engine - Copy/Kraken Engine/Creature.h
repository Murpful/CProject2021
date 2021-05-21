#pragma once
#include "PlayerCard.h"
#include "battleMapTile.h"
#include "ObjectDataBase.h"
#include "Component.h"
#include "Attack.h"
#include "Move.h"
enum entityFaction
{
	player, monster
};
class Creature
{
public:
	std::string name;



	int halfGoal;
	std::vector<PlayerCard> cardsReady;
	std::vector<PlayerCard> cardsUsed;
	int maxHealthPoints;
	int currentHealthPoints;
	int coolDown;
	int connect;
	int check;
	int currentTile;
	int moveDest;
	int armorStat;
	bool pierceable;
	int fazes;
	std::vector<Move> moveStat;
	std::vector<Attack> attackStat;
	ObjectDataBase* allObjects;
	std::vector<battleMapTile>* mapTiles;
	bool moving;
	std::vector<int> pathWeave;
	std::string linkID;
	bool killed;
	int goalx;
	int goaly;
	bool goalSet;
	int rangeCount;
	entityFaction faction;
	bool omniTileCheck(int tileNumber, bool impasable, bool character, bool enemy, bool null);
	Creature(std::vector<battleMapTile>*, ObjectDataBase*, std::string, std::string, entityFaction, int, std::vector<PlayerCard>);
	Creature(std::vector<battleMapTile>*, ObjectDataBase*, std::string, int, std::vector<Component>);//{Component(attack,{1,1})}
	void runTurn();
	void path();
	int checkTilesChar(int);
	int checkTilesChar(int,int&,std::vector<int>&);
	void moveRandom();
};
class Path {
public:
	std::vector<int> weave;
	int from;
	Path(std::vector<int>, int);
	bool pure = true;
};



