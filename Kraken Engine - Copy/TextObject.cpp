#include "TextObject.h"

TextObject::~TextObject() {

}
void TextObject::Render() {
	SDL_RenderCopy(rendererStorage::renderer, objTexture, NULL, &destRect);

}
TextObject::TextObject(std::string ID, const char* fontType, int fontSize, int colOne, int colTwo, int colThree, int x, int y, std::string text) {
	m_fontType = fontType;
	m_fontSize = fontSize;
	m_colOne = colOne;
	m_colTwo = colTwo;
	m_colThree = colThree;
	m_text = text;
	xPos = x;
	yPos = y;
	objectID = ID;
	objTexture = TextManager::loadTexture(m_fontType, m_fontSize, m_colOne, m_colTwo, m_colThree, m_text.c_str());
}
void TextObject::moveObjectTo(int x, int y) {
	xPos = x;
	yPos = y;
}
void TextObject::moveObject(int x, int y) {
	xPos += x;
	yPos += y;
}
void TextObject::changeText(std::string newText) {
	m_text = newText;
	objTexture = TextManager::loadTexture(m_fontType, m_fontSize, m_colOne, m_colTwo, m_colThree, newText.c_str());
}
void TextObject::update() {
	//m_text = m_text;
	//const char* c = m_text.c_str();

	//srcRect.h = 0;
	//srcRect.w = 0;
	SDL_QueryTexture(objTexture, NULL, NULL, &destRect.w, &destRect.h);
	srcRect.x = 0;
	srcRect.y = 0;
	destRect.x = xPos;
	destRect.y = yPos;
	//delete c;
}