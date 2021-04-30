#pragma once
#include<string>
#include<vector>
#include"PlayerCard.h"
#include"battleMapTile.h"
#include"Attack.h"
#include"Move.h"
class Character
{
	public:
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
		Character(std::string);
		void playCard();
		void updateTurn();
};

