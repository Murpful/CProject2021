#include "Attack.h"
Attack::Attack(int dmg, int rng) {
	damagePoints = dmg;
	range = rng;

}
Attack::Attack(int dmg, int rng, int length, int sublength, const char* anim) {
	damagePoints = dmg;
	range = rng;
	animation = anim;
	atkTime = length;
	subAtkTime = sublength;

}
Attack::Attack(int dmg, int rng, int length, int sublength, int frams, const char* anim) {
	damagePoints = dmg;
	range = rng;
	animation = anim;
	atkTime = length;
	subAtkTime = sublength;
	frames = frams;
	frameTime = atkTime/frams;
}