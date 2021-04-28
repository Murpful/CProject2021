#pragma once
#include <vector>
enum cardAction
{
	attack,heal
};
class CardEvent
{
public:
	cardAction action;
	std::vector<int> data;
	CardEvent(cardAction, std::vector<int>);
};

