#include "ButtonObject.h"
ButtonObject::~ButtonObject() {

}
ButtonObject::ButtonObject(std::string ID, const char* texturesheet, void (*function)(), int x, int y, int Width, int Height) : GameObject(texturesheet, x, y) {
	width = Width;
	height = Height;
	pressed = false;
	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.h = height;
	srcRect.w = width;
	frames = 0;
	animated = false;
	destRect.x = xPos;
	destRect.y = yPos;
	destRect.w = width;
	destRect.h = height;
	command = function;
	delayTime = 0;
	objectID = ID;
}
ButtonObject::ButtonObject(std::string ID, const char* texturesheet, void (*function)(), int x, int y, int Width, int Height, bool ani, int frameCount, int delayTimed) : GameObject(texturesheet, x, y) {
	width = Width;
	height = Height;
	pressed = false;
	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.h = height;
	srcRect.w = width;
	frames = frameCount;
	animated = ani;
	destRect.x = xPos;
	destRect.y = yPos;
	destRect.w = width;
	destRect.h = height;
	delayTime = delayTimed;
	command = function;
	objectID = ID;
}
ButtonObject::ButtonObject(std::string ID, const char* texturesheet, void (*function)(), int x, int y, int Width, int Height, int sourceh, int sourcew) : GameObject(texturesheet, x, y) {
	width = Width;
	height = Height;
	pressed = false;
	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.h = sourceh;
	srcRect.w = sourcew;
	destRect.w = width;
	destRect.h = height;
	frames = 0;
	animated = false;
	command = function;
	delayTime = 0;
	objectID = ID;
}
ButtonObject::ButtonObject(std::string ID, const char* textureSheet, void (*function)(), int x, int y, int Width, int Height, int sourceh, int sourcew, bool ani, int frameCount, int delayTimed) : GameObject(textureSheet, x, y) {
	width = Width;
	height = Height;
	pressed = false;
	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.h = sourceh;
	srcRect.w = sourcew;
	frames = frameCount;
	animated = ani;
	destRect.x = xPos;
	destRect.y = yPos;
	destRect.w = width;
	destRect.h = height;
	delayTime = delayTimed;
	command = function;
	objectID = ID;
}


ButtonObject::ButtonObject(std::string ID, const char* texturesheet, void (*function)(), int x, int y, int Width, int Height, bool oofs) : GameObject(texturesheet, x, y, oofs) {
	width = Width;
	height = Height;
	pressed = false;
	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.h = height;
	srcRect.w = width;
	frames = 0;
	animated = false;
	destRect.x = xPos;
	destRect.y = yPos;
	destRect.w = width;
	destRect.h = height;
	command = function;
	delayTime = 0;
	objectID = ID;
}
ButtonObject::ButtonObject(std::string ID, const char* texturesheet, void (*function)(), int x, int y, int Width, int Height, bool oofs, bool ani, int frameCount, int delayTimed) : GameObject(texturesheet, x, y, oofs) {
	width = Width;
	height = Height;
	pressed = false;
	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.h = height;
	srcRect.w = width;
	frames = frameCount;
	animated = ani;
	destRect.x = xPos;
	destRect.y = yPos;
	destRect.w = width;
	destRect.h = height;
	delayTime = delayTimed;
	command = function;
	objectID = ID;
}
ButtonObject::ButtonObject(std::string ID, const char* texturesheet, void (*function)(), int x, int y, int Width, int Height, int sourceh, int sourcew, bool oofs) : GameObject(texturesheet, x, y, oofs) {
	width = Width;
	height = Height;
	pressed = false;
	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.h = sourceh;
	srcRect.w = sourcew;
	destRect.w = width;
	destRect.h = height;
	frames = 0;
	animated = false;
	command = function;
	delayTime = 0;
	objectID = ID;
}
ButtonObject::ButtonObject(std::string ID, const char* textureSheet, void (*function)(), int x, int y, int Width, int Height, int sourceh, int sourcew, bool oofs, bool ani, int frameCount, int delayTimed) : GameObject(textureSheet, x, y, oofs) {
	width = Width;
	height = Height;
	pressed = false;
	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.h = sourceh;
	srcRect.w = sourcew;
	frames = frameCount;
	animated = ani;
	destRect.x = xPos;
	destRect.y = yPos;
	destRect.w = width;
	destRect.h = height;
	delayTime = delayTimed;
	command = function;
	objectID = ID;
}








