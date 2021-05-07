#pragma once
#include<string>
#include<vector>
#include"PlayerCard.h"
#include"battleMapTile.h"
#include"Attack.h"
#include"Move.h"
#include "ObjectDataBase.h"
#include "Creature.h"

class Character
{
	public:
		std::string objLink;
		ObjectDataBase* allObjects;
		std::vector<battleMapTile>* mapTiles;
		std::string className;
		int currentHP, maxHP, inventorySize, loc, targetLoc;
		int moveLoc;
		std::vector<battleMapTile>* currentLoc;
		bool weakened, iFrame;
		bool isAttacking, isMoving;
		PlayerCard selectedCard;
		std::vector<PlayerCard> deck;
		std::vector<PlayerCard> hand;
		std::vector<PlayerCard> discard;
		std::vector<Attack> attackQueue;
		std::vector<Move> moveQueue;
		std::vector<Creature>* creatures;
		std::vector<cardAction> pick;
		int goalx;
		int goaly;
		bool goalSet;
		int halfGoal;
		std::vector<int> pathWeave;
		Character(std::vector<battleMapTile>* map, ObjectDataBase* dataBase, std::vector<Creature>* creat, std::string, int);
		Character();
		void playCard();
		void updateTurn();
		void path();
};

