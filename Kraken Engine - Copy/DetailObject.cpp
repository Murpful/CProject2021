#include "DetailObject.h"
DetailObject::DetailObject(std::string ID, const char* textureSheet, int x, int y, int w, int h) : GameObject(textureSheet, x, y) {
	width = w;
	height = h;
	destRect.h = h;
	destRect.w = w;
	srcRect.h = height;
	srcRect.w = width;
	srcRect.x = 0;
	srcRect.y = 0;
	sy = 0;
	sx = 0;
	frames = 0;
	animated = false;
	delayTime = 0;
	objectID = ID;
	aniInit = false;
}
DetailObject::DetailObject(std::string ID, const char* textureSheet, int x, int y, int w, int h, bool anim, int frame, int delay) : GameObject(textureSheet, x, y) {
	width = w;
	height = h;
	destRect.h = h;
	destRect.w = w;
	srcRect.h = height;
	srcRect.w = width;
	srcRect.x = 0;
	srcRect.y = 0;
	frames = frame;
	animated = anim;
	delayTime = delay;
	objectID = ID;
	sy = 0;
	sx = 0;
	aniInit = false;
}
DetailObject::DetailObject(std::string ID, const char* textureSheet, int x, int y, int w, int h, int sw, int sh, bool anim, int frame, int delay, bool loops) : GameObject(textureSheet, x, y) {
	width = w;
	height = h;
	destRect.h = h;
	destRect.w = w;
	srcRect.h = height;
	srcRect.w = width;
	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.h = sh;
	srcRect.w = sw;
	frames = frame;
	animated = anim;
	delayTime = delay;
	objectID = ID;
	loop = loops;
	sy = sh;
	sx = sw;
	aniInit = false;
}
DetailObject::DetailObject(std::string ID, const char* textureSheet, int x, int y, int w, int h, int sw, int sh) : GameObject(textureSheet, x, y) {
	width = w;
	height = h;
	destRect.h = h;
	destRect.w = w;
	srcRect.h = sh;
	srcRect.w = sw;
	srcRect.x = 0;
	srcRect.y = 0;
	frames = 0;
	animated = false;
	delayTime = 0;
	objectID = ID;
	sy = sh;
	sx = sw;
	aniInit = false;
}
DetailObject::DetailObject(std::string ID, const char* textureSheet, int x, int y, int w, int h, bool offs) : GameObject(textureSheet, x, y, offs) {
	width = w;
	height = h;
	destRect.h = h;
	destRect.w = w;
	srcRect.h = height;
	srcRect.w = width;
	srcRect.x = 0;
	srcRect.y = 0;
	sy = 0;
	sx = 0;
	frames = 0;
	animated = false;
	delayTime = 0;
	objectID = ID;
	aniInit = false;
}
DetailObject::DetailObject(std::string ID, const char* textureSheet, int x, int y, int w, int h, int sw, int sh, bool offs) : GameObject(textureSheet, x, y, offs) {
	width = w;
	height = h;
	destRect.h = h;
	destRect.w = w;
	srcRect.h = sh;
	srcRect.w = sw;
	srcRect.x = 0;
	srcRect.y = 0;
	frames = 0;
	animated = false;
	delayTime = 0;
	objectID = ID;
	sy = sh;
	sx = sw;
	aniInit = false;
}
DetailObject::DetailObject(std::string ID, const char* textureSheet, int x, int y, int w, int h, bool offs, bool anim, int frame, int delay) : GameObject(textureSheet, x, y, offs) {
	width = w;
	height = h;
	destRect.h = h;
	destRect.w = w;
	srcRect.h = height;
	srcRect.w = width;
	srcRect.x = 0;
	srcRect.y = 0;
	frames = frame;
	animated = anim;
	delayTime = delay;
	objectID = ID;
	sy = 0;
	sx = 0;
	aniInit = false;
}
DetailObject::DetailObject(std::string ID, const char* textureSheet, int x, int y, int w, int h, int sw, int sh, bool offs, bool anim, int frame, int delay, bool looper) : GameObject(textureSheet, x, y, offs) {
	width = w;
	height = h;
	destRect.h = h;
	destRect.w = w;
	srcRect.h = height;
	srcRect.w = width;
	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.h = sh;
	srcRect.w = sw;
	frames = frame;
	animated = anim;
	delayTime = delay;
	objectID = ID;
	loop = looper;
	sy = sh;
	sx = sw;
	aniInit = false;
}



void DetailObject::moveObjectTo(int x, int y) {
	xPos = x;
	yPos = y;
}
void DetailObject::moveObject(int x, int y) {
	xPos += x;
	yPos += y;
}
void DetailObject::update() {
	static int offSet = 0;//static_cast<int>((SDL_GetTicks() / (delayTime)) % frames);
	if (animated == true) {
		if (loop == true) {
			if (frames > 1) {

				srcRect.x = srcRect.w * static_cast<int>((SDL_GetTicks() / (delayTime)) % frames);
			}
		}
		else if (loop == false) {

			if (aniInit == false) {
				offSet = static_cast<int>((SDL_GetTicks() / (delayTime)) % frames);
				aniInit = true;
			}

			if (frames > 1) {

				if ((static_cast<int>((SDL_GetTicks() / (delayTime)) % frames) - offSet) >= 0) {
					srcRect.x = srcRect.w * (static_cast<int>((SDL_GetTicks() / (delayTime)) % frames) - offSet);
				}
				else {
					srcRect.x = srcRect.w * ((static_cast<int>((SDL_GetTicks() / (delayTime)) % frames) - offSet) + frames);
				}

			}

		}

	}
	else if (aniInit == true) {
		std::cout << "reset ofofset";
		offSet = 0;
		srcRect.x = sx;
		srcRect.y = sy;
		aniInit = false;
	}


	destRect.x = xPos;
	destRect.y = yPos;
	destRect.w = width;
	destRect.h = height;
}
void DetailObject::setObjectID(std::string newid) {
	objectID = newid;
}