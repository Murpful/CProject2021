#pragma once
#include<vector>
enum stats
{
	attackType, health, moveStats, faze, armor
};
class Component
{
public:
	stats witch;
	std::vector<int> value;
	Component(stats, std::vector<int>);

};

