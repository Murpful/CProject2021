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
		std::vector<battleMapTile>* currentLoc;
		bool weakened, iFrame;
		bool isAttacking, isMoving;
		PlayerCard selectedCard;
		std::vector<PlayerCard> deck;
		std::vector<PlayerCard> hand;
		std::vector<Attack> attackQueue;
		std::vector<Move> moveQueue;
		Character(std::vector<battleMapTile>* map, ObjectDataBase* dataBase, std::string, int);
		Character();
		void playCard();
		void updateTurn();
};

