#include "KeyInputObject.h"
KeyInputObject::KeyInputObject(std::string ID, void (*function)(), SDL_Scancode keycode) {
	mInputMgr = InputManager::Instance();
	command = function;
	chosenKey = keycode;
	held = false;
	pressed = false;
	objectID = ID;
}
KeyInputObject::KeyInputObject(std::string ID, void (*function)(), SDL_Scancode keycode, bool hold) {
	mInputMgr = InputManager::Instance();
	command = function;
	chosenKey = keycode;
	held = hold;
	pressed = false;
	objectID = ID;
}
KeyInputObject::~KeyInputObject() {
	InputManager::Release();
	mInputMgr = NULL;
}

void KeyInputObject::Update() {
	mInputMgr->Update();
	execute();
}
void KeyInputObject::execute() {
	if ((mInputMgr->KeyDown(chosenKey))) {
		if ((pressed == false)) {
			command();
			if (held == false) {
				pressed = true;
			}
		}

	}
	else {
		pressed = false;
	}
}