#pragma once
class Attack
{public:
	int damagePoints;
	int range;
	int atkTime, subAtkTime;
	int frames, frameTime;
	const char* animation;
	Attack(int, int);
	Attack(int, int, int , int , const char*);
	Attack(int, int, int, int, int, const char*);

};

