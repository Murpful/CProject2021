#pragma once
#include<vector>
#include"move.h"
enum stats
{
	attackType, health, moveStats, faze, armor
};
class Component
{
public:
	stats witch;
	std::vector<int> value;
	moveTypes crtrMvmt;
	Component(stats, std::vector<int>, moveTypes);

};

