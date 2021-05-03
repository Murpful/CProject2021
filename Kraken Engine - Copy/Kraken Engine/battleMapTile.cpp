#include "battleMapTile.h"

battleMapTile::battleMapTile(int co1 ,int co2 ,int co3,int co4,int co5 ,int co6, bool noPass ) {
	c1 = co1;
	c2 = co2;
	c3 = co3;
	c4 = co4;
	c5 = co5;
	c6 = co6;
	isUnpassable = noPass;
	isShadowed = false;
	creatureLink = "";
}
battleMapTile::~battleMapTile() {

}