#pragma once
#include "TextManager.h"
#include "ButtonObject.h"
#include "KeyInputObject.h"
class TextObject
{
public:
	TextObject(std::string ID, const char* fontType, int fontSize, int colOne, int colTwo, int colThree, int x, int y, std::string text);
	~TextObject();
	void update();
	void Render();
	void moveObjectTo(int x, int y);
	void moveObject(int x, int y);
	void changeText(std::string text);
	int xPos;
	int yPos;
	SDL_Rect srcRect, destRect;
	std::string objectID;
	std::string m_text;
protected:
	const char* m_fontType;
	int m_fontSize;
	int m_colOne;
	int m_colTwo;
	int m_colThree;

	bool diry = true;
	bool dirx = true;
	SDL_Texture* objTexture;
};

