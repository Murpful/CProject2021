#pragma once
enum moveTypes
{
	random, toward, away
};
class Move
{
public:
	moveTypes movement;
	int speed;
	int range;
	Move(int, int, moveTypes = random);
};


