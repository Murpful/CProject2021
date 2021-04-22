#pragma once
#include "DetailObject.h"
class ButtonObject :
	public GameObject
{
public:
	std::vector<std::string>* eventList;
	int width;
	int height;
	int frames;
	int delayTime;
	bool animated;
	bool pressed;
	void (*command)();
	std::string objectID;
	~ButtonObject();
	ButtonObject(std::string ID, const char* textureSheet, void (*function)(), int x, int y, int width, int height);
	ButtonObject(std::string ID, const char* textureSheet, void (*function)(), int x, int y, int width, int height, bool ani, int frames, int delayTime = 500);
	ButtonObject(std::string ID, const char* textureSheet, void (*function)(), int x, int y, int width, int height, int sh, int sw);
	ButtonObject(std::string ID, const char* textureSheet, void (*function)(), int x, int y, int width, int height, int sh, int sw, bool ani, int frames, int delayTime = 500);

	ButtonObject(std::string ID, const char* textureSheet, void (*function)(), int x, int y, int width, int height, bool oofs);
	ButtonObject(std::string ID, const char* textureSheet, void (*function)(), int x, int y, int width, int height, bool oofs, bool ani, int frames, int delayTime = 500);
	ButtonObject(std::string ID, const char* textureSheet, void (*function)(), int x, int y, int width, int height, int sh, int sw, bool oofs);
	ButtonObject(std::string ID, const char* textureSheet, void (*function)(), int x, int y, int width, int height, int sh, int sw, bool oofs, bool ani, int frames, int delayTime = 500);
	void moveObjectTo(int x, int y);
	void moveObject(int x, int y);
	virtual void update(int offsetx, int offsety);
	//virtual void executeCommand() = 0;
};

class AdvancedHexagonalButtonObject : public ButtonObject {
	void (*command)(int);
	int numID;
	int radius;
	~AdvancedHexagonalButtonObject();
	AdvancedHexagonalButtonObject(std::string ID, const char* textureSheet,int id, void (*function)(int), int x, int y, int radi);
	AdvancedHexagonalButtonObject(std::string ID, const char* textureSheet,int id, void (*function)(int), int x, int y, int radi, bool ani, int frames, int delayTime = 500);
	AdvancedHexagonalButtonObject(std::string ID, const char* textureSheet,int id, void (*function)(int), int x, int y, int radi, int sh, int sw);
	AdvancedHexagonalButtonObject(std::string ID, const char* textureSheet,int id, void (*function)(int), int x, int y, int radi, int sh, int sw, bool ani, int frames, int delayTime = 500);

	AdvancedHexagonalButtonObject(std::string ID, const char* textureSheet, int id, void (*function)(int), int x, int y, int radi, bool oofs);
	AdvancedHexagonalButtonObject(std::string ID, const char* textureSheet, int id, void (*function)(int), int x, int y, int radi, bool oofs, bool ani, int frames, int delayTime = 500);
	AdvancedHexagonalButtonObject(std::string ID, const char* textureSheet, int id, void (*function)(int), int x, int y, int radi, int sh, int sw, bool oofs);
	AdvancedHexagonalButtonObject(std::string ID, const char* textureSheet, int id, void (*function)(int), int x, int y, int radi, int sh, int sw, bool oofs, bool ani, int frames, int delayTime = 500);
	void update(int offsetx, int offsety);
};
