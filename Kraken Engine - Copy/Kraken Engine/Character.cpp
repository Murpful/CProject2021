#include "Character.h"

void Character::playCard() {
	if (!weakened) {
		//action here based on user choice
		
		
	}
}
Character::Character(std::string setClassName) {
	if (setClassName == "Brute")
	{
		className = setClassName;
		maxHP = 25;
		currentHP = maxHP;
		inventorySize = 25;
		loc = 1;
		iFrame = 0; weakened = 0;
		for (int counter = 0; counter < inventorySize; counter++) {
			deck.push_back("atk", {}, image);

		}
	}
	if (setClassName == "Knight")
	{
		className = setClassName;
		maxHP = 20;
		currentHP = maxHP;
		inventorySize = 20;
		loc = 2;
		iFrame = 0; weakened = 0;
	}

}
