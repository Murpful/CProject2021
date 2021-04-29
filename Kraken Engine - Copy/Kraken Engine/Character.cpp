#include "Character.h"
bool Character::isWeakened()
{
	return weakened;
}
int Character::getHealth()
{
	return health;
}
int Character::getMaxHP()
{
	return maxHP;
}
int Character::getLoc()
{
	return loc;
}
int Character::getInventorySize()
{
	return inventorySize;
}
std::string Character::getClassName()
{
	return className;
}
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
		health = maxHP;
		inventorySize = 25;
		loc = 1;
	}
	if (setClassName == "Knight")
	{
		className = setClassName;
		maxHP = 20;
		health = maxHP;
		inventorySize = 20;
		loc = 2;
	}

}
