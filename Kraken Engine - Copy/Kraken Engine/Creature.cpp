#include "Creature.h"
Path::Path(std::vector<int> w, int p) {
	weave = w;
	from = p;
}
Creature::Creature(std::vector<battleMapTile>* map, ObjectDataBase* dataBase, std::string named, std::string linkedid, entityFaction fact, int tile, std::vector<PlayerCard> cards) {
	maxHealthPoints = 5;
	halfGoal = 0;
	currentHealthPoints = 5;
	faction = monster;
	coolDown = 100;
	cardsUsed = { };
	currentTile = 0;
	moveDest = -1;
	mapTiles = map;
	map->at(tile).creatureLink = named;
	moving = false;
	pathWeave = { };
	allObjects = dataBase;
	std::string objectTag = "tile" + std::to_string(tile);
	std::cout << objectTag << " ";
	goalx = allObjects->getDetailObject(objectTag)->xPos + 20;
	goaly = allObjects->getDetailObject(objectTag)->yPos + 20;
	allObjects->getDetailObject(linkedid)->xPos = goalx;
	allObjects->getDetailObject(linkedid)->yPos = goaly;
	goalSet = false;
	name = named;
	linkID = linkedid;
	currentTile = tile;
	faction = fact;
	cardsReady = cards;
	killed = false;

}
Creature::Creature(std::vector<battleMapTile>* map, ObjectDataBase* dataBase, std::string named, int tile, std::vector<Component> creatureStats)
{
	moveDest = -1;
	mapTiles = map;
	map->at(tile).creatureLink = named;
	moving = false;
	pathWeave = { };
	allObjects = dataBase;
	std::string objectTag = "tile" + std::to_string(tile);
	std::cout << objectTag << " ";
	goalx = allObjects->getDetailObject(objectTag)->xPos + 20;
	goaly = allObjects->getDetailObject(objectTag)->yPos + 20;
	allObjects->getDetailObject(named)->xPos = goalx;
	allObjects->getDetailObject(named)->yPos = goaly;
	goalSet = false;
	name = named;
	linkID = name;
	currentTile = tile;
	killed = false;
	maxHealthPoints = 0;
	currentHealthPoints = 0;
	armorStat = 0;
	pierceable = 1;
	fazes = 0;
	coolDown = 100;
	rangeCount = 0;
	//Attack newStat = Attack(0, 0);
	//attackStat.push_back(newStat);
	//Move newStat2 = Move(0, 0);
	//moveStat.push_back(newStat2);
	for (int i = 0; i < creatureStats.size(); i++)
	{
		if (creatureStats.at(i).witch == attackType)
		{
			Attack newStat = Attack(creatureStats.at(i).value.at(0), creatureStats.at(i).value.at(1));
			attackStat.push_back(newStat);
		}
		if (creatureStats.at(i).witch == health)
		{
			if (creatureStats.at(i).value.size() > 1)
			{
				currentHealthPoints = creatureStats.at(i).value.at(0);
				maxHealthPoints = creatureStats.at(i).value.at(1);
			}
			else
			{
				currentHealthPoints = creatureStats.at(i).value.at(0);
				maxHealthPoints = creatureStats.at(i).value.at(0);
			}
		}
		if (creatureStats.at(i).witch == moveStats)
		{
			if (creatureStats.at(i).value.size() > 2) {
				Move newStat(creatureStats.at(i).value.at(0), creatureStats.at(i).value.at(1), creatureStats.at(i).crtrMvmt, creatureStats.at(i).value.at(2));
				moveStat.push_back(newStat);
			}
			else {
				Move newStat(creatureStats.at(i).value.at(0), creatureStats.at(i).value.at(1), creatureStats.at(i).crtrMvmt);
				moveStat.push_back(newStat);
			}


		}
		if (creatureStats.at(i).witch == faze)
		{
			fazes = creatureStats.at(i).value.at(0);
		}
		if (creatureStats.at(i).witch == armor)
		{
			armorStat = creatureStats.at(i).value.at(0);
			std::cout << "armorvalue: " << creatureStats.at(i).value.at(0) << std::endl;
			if (creatureStats.at(i).value.size() > 1)
			{
				pierceable = static_cast<bool>(creatureStats.at(i).value.at(1));
			}
		}
	}
	std::cout << "armor: " << armorStat << std::endl;

}
void Creature::moveRandom()
{
	int currentloc = currentTile;
	int randDirection = rand() % 6;
	std::cout << "rnge " << moveStat.at(0).range << std::endl;
	for (int k = 0; k < moveStat.at(0).range; k++)
	{

		//std::cout << "    Current loc at loop start: " << currentloc << "   ";
		std::cout << "move attempt" << std::endl;
		if (randDirection == 0) {
			if (mapTiles->at(currentloc).c1 == -1 || mapTiles->at(mapTiles->at(currentloc).c1).isUnpassable == true) {
				k--;
				moveDest = currentloc;
			}
			else {
				moveDest = mapTiles->at(currentloc).c1;

			}
		}
		else if (randDirection == 1) {
			if (mapTiles->at(currentloc).c2 == -1 || mapTiles->at(mapTiles->at(currentloc).c2).isUnpassable == true) {
				k--;
				moveDest = currentloc;
			}
			else {
				moveDest = mapTiles->at(currentloc).c2;

			}

		}
		else if (randDirection == 2) {
			if (mapTiles->at(currentloc).c3 == -1 || mapTiles->at(mapTiles->at(currentloc).c3).isUnpassable == true) {
				k--;
				moveDest = currentloc;
			}
			else {
				moveDest = mapTiles->at(currentloc).c3;

			}

		}
		else if (randDirection == 3) {
			if (mapTiles->at(currentloc).c4 == -1 || mapTiles->at(mapTiles->at(currentloc).c4).isUnpassable == true) {
				k--;
				moveDest = currentloc;
			}
			else {
				moveDest = mapTiles->at(currentloc).c4;

			}

		}
		else if (randDirection == 4) {
			if (mapTiles->at(currentloc).c5 == -1 || mapTiles->at(mapTiles->at(currentloc).c5).isUnpassable == true) {
				k--;
				moveDest = currentloc;
			}
			else {
				moveDest = mapTiles->at(currentloc).c5;

			}

		}
		else if (randDirection == 5) {
			if (mapTiles->at(currentloc).c6 == -1 || mapTiles->at(mapTiles->at(currentloc).c6).isUnpassable == true) {
				k--;
				moveDest = currentloc;
			}
			else {
				moveDest = mapTiles->at(currentloc).c6;

			}

		}
		//std::cout << "    Move destination is currently set to: " << moveDest << "     ";
		std::cout << "k: " << k << std::endl;
		currentloc = moveDest;
		if (rand() % 5 == 0) {
			randDirection = rand() % 6;
		}

	}
	//std::cout << "   Selecting Destination of: " << moveDest << "  ";
	if (currentTile != moveDest) {
		moving = true;
		int randTime = rand() % 500;
		coolDown = 100 + (randTime / moveStat.at(0).speed);
	}

}
int Creature::checkTilesChar(int testTile)
{
	std::cout << "checking tiles..." << std::endl;
	int testDest = testTile;
	if (mapTiles->at(testDest).c1 != -1 && mapTiles->at(mapTiles->at(testDest).c1).characterLink != "")
	{
		std::cout << "returning 1, link: " << mapTiles->at(mapTiles->at(testDest).c1).characterLink << std::endl;
		rangeCount++;
		return mapTiles->at(testDest).c1;
	}
	else if (mapTiles->at(testDest).c2 != -1 && mapTiles->at(mapTiles->at(testDest).c2).characterLink != "")
	{
		std::cout << "returning 2, link: " << mapTiles->at(mapTiles->at(testDest).c2).characterLink << std::endl;
		rangeCount++;
		return mapTiles->at(testDest).c2;
	}
	else if (mapTiles->at(testDest).c3 != -1 && mapTiles->at(mapTiles->at(testDest).c3).characterLink != "")
	{
		std::cout << "returning 3, link: " << mapTiles->at(mapTiles->at(testDest).c3).characterLink << std::endl;
		rangeCount++;
		return mapTiles->at(testDest).c3;
	}
	else if (mapTiles->at(testDest).c4 != -1 && mapTiles->at(mapTiles->at(testDest).c4).characterLink != "")
	{
		std::cout << "returning 4, link: " << mapTiles->at(mapTiles->at(testDest).c4).characterLink << std::endl;
		rangeCount++;
		return mapTiles->at(testDest).c4;
	
	}
	else if (mapTiles->at(testDest).c5 != -1 && mapTiles->at(mapTiles->at(testDest).c5).characterLink != "")
	{
		std::cout << "returning 5, link: " << mapTiles->at(mapTiles->at(testDest).c5).characterLink << std::endl;
		rangeCount++;
		return mapTiles->at(testDest).c5;
		
	}
	else if (mapTiles->at(testDest).c6 != -1 && mapTiles->at(mapTiles->at(testDest).c6).characterLink != "")
	{
		std::cout << "returning 6, link: " << mapTiles->at(mapTiles->at(testDest).c6).characterLink << std::endl;
		rangeCount++;
		return mapTiles->at(testDest).c6;
		
	}
	std::cout << "rangecount: " << rangeCount << "  range: " << moveStat.at(0).range << std::endl;
	std::cout << "move stat size: " << moveStat.size();
	if (rangeCount < moveStat.at(0).range)
	{
		std::cout << "enterrangeif" << std::endl;
		rangeCount++;
		std::cout << "rangecount: " << rangeCount << std::endl;
		int tile1 = -1, tile2 = -1, tile3 = -1, tile4 = -1, tile5 = -1, tile6 = -1;
		if (mapTiles->at(testDest).c1 != -1 && (mapTiles->at(mapTiles->at(testDest).c1).isUnpassable == false || mapTiles->at(mapTiles->at(testDest).c1).characterLink !=""))
		{
			std::cout << 1 << std::endl;
			tile1 = checkTilesChar(mapTiles->at(testDest).c1);
			rangeCount--;
			if (tile1 != -1)
			{
				std::cout << "tile found: " << tile1 << std::endl;
				return tile1;
			}
		}

		if (mapTiles->at(testDest).c2 != -1 && (mapTiles->at(mapTiles->at(testDest).c2).isUnpassable == false || mapTiles->at(mapTiles->at(testDest).c2).characterLink != ""))
		{
			std::cout << 2 << std::endl;
			tile2 = checkTilesChar(mapTiles->at(testDest).c2);
			rangeCount--;
			if (tile2 != -1)
			{
				std::cout << "tile found: " << tile2 << std::endl;
				return tile2;
			}
		}

		if (mapTiles->at(testDest).c3 != -1 && (mapTiles->at(mapTiles->at(testDest).c3).isUnpassable == false || mapTiles->at(mapTiles->at(testDest).c3).characterLink != ""))
		{
			std::cout << 3 << std::endl;
			tile3 = checkTilesChar(mapTiles->at(testDest).c3);
			rangeCount--;
			if (tile3 != -1)
			{
				std::cout << "tile found: " << tile3 << std::endl;
				return tile3;
			}
		}

		if (mapTiles->at(testDest).c4 != -1 && (mapTiles->at(mapTiles->at(testDest).c4).isUnpassable == false || mapTiles->at(mapTiles->at(testDest).c4).characterLink != ""))
		{
			std::cout << 4 << std::endl;
			tile4 = checkTilesChar(mapTiles->at(testDest).c4);
			rangeCount--;
			if (tile4 != -1)
			{
				std::cout << "tile found: " << tile4 << std::endl;
				return tile4;
			}
		}

		if (mapTiles->at(testDest).c5 != -1 && (mapTiles->at(mapTiles->at(testDest).c5).isUnpassable == false || mapTiles->at(mapTiles->at(testDest).c5).characterLink != ""))
		{
			std::cout << 5 << std::endl;
			tile5 = checkTilesChar(mapTiles->at(testDest).c5);
			rangeCount--;
			if (tile5 != -1)
			{
				std::cout << "tile found: " << tile5 << std::endl;
				return tile5;
			}
		}

		if (mapTiles->at(testDest).c6 != -1 && (mapTiles->at(mapTiles->at(testDest).c6).isUnpassable == false || mapTiles->at(mapTiles->at(testDest).c6).characterLink != ""))
		{
			std::cout << 6 << std::endl;
			tile6 = checkTilesChar(mapTiles->at(testDest).c6);
			rangeCount--;
			if (tile6 != -1)
			{
				std::cout << "tile found: " << tile6 << std::endl;
				return tile6;
			}
		}

		std::cout << "tiles: " << tile1 << tile2 << tile3 << tile4 << tile5 << tile6 << std::endl;
		return -1;
	}
	else
	{
		rangeCount++;
		return -1;
	}

}
int Creature::checkTilesChar(int testTile, int &distanceFrom, std::vector<int> &prevmoves)
{
	std::cout << "checking tiles..." << std::endl;
	int testDest = testTile;
	if (mapTiles->at(testDest).c1 != -1 && mapTiles->at(mapTiles->at(testDest).c1).characterLink != "")
	{
		prevmoves.push_back(1);
		std::cout << "returning 1, link: " << mapTiles->at(mapTiles->at(testDest).c1).characterLink << std::endl;
		distanceFrom = rangeCount+1;
		if (distanceFrom < moveStat.at(0).minDist) {
			distanceFrom = (distanceFrom - moveStat.at(0).minDist);
		}
		else {
			rangeCount++;
		}
		return mapTiles->at(testDest).c1;
		
	}
	else if (mapTiles->at(testDest).c2 != -1 && mapTiles->at(mapTiles->at(testDest).c2).characterLink != "")
	{
		prevmoves.push_back(2);
		std::cout << "returning 2, link: " << mapTiles->at(mapTiles->at(testDest).c2).characterLink << std::endl;
		distanceFrom = rangeCount + 1;
		if (distanceFrom < moveStat.at(0).minDist) {
			distanceFrom = (distanceFrom - moveStat.at(0).minDist);
		}
		else {
			rangeCount++;
		}
		return mapTiles->at(testDest).c2;
	}
	else if (mapTiles->at(testDest).c3 != -1 && mapTiles->at(mapTiles->at(testDest).c3).characterLink != "")
	{
		prevmoves.push_back(3);
		std::cout << "returning 3, link: " << mapTiles->at(mapTiles->at(testDest).c3).characterLink << std::endl;
		distanceFrom = rangeCount + 1;
		if (distanceFrom < moveStat.at(0).minDist) {
			distanceFrom = (distanceFrom - moveStat.at(0).minDist);
		}
		else {
			rangeCount++;
		}
		return mapTiles->at(testDest).c3;
	}
	else if (mapTiles->at(testDest).c4 != -1 && mapTiles->at(mapTiles->at(testDest).c4).characterLink != "")
	{
		prevmoves.push_back(4);
		std::cout << "returning 4, link: " << mapTiles->at(mapTiles->at(testDest).c4).characterLink << std::endl;
		distanceFrom = rangeCount + 1;
		if (distanceFrom < moveStat.at(0).minDist) {
			distanceFrom = (distanceFrom - moveStat.at(0).minDist);
		}
		else {
			rangeCount++;
		}
		return mapTiles->at(testDest).c4;

	}
	else if (mapTiles->at(testDest).c5 != -1 && mapTiles->at(mapTiles->at(testDest).c5).characterLink != "")
	{
		prevmoves.push_back(5);
		std::cout << "returning 5, link: " << mapTiles->at(mapTiles->at(testDest).c5).characterLink << std::endl;
		distanceFrom = rangeCount + 1;
		if (distanceFrom < moveStat.at(0).minDist) {
			distanceFrom = (distanceFrom - moveStat.at(0).minDist);
		}
		else {
			rangeCount++;
		}
		return mapTiles->at(testDest).c5;

	}
	else if (mapTiles->at(testDest).c6 != -1 && mapTiles->at(mapTiles->at(testDest).c6).characterLink != "")
	{
		prevmoves.push_back(6);
		std::cout << "returning 6, link: " << mapTiles->at(mapTiles->at(testDest).c6).characterLink << std::endl;
		distanceFrom = rangeCount + 1;
		if (distanceFrom < moveStat.at(0).minDist) {
			distanceFrom = (distanceFrom - moveStat.at(0).minDist);
		}
		else {
			rangeCount++;
		}
		return mapTiles->at(testDest).c6;

	}
	std::cout << "rangecount: " << rangeCount << "  range: " << moveStat.at(0).range << std::endl;
	std::cout << "move stat size: " << moveStat.size();
	if (rangeCount < moveStat.at(0).range)
	{
		std::cout << "enterrangeif" << std::endl;
		rangeCount++;
		//std::cout << "rangecount: " << rangeCount << std::endl;
		int tile1 = -1, tile2 = -1, tile3 = -1, tile4 = -1, tile5 = -1, tile6 = -1;
		if (mapTiles->at(testDest).c1 != -1 && (mapTiles->at(mapTiles->at(testDest).c1).isUnpassable == false || mapTiles->at(mapTiles->at(testDest).c1).characterLink != ""))
		{
			std::cout << 1 << std::endl;
			prevmoves.push_back(1);
			tile1 = checkTilesChar(mapTiles->at(testDest).c1,distanceFrom,prevmoves);
			if (tile1 != -1)
			{
				std::cout << "tile found: " << tile1 << std::endl;
				return tile1;
			}
			else {
				prevmoves.erase(prevmoves.begin() + (prevmoves.size() - 1));
				rangeCount--;
			}
		}

		if (mapTiles->at(testDest).c2 != -1 && (mapTiles->at(mapTiles->at(testDest).c2).isUnpassable == false || mapTiles->at(mapTiles->at(testDest).c2).characterLink != ""))
		{
			std::cout << 2 << std::endl;
			prevmoves.push_back(2);
			tile2 = checkTilesChar(mapTiles->at(testDest).c2, distanceFrom, prevmoves);
			if (tile2 != -1)
			{
				std::cout << "tile found: " << tile2 << std::endl;
				return tile2;
			}
			else {
				prevmoves.erase(prevmoves.begin() + (prevmoves.size() - 1));
				rangeCount--;
			}
		}

		if (mapTiles->at(testDest).c3 != -1 && (mapTiles->at(mapTiles->at(testDest).c3).isUnpassable == false || mapTiles->at(mapTiles->at(testDest).c3).characterLink != ""))
		{
			prevmoves.push_back(3);
			std::cout << 3 << std::endl;
			tile3 = checkTilesChar(mapTiles->at(testDest).c3, distanceFrom, prevmoves);
			if (tile3 != -1)
			{
				std::cout << "tile found: " << tile3 << std::endl;
				return tile3;
			}
			else {
				prevmoves.erase(prevmoves.begin() + (prevmoves.size() - 1));
				rangeCount--;
			}
		}

		if (mapTiles->at(testDest).c4 != -1 && (mapTiles->at(mapTiles->at(testDest).c4).isUnpassable == false || mapTiles->at(mapTiles->at(testDest).c4).characterLink != ""))
		{
			std::cout << 4 << std::endl;
			prevmoves.push_back(4);
			tile4 = checkTilesChar(mapTiles->at(testDest).c4, distanceFrom, prevmoves);
			
			if (tile4 != -1)
			{
				std::cout << "tile found: " << tile4 << std::endl;
				return tile4;
			}
			else {
				prevmoves.erase(prevmoves.begin() + (prevmoves.size() - 1));
				rangeCount--;
			}
		}

		if (mapTiles->at(testDest).c5 != -1 && (mapTiles->at(mapTiles->at(testDest).c5).isUnpassable == false || mapTiles->at(mapTiles->at(testDest).c5).characterLink != ""))
		{
			std::cout << 5 << std::endl;
			prevmoves.push_back(5);
			tile5 = checkTilesChar(mapTiles->at(testDest).c5, distanceFrom, prevmoves);
			if (tile5 != -1)
			{
				std::cout << "tile found: " << tile5 << std::endl;
				return tile5;
			}
			else {
				prevmoves.erase(prevmoves.begin() + (prevmoves.size() - 1));
				rangeCount--;
			}
		}

		if (mapTiles->at(testDest).c6 != -1 && (mapTiles->at(mapTiles->at(testDest).c6).isUnpassable == false || mapTiles->at(mapTiles->at(testDest).c6).characterLink != ""))
		{
			std::cout << 6 << std::endl;
			prevmoves.push_back(6);
			tile6 = checkTilesChar(mapTiles->at(testDest).c6, distanceFrom, prevmoves);
			if (tile6 != -1)
			{
				std::cout << "tile found: " << tile6 << std::endl;
				return tile6;
			}
			else {
				prevmoves.erase(prevmoves.begin() + (prevmoves.size() - 1));
				rangeCount--;
			}
		}

		std::cout << "tiles: " << tile1 << tile2 << tile3 << tile4 << tile5 << tile6 << std::endl;
		return -1;
	}
	else
	{
		rangeCount++;
		std::cout << "The current rage away is this: " << rangeCount;
		return -1;
	}

}





