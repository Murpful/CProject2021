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
	int minDist;
	Move(int, int, moveTypes = random);
	Move(int, int, moveTypes, int);
};


