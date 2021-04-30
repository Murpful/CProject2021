#pragma once
#include<string>
#include<vector>
#include"PlayerCard.h"
#include"battleMapTile.h"
class Character
{
	public:
		std::string className;
		int currentHP, maxHP, inventorySize, loc, targetLoc;
		std::vector<battleMapTile>* currentLoc;
		bool weakened, iFrame;
		std::vector<PlayerCard> deck;
		std::vector<PlayerCard> hand;
		Character(std::string);
		void playCard();
};

