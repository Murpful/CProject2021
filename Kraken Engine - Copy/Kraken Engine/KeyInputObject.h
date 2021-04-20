#pragma once
#include "InputManager.h"
#include <string>
class KeyInputObject
{
public:
	bool held;
	bool pressed;
	InputManager* mInputMgr;
	void Update();
	void execute();
	KeyInputObject(std::string ID, void (*function)(), SDL_Scancode);
	KeyInputObject(std::string ID, void (*function)(), SDL_Scancode, bool);
	~KeyInputObject();
	void (*command)();
	SDL_Scancode chosenKey;
	std::string objectID;
};

