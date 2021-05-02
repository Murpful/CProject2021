#include "Character.h"
int selectedTile;
void selectTile(int inf) {
	selectedTile = inf;
	std::cout << "info: " << inf << "    ";
}


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
	
	if (attackQueue.size() > 0 && !isAttacking && !isMoving) {
		isAttacking = true;
		int startingTileOfCreation = mapTiles->at(loc).c1;
		for (int i = 0; i < attackQueue.at(0).range; i++)
		{
			
			std::string firstTileLink = "tile" + std::to_string(startingTileOfCreation);
			allObjects->addObject(new AdvancedButtonObject("targetButton", "assets/RegHexBaseTarget.png",&selectTile, allObjects->getDetailObject(firstTileLink)->xPos, allObjects->getDetailObject(firstTileLink)->yPos, 110, 96, startingTileOfCreation));
			for (int k = 0; k < i+1; k++)
			{
				startingTileOfCreation = mapTiles->at(startingTileOfCreation).c3;
				firstTileLink = "tile" + std::to_string(startingTileOfCreation);
				allObjects->addObject(new AdvancedButtonObject("targetButton", "assets/RegHexBaseTarget.png", &selectTile, allObjects->getDetailObject(firstTileLink)->xPos, allObjects->getDetailObject(firstTileLink)->yPos, 110, 96, startingTileOfCreation));
			}
			for (int k = 0; k < i + 1; k++)
			{
				startingTileOfCreation = mapTiles->at(startingTileOfCreation).c4;
				firstTileLink = "tile" + std::to_string(startingTileOfCreation);
				allObjects->addObject(new AdvancedButtonObject("targetButton", "assets/RegHexBaseTarget.png", &selectTile, allObjects->getDetailObject(firstTileLink)->xPos, allObjects->getDetailObject(firstTileLink)->yPos, 110, 96, startingTileOfCreation));
			}
			for (int k = 0; k < i + 1; k++)
			{
				startingTileOfCreation = mapTiles->at(startingTileOfCreation).c5;
				firstTileLink = "tile" + std::to_string(startingTileOfCreation);
				allObjects->addObject(new AdvancedButtonObject("targetButton", "assets/RegHexBaseTarget.png", &selectTile, allObjects->getDetailObject(firstTileLink)->xPos, allObjects->getDetailObject(firstTileLink)->yPos, 110, 96, startingTileOfCreation));
			}
			for (int k = 0; k < i + 1; k++)
			{
				startingTileOfCreation = mapTiles->at(startingTileOfCreation).c6;
				firstTileLink = "tile" + std::to_string(startingTileOfCreation);
				allObjects->addObject(new AdvancedButtonObject("targetButton", "assets/RegHexBaseTarget.png", &selectTile, allObjects->getDetailObject(firstTileLink)->xPos, allObjects->getDetailObject(firstTileLink)->yPos, 110, 96, startingTileOfCreation));
			}
			for (int k = 0; k < i + 1; k++)
			{
				startingTileOfCreation = mapTiles->at(startingTileOfCreation).c1;
				firstTileLink = "tile" + std::to_string(startingTileOfCreation);
				allObjects->addObject(new AdvancedButtonObject("targetButton", "assets/RegHexBaseTarget.png", &selectTile, allObjects->getDetailObject(firstTileLink)->xPos, allObjects->getDetailObject(firstTileLink)->yPos, 110, 96, startingTileOfCreation));
			}
			for (int k = 0; k < i; k++)
			{
				startingTileOfCreation = mapTiles->at(startingTileOfCreation).c2;
				firstTileLink = "tile" + std::to_string(startingTileOfCreation);
				allObjects->addObject(new AdvancedButtonObject("targetButton", "assets/RegHexBaseTarget.png", &selectTile, allObjects->getDetailObject(firstTileLink)->xPos, allObjects->getDetailObject(firstTileLink)->yPos, 110, 96, startingTileOfCreation));
			}
			startingTileOfCreation = (startingTileOfCreation + 1);
			
		}
	}
	if (isAttacking) {

	}
	if (moveQueue.size() > 0 && !isMoving && !isAttacking) {
		isMoving = true;
	}
	if (isMoving) {

	}
}
Character::Character() {

}
Character::Character(std::vector<battleMapTile>* map, ObjectDataBase* dataBase, std::string setClassName, int startingTile) {
	isAttacking = false;
	isMoving = false;
	attackQueue.push_back(Attack(1, 2));
	loc = startingTile;
	allObjects = dataBase;
	mapTiles = map;
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
