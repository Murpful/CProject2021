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
	virtual void update(int, int);

	//virtual void executeCommand() = 0;
};
class AdvancedButtonObject : public ButtonObject {
public:
	void (*command1)(int);
	void (*command2)(std::vector<int>);
	void (*command3)(std::string);
	void (*command4)(std::vector<std::string>);
	void (*command5)(double);
	void (*command6)(std::vector<double>);
	int infoInt;
	int commandType;
	std::vector<int> infoIntVec;
	void update(int, int);
	AdvancedButtonObject(std::string ID, const char* textureSheet, void (*function)(int), int x, int y, int width, int height, int info);
	AdvancedButtonObject(std::string ID, const char* textureSheet, void (*function)(int), int x, int y, int width, int height, int info, bool ani, int frames, int delayTime = 500);
	AdvancedButtonObject(std::string ID, const char* textureSheet, void (*function)(int), int x, int y, int width, int height, int info, int sh, int sw);
	AdvancedButtonObject(std::string ID, const char* textureSheet, void (*function)(int), int x, int y, int width, int height, int info, int sh, int sw, bool ani, int frames, int delayTime = 500);
	AdvancedButtonObject(std::string ID, const char* textureSheet, void (*function)(int), int x, int y, int width, int height, int info, bool oofs);
	AdvancedButtonObject(std::string ID, const char* textureSheet, void (*function)(int), int x, int y, int width, int height, int info, bool oofs, bool ani, int frames, int delayTime = 500);
	AdvancedButtonObject(std::string ID, const char* textureSheet, void (*function)(int), int x, int y, int width, int height, int info, int sh, int sw, bool oofs);
	AdvancedButtonObject(std::string ID, const char* textureSheet, void (*function)(int), int x, int y, int width, int height, int info, int sh, int sw, bool oofs, bool ani, int frames, int delayTime = 500);

	AdvancedButtonObject(std::string ID, const char* textureSheet, void (*function)(std::vector<int>), int x, int y, int width, int height, std::vector<int> info);
	AdvancedButtonObject(std::string ID, const char* textureSheet, void (*function)(std::vector<int>), int x, int y, int width, int height, std::vector<int> info, bool ani, int frames, int delayTime = 500);
	AdvancedButtonObject(std::string ID, const char* textureSheet, void (*function)(std::vector<int>), int x, int y, int width, int height, std::vector<int> info, int sh, int sw);
	AdvancedButtonObject(std::string ID, const char* textureSheet, void (*function)(std::vector<int>), int x, int y, int width, int height, std::vector<int> info, int sh, int sw, bool ani, int frames, int delayTime = 500);
	AdvancedButtonObject(std::string ID, const char* textureSheet, void (*function)(std::vector<int>), int x, int y, int width, int height, std::vector<int> info, bool oofs);
	AdvancedButtonObject(std::string ID, const char* textureSheet, void (*function)(std::vector<int>), int x, int y, int width, int height, std::vector<int> info, bool oofs, bool ani, int frames, int delayTime = 500);
	AdvancedButtonObject(std::string ID, const char* textureSheet, void (*function)(std::vector<int>), int x, int y, int width, int height, std::vector<int> info, int sh, int sw, bool oofs);
	AdvancedButtonObject(std::string ID, const char* textureSheet, void (*function)(std::vector<int>), int x, int y, int width, int height, std::vector<int> info, int sh, int sw, bool oofs, bool ani, int frames, int delayTime = 500);
};













class AdvancedHexagonalButtonObject : public ButtonObject {
public:
	void (*command)(int);
	int numID;
	int radius;
	~AdvancedHexagonalButtonObject();
	AdvancedHexagonalButtonObject(std::string ID, const char* textureSheet, int id, void (*function)(int), int x, int y, int radi, int width, int height);
	AdvancedHexagonalButtonObject(std::string ID, const char* textureSheet, int id, void (*function)(int), int x, int y, int radi, int width, int height, bool ani, int frames, int delayTime = 500);
	AdvancedHexagonalButtonObject(std::string ID, const char* textureSheet, int id, void (*function)(int), int x, int y, int radi, int width, int height, int sh, int sw);
	AdvancedHexagonalButtonObject(std::string ID, const char* textureSheet, int id, void (*function)(int), int x, int y, int radi, int width, int height, int sh, int sw, bool ani, int frames, int delayTime = 500);

	AdvancedHexagonalButtonObject(std::string ID, const char* textureSheet, int id, void (*function)(int), int x, int y, int radi, int width, int height, bool oofs);
	AdvancedHexagonalButtonObject(std::string ID, const char* textureSheet, int id, void (*function)(int), int x, int y, int radi, int width, int height, bool oofs, bool ani, int frames, int delayTime = 500);
	AdvancedHexagonalButtonObject(std::string ID, const char* textureSheet, int id, void (*function)(int), int x, int y, int radi, int width, int height, int sh, int sw, bool oofs);
	AdvancedHexagonalButtonObject(std::string ID, const char* textureSheet, int id, void (*function)(int), int x, int y, int radi, int width, int height, int sh, int sw, bool oofs, bool ani, int frames, int delayTime = 500);
	void update(int offsetx, int offsety);
};