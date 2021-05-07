#include "GameObject.h"
GameObject::GameObject(const char* texturesheet, int x, int y) {
	objTexture = TextureManager::loadTexture(texturesheet);
	xPos = x;
	yPos = y;
	srcRect.h = 640;
	srcRect.w = 800;
	srcRect.x = 0;
	srcRect.y = 0;
	destRect.x = xPos;
	destRect.y = yPos;
	destRect.w = srcRect.w;
	destRect.h = srcRect.h;
	offSet = true;
}
GameObject::GameObject(const char* texturesheet, int x, int y, bool off) {
	objTexture = TextureManager::loadTexture(texturesheet);
	xPos = x;
	yPos = y;
	srcRect.h = 640;
	srcRect.w = 800;
	srcRect.x = 0;
	srcRect.y = 0;
	destRect.x = xPos;
	destRect.y = yPos;
	destRect.w = srcRect.w;
	destRect.h = srcRect.h;
	offSet = off;
}
GameObject::~GameObject() {

}
void GameObject::Render(int offSetx, int offSety) {
	if ((((destRect.x + offSetx + destRect.w > 0) && (destRect.y + offSety + destRect.h > 0) && (destRect.y + offSety < 864) && (destRect.x + offSetx < 1536)) || offSet == false)) {
		if (offSet == true) {
			destRect.x += offSetx;
			destRect.y += offSety;
		}
		SDL_RenderCopy(rendererStorage::renderer, objTexture, &srcRect, &destRect);
		if (offSet == true) {
			destRect.x -= offSetx;
			destRect.y -= offSety;
		}
	}



}
void GameObject::update() {

}
