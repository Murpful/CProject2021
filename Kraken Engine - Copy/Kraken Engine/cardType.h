#pragma once
#include<string>
class CardType
{
	std::string cardName;
	int cooldown;
	CardType(std::string);
	void act();
};

