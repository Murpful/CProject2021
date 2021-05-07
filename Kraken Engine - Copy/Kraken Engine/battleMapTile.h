#pragma once
#include<string>
class battleMapTile
{
public:
	int c1;
	int c2;
	int c3;
	int c4;
	int c5;
	int c6;
	bool isUnpassable;
	bool isShadowed;
	bool finalTile;
	battleMapTile(int, int, int, int, int, int, bool = false);
	~battleMapTile();
	std::string creatureLink;
	std::string characterLink;

};

