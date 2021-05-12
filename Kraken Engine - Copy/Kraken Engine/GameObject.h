#pragma once
#include "TextureManager.h"
class GameObject
{



public:
	virtual void update();
	bool offSet;
	virtual void Render(int offSetx, int offSety);
	GameObject(const char* textureSheet, int x, int y);
	GameObject(const char* textureSheet, int x, int y, bool);
	~GameObject();
	int xPos;
	int yPos;
	SDL_Texture* objTexture; //this is the object texture file c string
	int renderOffSetx;
	int renderOffSety;

	SDL_Rect srcRect, destRect;
	bool diry = true;
	bool dirx = true;
	//SDL_Texture* objTexture; //this is the object texture file c string

};