void Creature::runTurn() {
	//std::cout << "remaining actions: " << cardsReady.size();
	if (currentHealthPoints <= 0) {
		killed = true;
	}
	std::cout << "cd: " << coolDown;
	if (moving) {
		std::cout << "here? moving" << std::endl;
		if (goalSet == false) {
			std::cout << "here? goalset" << std::endl;
			if (pathWeave.size() == 0) {
				//std::cout << "Destintation: " << moveDest << "   ";
				std::cout << "here? path start" << std::endl;
				path();
				std::cout << "here? path end" << std::endl;
			}

			if (mapTiles->at(currentTile).c1 == pathWeave.at(0)) {
				goaly -= 96;
			}
			else if (mapTiles->at(currentTile).c2 == pathWeave.at(0)) {
				goaly -= 48;
				goalx += 83;
			}
			else if (mapTiles->at(currentTile).c3 == pathWeave.at(0)) {
				goaly += 48;
				goalx += 83;
			}
			else if (mapTiles->at(currentTile).c4 == pathWeave.at(0)) {
				goaly += 96;
			}
			else if (mapTiles->at(currentTile).c5 == pathWeave.at(0)) {
				goaly += 48;
				goalx -= 83;
			}
			else if (mapTiles->at(currentTile).c6 == pathWeave.at(0)) {
				goaly -= 48;
				goalx -= 83;
			}
			goalSet = true;
		}
		else if (goalSet == true && mapTiles->at(pathWeave.at(0)).characterLink != "") {
			std::cout << "here? gs true" << std::endl;
			goalSet = false;
			halfGoal = 0;
			pathWeave = { };
			std::string objectTag = "tile" + std::to_string(currentTile);
			//std::cout << objectTag << " ";
			goalx = allObjects->getDetailObject(objectTag)->xPos + 30;
			goaly = allObjects->getDetailObject(objectTag)->yPos + 20;
			allObjects->getDetailObject(linkID)->xPos = goalx;
			allObjects->getDetailObject(linkID)->yPos = goaly;
			moving = false;
			pathWeave = { };
		}

		else {
			std::cout << "here? else" << std::endl;
			if (halfGoal == 0)
			{
				halfGoal = sqrt(pow(goalx - allObjects->getDetailObject(linkID)->xPos, 2) + pow(goaly - (allObjects->getDetailObject(linkID)->yPos), 2)) / 2;

			}
			int tilenumb = pathWeave.at(0);
			bool reached = true;
			bool half = false;
			//std::cout << "Goalx: " << goalx << "Goaly: " << goaly;
			//if (mapTiles->at(tilenumb).isUnpassable == false) {
			if (allObjects->getDetailObject(linkID)->yPos < goaly) {
				allObjects->getDetailObject(linkID)->moveObject(0, 1 * moveStat.at(0).speed);
				reached = false;
			}
			else if (allObjects->getDetailObject(linkID)->yPos > goaly) {
				allObjects->getDetailObject(linkID)->moveObject(0, (-1 * moveStat.at(0).speed));
				reached = false;
			}
			if (allObjects->getDetailObject(linkID)->xPos < goalx) {
				allObjects->getDetailObject(linkID)->moveObject(1 * moveStat.at(0).speed, 0);
				reached = false;
			}
			else if (allObjects->getDetailObject(linkID)->xPos > goalx) {
				allObjects->getDetailObject(linkID)->moveObject(-1 * moveStat.at(0).speed, 0);
				reached = false;
			}
			if (sqrt(pow(abs(goalx - allObjects->getDetailObject(linkID)->xPos), 2) + pow(abs(goaly - (allObjects->getDetailObject(linkID)->yPos)), 2)) >= halfGoal - 5 && sqrt(pow(abs(goalx - allObjects->getDetailObject(linkID)->xPos), 2) + pow(abs(goaly - (allObjects->getDetailObject(linkID)->yPos)), 2)) <= halfGoal + 5)
			{
				half = true;
			}
			if (half)
			{
				mapTiles->at(currentTile).isUnpassable = false;
				mapTiles->at(currentTile).creatureLink = "";
				currentTile = pathWeave.at(0);
				mapTiles->at(currentTile).creatureLink = name;
				mapTiles->at(currentTile).isUnpassable = true;
				halfGoal = -6;
				std::cout << "reached half" << std::endl;
			}
			if (reached) {
				pathWeave.erase(pathWeave.begin() + 0);
				goalSet = false;
				halfGoal = 0;
				std::cout << "reached full" << std::endl;
				if (pathWeave.size() == 0) {
					moving = false;
					pathWeave = { };
				}
				//std::cout << "New current tile: " << currentTile;
			}
			//}
			//else {
			// moving = false;
			// goalSet = false;
			//}

		}

	}

	else if (coolDown == 0) {
		std::cout << "here? cd0" << std::endl;
		if (mapTiles->size() > 0)
		{
			if (moveStat.size() > 0) {
				if (moveStat.at(0).movement == random)
				{
					moveRandom();
				}
				else if (moveStat.at(0).movement == toward)
				{
					rangeCount = 0;
					int distanceAway = 0;
					std::vector<int> prevmov;
					int moveAttempt = checkTilesChar(currentTile,distanceAway, prevmov);
					std::cout << "Player is " << distanceAway << " tiles away";
					std::cout << "moveattempt " << moveAttempt << std::endl;
					if (moveAttempt != -1 && distanceAway > 0)
					{
						std::cout << "lets move toward" << std::endl;
						moveDest = moveAttempt;
						for (int i = 0; i < moveStat.at(0).minDist - 1; i++)
						{
						
							int move = prevmov.at(prevmov.size() - 1);
							if (move == 1) {
								moveDest = mapTiles->at(moveDest).c4;
							}
							else if (move == 2) {

								moveDest = mapTiles->at(moveDest).c5;
							}
							else if (move == 3) {
								moveDest = mapTiles->at(moveDest).c6;
							}
							else if (move == 4) {
								moveDest = mapTiles->at(moveDest).c1;

							}
							else if (move == 5) {
								moveDest = mapTiles->at(moveDest).c2;

							}
							else if (move == 6) {
								moveDest = mapTiles->at(moveDest).c3;
							}
						}
						moving = true;
						coolDown = 100 + ((rand() % 500) / moveStat.at(0).speed);

					}
					else if (distanceAway < 0)
					{
						//std::cout << "lets move away" << std::endl;
						//moveDest = moveAttempt;
						//moving = true;
						//coolDown = 100 + ((rand() % 500) / moveStat.at(0).speed);
					}
					else
					{
						std::cout << "lets move random" << std::endl;
						moveRandom();
					}
				}
			}
			
		}
		/*if ((cardsReady.size() > 0) && mapTiles->size() > 0) {
		PlayerCard activeCard = cardsReady.at(0);
		cardsUsed.push_back(cardsReady.at(0));
		cardsReady.erase(cardsReady.begin() + 0);
		coolDown = activeCard.coolDown;
		for (int i = 0; i < activeCard.cardEvents.size(); i++)
		{
		if (activeCard.cardEvents.at(i).action == move) {
		if (activeCard.cardEvents.at(i).data.at(0) == 0) {
		int thisTile = currentTile;
		std::vector<int> targets = { };

		for (int i = 0; i < activeCard.cardEvents.at(i).data.at(1); i++)
		{
		thisTile = mapTiles->at(thisTile).c1;
		if (mapTiles->at(thisTile).isUnpassable == true) {
		targets.push_back(0); // add a new variable to tiles that stores who/what is in the tile at a given moment.
		}
		}

		moving = true;
		coolDown = 600;
		}
		else if (activeCard.cardEvents.at(i).data.at(0) == 1) {
		int currentloc = currentTile;
		int randDirection = rand() % 6;
		for (int k = 0; k < activeCard.cardEvents.at(i).data.at(1); k++)
		{
		//std::cout << "    Current loc at loop start: " << currentloc << "   ";

		if (randDirection == 0) {
		if (mapTiles->at(currentloc).c1 == -1 || mapTiles->at(mapTiles->at(currentloc).c1).isUnpassable == true) {
		k--;
		moveDest = currentloc;
		}
		else {
		moveDest = mapTiles->at(currentloc).c1;

		}
		}
		else if (randDirection == 1) {
		if (mapTiles->at(currentloc).c2 == -1 || mapTiles->at(mapTiles->at(currentloc).c2).isUnpassable == true) {
		k--;
		moveDest = currentloc;
		}
		else {
		moveDest = mapTiles->at(currentloc).c2;

		}

		}
		else if (randDirection == 2) {
		if (mapTiles->at(currentloc).c3 == -1 || mapTiles->at(mapTiles->at(currentloc).c3).isUnpassable == true) {
		k--;
		moveDest = currentloc;
		}
		else {
		moveDest = mapTiles->at(currentloc).c3;

		}

		}
		else if (randDirection == 3) {
		if (mapTiles->at(currentloc).c4 == -1 || mapTiles->at(mapTiles->at(currentloc).c4).isUnpassable == true) {
		k--;
		moveDest = currentloc;
		}
		else {
		moveDest = mapTiles->at(currentloc).c4;

		}

		}
		else if (randDirection == 4) {
		if (mapTiles->at(currentloc).c5 == -1 || mapTiles->at(mapTiles->at(currentloc).c5).isUnpassable == true) {
		k--;
		moveDest = currentloc;
		}
		else {
		moveDest = mapTiles->at(currentloc).c5;

		}

		}
		else if (randDirection == 5) {
		if (mapTiles->at(currentloc).c6 == -1 || mapTiles->at(mapTiles->at(currentloc).c6).isUnpassable == true) {
		k--;
		moveDest = currentloc;
		}
		else {
		moveDest = mapTiles->at(currentloc).c6;

		}

		}
		//std::cout << "    Move destination is currently set to: " << moveDest << "     ";
		currentloc = moveDest;
		if (rand() % 5 == 0) {
		randDirection = rand() % 6;
		}

		}
		//std::cout << "   Selecting Destination of: " << moveDest << "  ";
		if (currentTile != moveDest) {
		moving = true;
		}

		}
		}
		}
		}*/
	}
	if (coolDown>0) {
		std::cout << "here? cd++" << std::endl;
		/*if (cardsReady.size() < 1) {
			int size = cardsUsed.size();
			for (int i = 0; i < size; i++)
			{
				int loc = (rand() % cardsUsed.size());
				cardsReady.push_back(cardsUsed.at(loc));
				cardsUsed.erase(cardsUsed.begin() + loc);
			}
		}*/
		coolDown -= 1;
	}
}



