#pragma once
#include<string>
#include<vector>
#include"CardType.h"
class Character
{
	protected:
		std::string className;
		int health, loc, inventorySize, maxHP, targetLoc;
		bool weakened;
		std::vector<CardType> deck;
		Character(std::string);

	public:
		bool isWeakened();
		int getHealth();
		int getMaxHP();
		int getLoc();
		int getInventorySize();
		std::string getClassName();
		void playCard();
};

