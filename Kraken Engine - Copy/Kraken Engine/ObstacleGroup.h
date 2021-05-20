#pragma once
#include <vector>
class Obstacle {
public:
	bool obstacle;
	const char* texture;
	Obstacle(bool, const char*);
};
class ObstacleGroup
{
public:
	std::vector<std::vector<Obstacle>> tileLayout;
	ObstacleGroup(std::vector<std::vector<Obstacle>> );
};

