#pragma once
#include "CardEvent.h"
#include <string>
class CreatureCard
{
public:
	std::string cardTitle;
	std::vector<CardEvent> cardEvents;
	int cooldown;
	CreatureCard(std::string, std::vector<CardEvent>, int);
};