void ButtonObject::moveObjectTo(int x, int y) {
	xPos = x;
	yPos = y;
}
void ButtonObject::moveObject(int x, int y) {
	xPos += x;
	yPos += y;
}
void ButtonObject::update(int offx, int offy) {
	if (offSet == false) {
		offx = 0;
		offy = 0;
	}
	if (frames > 1) {
		srcRect.x = srcRect.w * static_cast<int>((SDL_GetTicks() / (delayTime)) % frames);
	}
	int xl = 0;
	int yl = 0;
	//std::cout << pressed;
	
	//else {
		if (SDL_GetMouseState(&xl, &yl) != 1) {
			//std::cout << "not down";
			if (pressed == true && ((xl > xPos + offx) && (yl > yPos + offy) && (xl < xPos + destRect.w + offx) && (yl < yPos + destRect.h + offy))) {
				command();
				//SDL_Delay(200);
			}
			pressed = false;
		} else if (pressed == false) {
			if (SDL_GetMouseState(&xl, &yl) == 1) {
				if ((xl > xPos + offx) && (yl > yPos + offy) && (xl < xPos + destRect.w + offx) && (yl < yPos + destRect.h + offy)) {
					pressed = true;
					//command();
					//SDL_Delay(200);
					//std::cout << pressed;
				}
			}
		}
	//}


}




AdvancedHexagonalButtonObject::~AdvancedHexagonalButtonObject() {

}
AdvancedHexagonalButtonObject::AdvancedHexagonalButtonObject(std::string ID, const char* texturesheet,int id, void (*function)(int), int x, int y, int radi) : ButtonObject( ID,  texturesheet,  NULL,  x,  y,  0,  0) {
	radius = radi;
	numID = id;
	pressed = false;
	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.h = height;
	srcRect.w = width;
	frames = 0;
	animated = false;
	destRect.x = xPos;
	destRect.y = yPos;
	destRect.w = width;
	destRect.h = height;
	command = function;
	delayTime = 0;
	objectID = ID;
}
AdvancedHexagonalButtonObject::AdvancedHexagonalButtonObject(std::string ID, const char* texturesheet, int id, void (*function)(int), int x, int y, int radi, bool ani, int frameCount, int delayTimed) : ButtonObject( ID,  texturesheet,  NULL,  x,  y,  0,  0,  ani,  frameCount,  delayTimed) {
	radius = radi;
	numID = id;
	pressed = false;
	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.h = height;
	srcRect.w = width;
	frames = frameCount;
	animated = ani;
	destRect.x = xPos;
	destRect.y = yPos;
	destRect.w = width;
	destRect.h = height;
	delayTime = delayTimed;
	command = function;
	objectID = ID;
}
AdvancedHexagonalButtonObject::AdvancedHexagonalButtonObject(std::string ID, const char* texturesheet, int id, void (*function)(int), int x, int y, int radi, int sourceh, int sourcew) : ButtonObject( ID,  texturesheet,  NULL,  x,  y,  0,  0,  sourceh,  sourcew) {
	radius = radi;
	numID = id;
	pressed = false;
	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.h = sourceh;
	srcRect.w = sourcew;
	destRect.w = width;
	destRect.h = height;
	frames = 0;
	animated = false;
	command = function;
	delayTime = 0;
	objectID = ID;
}
AdvancedHexagonalButtonObject::AdvancedHexagonalButtonObject(std::string ID, const char* textureSheet, int id, void (*function)(int), int x, int y, int radi, int sourceh, int sourcew, bool ani, int frameCount, int delayTimed) : ButtonObject( ID,  textureSheet,  NULL,  x,  y,  0,  0,  sourceh,  sourcew,  ani,  frameCount,  delayTimed) {
	radius = radi;
	numID = id;
	pressed = false;
	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.h = sourceh;
	srcRect.w = sourcew;
	frames = frameCount;
	animated = ani;
	destRect.x = xPos;
	destRect.y = yPos;
	destRect.w = width;
	destRect.h = height;
	delayTime = delayTimed;
	command = function;
	objectID = ID;
}


