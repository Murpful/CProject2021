#include "Character.h"

void Character::playCard() {
	for (int i = 0; i < selectedCard.cardEvents.size(); i++)
	{
		if (selectedCard.cardEvents.at(i).action == attack) {
			attackQueue.push_back(Attack(selectedCard.cardEvents.at(i).data.at(0), selectedCard.cardEvents.at(i).data.at(1)));
		}
		if (selectedCard.cardEvents.at(i).action == move) {
			moveQueue.push_back(Move(selectedCard.cardEvents.at(i).data.at(0), selectedCard.cardEvents.at(i).data.at(1)));
		}
		
	}
	
}
void Character::updateTurn() {
	if (attackQueue.size() > 0 &&!isAttacking && !isMoving) {
		isAttacking = true;
	}
	if (isAttacking) {

	}
	if (moveQueue.size() > 0 && !isMoving && !isAttacking) {
		isMoving = true;
	}
	if (isMoving) {

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
		for (int counter = 0; counter < inventorySize/2; counter++) {
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
		loc = 2;
		iFrame = 0; weakened = 0;
	}

}
