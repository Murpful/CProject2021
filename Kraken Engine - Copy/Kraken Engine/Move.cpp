#include "Move.h"
Move::Move(int spd, int rng, moveTypes rdm) {
	speed = spd;
	range = rng;
	movement = rdm;
	minDist = 1;
}
Move::Move(int spd, int rng, moveTypes rdm, int minrng) {

	speed = spd;
	range = rng;
	movement = rdm;
	minDist = minrng+1;
}

