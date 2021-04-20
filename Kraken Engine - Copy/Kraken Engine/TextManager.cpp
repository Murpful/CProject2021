#include "TextManager.h"
SDL_Texture* TextManager::loadTexture(const char* fontType, int fontSize, int colOne, int colTwo, int colThree, const char* text) {

	TTF_Font* font = TTF_OpenFont(fontType, fontSize);
	SDL_Color color = { colOne, colTwo, colThree };
	SDL_Surface* surface = TTF_RenderText_Solid(font, text, color);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(rendererStorage::renderer, surface);
	TTF_CloseFont(font);
	SDL_FreeSurface(surface);
	//SDL_DestroyTexture(tex);


	return tex;

}