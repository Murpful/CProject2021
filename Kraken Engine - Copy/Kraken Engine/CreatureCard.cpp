#include "CreatureCard.h"
CreatureCard::CreatureCard(std::string name, std::vector<CardEvent> events, int cool)
{
	cardTitle = name;
	cardEvents = events;
	cooldown = cool;
}