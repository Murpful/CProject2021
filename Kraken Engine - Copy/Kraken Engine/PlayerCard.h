#pragma once
#include "CardEvent.h"
#include <string>

class PlayerCard
{
public:
	std::string cardTitle;
	std::vector<CardEvent> cardEvents;
	const char* cardImage;
	PlayerCard(std::string,std::vector<CardEvent>,int,const char*);
	std::vector<CardEvent> getCardEvent();
	int coolDown;
	PlayerCard() {};
};