bool Creature::omniTileCheck(int tileNumber, bool impasable, bool character, bool enemy, bool nuller) {

	bool finalVal = true;

	if (nuller && (tileNumber == -1)) {
		finalVal = false; 
	}
	else {
		if (impasable && (mapTiles->at(tileNumber)).isUnpassable == true) {
			
			if ( (!character && (mapTiles->at(tileNumber)).characterLink != "")) {
				
			}
			else if (character) {
				finalVal = false;
				//std::cout << "Banned on account of character being blocking the tile!!!!!!!!!!!!!!!!!!1";
			}
			else
			if ((!enemy && (mapTiles->at(tileNumber)).creatureLink != "")) {

			}
			else if (enemy) {
				finalVal = false;
			}
			else {
				finalVal = false;
			}
		} 
		if (character && (mapTiles->at(tileNumber)).characterLink != "") {
			finalVal = false;
		} 
		if (enemy && (mapTiles->at(tileNumber)).creatureLink != "") {
			finalVal = false;
		}
	}
	




	return finalVal;
}
void Creature::path() {
	
	std::vector<Path> paths = { Path({mapTiles->at(currentTile).c1},4),Path({mapTiles->at(currentTile).c2},5),Path({mapTiles->at(currentTile).c3},6),Path({mapTiles->at(currentTile).c4},1),Path({mapTiles->at(currentTile).c5},2),Path({mapTiles->at(currentTile).c6},3) };
	if (mapTiles->at(currentTile).c6 == -1 || mapTiles->at(mapTiles->at(currentTile).c6).isUnpassable) {
		paths.erase(paths.begin() + 5);
	}
	if (mapTiles->at(currentTile).c5 == -1 || mapTiles->at(mapTiles->at(currentTile).c5).isUnpassable) {
		paths.erase(paths.begin() + 4);
	}
	if (mapTiles->at(currentTile).c4 == -1 || mapTiles->at(mapTiles->at(currentTile).c4).isUnpassable) {
		paths.erase(paths.begin() + 3);
	}
	if (mapTiles->at(currentTile).c3 == -1 || mapTiles->at(mapTiles->at(currentTile).c3).isUnpassable) {
		paths.erase(paths.begin() + 2);
	}
	if (mapTiles->at(currentTile).c2 == -1 || mapTiles->at(mapTiles->at(currentTile).c2).isUnpassable) {
		paths.erase(paths.begin() + 1);
	}
	if (mapTiles->at(currentTile).c1 == -1 || mapTiles->at(mapTiles->at(currentTile).c1).isUnpassable) {
		paths.erase(paths.begin() + 0);
	}
	//std::cout << "    Paths in list: " << paths.size() << "      ";
	//std::vector<int> currentShortest = { };
	bool going = true;
	int currentLeng = 1;
	while (going) {
		std::cout << "run path: Trying to make it to the tile that is named: " << moveDest << std::endl ;
		std::cout << "The current paths are: " << std::endl;
		for (int i = 0; i < paths.size(); i++)
		{
			std::cout << paths.at(i).weave.at(paths.at(i).weave.size() - 1) << std::endl;
		}
		int pathSize = paths.size();
		for (int i = 0; i < pathSize; i++)
		{
			if (paths.at(i).weave.at(paths.at(i).weave.size() - 1) == moveDest) {
				going = false;
				going = false;
				pathWeave = paths.at(i).weave;
				break;
			}
			else {
				if (paths.at(i).from == 4) {
					if (omniTileCheck((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c6),true,false,true,true)) {
						paths.push_back(paths.at(i));
						paths.at(paths.size() - 1).from = 3;
						paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c6);
					}

					if (omniTileCheck((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c2), true, false, true, true)) {
						paths.push_back(paths.at(i));
						paths.at(paths.size() - 1).from = 5;
						paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c2);
					}

					if (omniTileCheck((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c1), true, false, true, true)) {
						std::cout << "going up!";
						paths.at(i).from = 4;
						paths.at(i).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c1);
					}

				}
				else if (paths.at(i).from == 5) {
					if ((omniTileCheck((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c1), true, false, true, true))) {
						paths.push_back(paths.at(i));
						paths.at(paths.size() - 1).from = 4;
						paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c1);
					}
					if ((omniTileCheck((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c3), true, false, true, true))) {
						paths.push_back(paths.at(i));
						paths.at(paths.size() - 1).from = 6;
						paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c3);
					}
					if ((omniTileCheck((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c2), true, false, true, true))) {
						paths.at(i).from = 5;
						paths.at(i).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c2);
					}
				}
				else if (paths.at(i).from == 6) {
					if ((omniTileCheck((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c2), true, false, true, true))) {
						paths.push_back(paths.at(i));
						paths.at(paths.size() - 1).from = 5;
						paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c2);
					}
					if ((omniTileCheck((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c4), true, false, true, true))) {
						paths.push_back(paths.at(i));
						paths.at(paths.size() - 1).from = 1;
						paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c4);
					}
					if ((omniTileCheck((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c3), true, false, true, true))) {
						paths.at(i).from = 6;
						paths.at(i).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c3);
					}
				}
				else if (paths.at(i).from == 1) {
					if ((omniTileCheck((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c3), true, false, true, true))) {
						paths.push_back(paths.at(i));
						paths.at(paths.size() - 1).from = 6;
						paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c3);
					}
					if ((omniTileCheck((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c5), true, false, true, true))) {
						paths.push_back(paths.at(i));
						paths.at(paths.size() - 1).from = 2;
						paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c5);
					}
					if ((omniTileCheck((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c4), true, false, true, true))) {
						paths.at(i).from = 1;
						paths.at(i).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c4);
					}
				}
				else if (paths.at(i).from == 2) {
					if ((omniTileCheck((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c4), true, false, true, true))) {
						paths.push_back(paths.at(i));
						paths.at(paths.size() - 1).from = 1;
						paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c4);
					}
					if ((omniTileCheck((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c6), true, false, true, true))) {

						paths.push_back(paths.at(i));
						paths.at(paths.size() - 1).from = 3;
						paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c6);
					}
					if ((omniTileCheck((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c5), true, false, true, true))) {
						paths.at(i).from = 2;
						paths.at(i).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c5);
					}
				}
				else if (paths.at(i).from == 3) {
					if ((omniTileCheck((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c5), true, false, true, true))) {
						paths.push_back(paths.at(i));
						paths.at(paths.size() - 1).from = 2;
						paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c5);
					}
					if ((omniTileCheck((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c1), true, false, true, true))) {
						paths.push_back(paths.at(i));
						paths.at(paths.size() - 1).from = 4;
						paths.at(paths.size() - 1).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c1);
					}
					if ((omniTileCheck((mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c6), true, false, true, true))) {
						paths.at(i).from = 3;
						paths.at(i).weave.push_back(mapTiles->at(paths.at(i).weave.at(paths.at(i).weave.size() - 1)).c6);
					}
				}
			}
		}
	}
	for (int i = 0; i < pathWeave.size(); i++)
	{
		//std::cout << pathWeave.at(i) << "  ";
	}
}
