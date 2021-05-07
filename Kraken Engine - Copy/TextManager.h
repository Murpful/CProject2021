#pragma once
//#include "Game.h"
#include "rendererStorage.h"
class TextManager
{
public:

	static SDL_Texture* loadTexture(const char* fontType, int fontSize, int colOne, int colTwo, int colThree, const char* text);
};

