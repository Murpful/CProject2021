#pragma once
enum moveTypes
{
	random, toward, away
};
class Move
{public:
	moveTypes movement;
	int speed;
	int range;
	Move(moveTypes, int, int);
};

