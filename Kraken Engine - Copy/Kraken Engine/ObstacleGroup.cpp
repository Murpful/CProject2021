#include "ObstacleGroup.h"
Obstacle::Obstacle(bool passability, const char* tex) {
	obstacle = passability;
	texture = tex;
}
ObstacleGroup::ObstacleGroup(std::vector<std::vector<Obstacle>> group) {
	tileLayout = group;
}