AdvancedHexagonalButtonObject::AdvancedHexagonalButtonObject(std::string ID, const char* texturesheet, int id, void (*function)(int), int x, int y, int radi, bool oofs) : ButtonObject( ID,  texturesheet,  NULL,  x,  y,  0,  0,  oofs) {
	radius = radi;
	numID = id;
	pressed = false;
	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.h = height;
	srcRect.w = width;
	frames = 0;
	animated = false;
	destRect.x = xPos;
	destRect.y = yPos;
	destRect.w = width;
	destRect.h = height;
	command = function;
	delayTime = 0;
	objectID = ID;
}
AdvancedHexagonalButtonObject::AdvancedHexagonalButtonObject(std::string ID, const char* texturesheet, int id, void (*function)(int), int x, int y, int radi, bool oofs, bool ani, int frameCount, int delayTimed) : ButtonObject( ID,  texturesheet,  NULL,  x,  y,  0,  0,  oofs,  ani,  frameCount,  delayTimed) {
	radius = radi;
	numID = id;
	pressed = false;
	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.h = height;
	srcRect.w = width;
	frames = frameCount;
	animated = ani;
	destRect.x = xPos;
	destRect.y = yPos;
	destRect.w = width;
	destRect.h = height;
	delayTime = delayTimed;
	command = function;
	objectID = ID;
}
AdvancedHexagonalButtonObject::AdvancedHexagonalButtonObject(std::string ID, const char* texturesheet, int id, void (*function)(int), int x, int y, int radi, int sourceh, int sourcew, bool oofs) : ButtonObject( ID,  texturesheet,  NULL,  x,  y,  0,  0,  sourceh,  sourcew,  oofs) {
	radius = radi;
	numID = id;
	pressed = false;
	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.h = sourceh;
	srcRect.w = sourcew;
	destRect.w = width;
	destRect.h = height;
	frames = 0;
	animated = false;
	command = function;
	delayTime = 0;
	objectID = ID;
}
AdvancedHexagonalButtonObject::AdvancedHexagonalButtonObject(std::string ID, const char* textureSheet, int id, void (*function)(int), int x, int y, int radi, int sourceh, int sourcew, bool oofs, bool ani, int frameCount, int delayTimed)  : ButtonObject(ID,  textureSheet,  nullptr,  x,  y,  0,  0,  sourceh,  sourcew,  oofs,  ani,  frameCount,  delayTimed) {
	radius = radi;
	numID = id;
	pressed = false;
	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.h = sourceh;
	srcRect.w = sourcew;
	frames = frameCount;
	animated = ani;
	destRect.x = xPos;
	destRect.y = yPos;
	destRect.w = width;
	destRect.h = height;
	delayTime = delayTimed;
	command = function;
	objectID = ID;
}


void AdvancedHexagonalButtonObject::update(int offx, int offy) {
	//make this work for d hexagon???????????????
	if (offSet == false) {
		offx = 0;
		offy = 0;
	}
	if (frames > 1) {
		srcRect.x = srcRect.w * static_cast<int>((SDL_GetTicks() / (delayTime)) % frames);
	}
	int xl = 0;
	int yl = 0;
	//std::cout << pressed;

	//else {
	if (SDL_GetMouseState(&xl, &yl) != 1) {
		//std::cout << "not down";
		if (pressed == true && ((xl > xPos + offx) && (yl > yPos + offy) && (xl < xPos + destRect.w + offx) && (yl < yPos + destRect.h + offy))) {
			command(numID);
			//SDL_Delay(200);
		}
		pressed = false;
	}
	else if (pressed == false) {
		if (SDL_GetMouseState(&xl, &yl) == 1) {
			if ((xl > xPos + offx) && (yl > yPos + offy) && (xl < xPos + destRect.w + offx) && (yl < yPos + destRect.h + offy)) {
				pressed = true;
			}
		}
	}
	//}


}