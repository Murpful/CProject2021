#pragma once
enum entityFaction
{
	player,monster
};
class Creature
{
public:
	int maxHealthPoints;
	int currentHealthPoints;
	entityFaction faction;
	Creature();
};

