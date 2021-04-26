#pragma once
#include "ObjectDataBase.h"


void ObjectDataBase::addObject(DetailObject* object) {
	DetailObject newObject = *object;
	detailedObjects.push_back(NULL);
	detailedObjects.at(detailedObjects.size() - 1) = NULL;
	detailedObjects.at(detailedObjects.size() - 1) = new DetailObject(newObject);
	delete object;
}
void ObjectDataBase::addObject(TextObject* object) {
	TextObject newObject = *object;
	textObjects.push_back(NULL);
	textObjects.at(textObjects.size() - 1) = NULL;
	textObjects.at(textObjects.size() - 1) = new TextObject(newObject);
	delete object;
}
void ObjectDataBase::addObject(ButtonObject* object) {
	ButtonObject newObject = *object;
	buttonObjects.push_back(NULL);
	buttonObjects.at(buttonObjects.size() - 1) = NULL;
	buttonObjects.at(buttonObjects.size() - 1) = new ButtonObject(newObject);
	delete object;
}
void ObjectDataBase::addObject(KeyInputObject* object) {
	KeyInputObject newObject = *object;
	keyInputObjects.push_back(NULL);
	keyInputObjects.at(keyInputObjects.size() - 1) = NULL;
	keyInputObjects.at(keyInputObjects.size() - 1) = new KeyInputObject(newObject);
	delete object;
}
void ObjectDataBase::deleteAllDetailObject() {
	while (detailedObjects.size() > 0)
	{
		delete detailedObjects.at(0);
		detailedObjects.erase(detailedObjects.begin() + 0);
	}
}
void ObjectDataBase::deleteAllButtonObject() {
	while (buttonObjects.size() > 0)
	{
		delete buttonObjects.at(0);
		buttonObjects.erase(buttonObjects.begin() + 0);
	}
}
void ObjectDataBase::deleteAllTextObject() {
	while (textObjects.size() > 0)
	{
		delete textObjects.at(0);
		textObjects.erase(textObjects.begin() + 0);
	}
}
void ObjectDataBase::deleteAllKeyInputObject() {
	while (keyInputObjects.size() > 0)
	{
		InputManager::Release();
		keyInputObjects.at(0) = NULL;
		delete keyInputObjects.at(0);
		keyInputObjects.erase(keyInputObjects.begin() + 0);
	}
}
void ObjectDataBase::deleteAll() {
	deleteAllButtonObject();
	deleteAllDetailObject();
	deleteAllTextObject();
	deleteAllKeyInputObject();
}
void ObjectDataBase::deleteDetailObject(int at) {
	delete detailedObjects.at(at);
	detailedObjects.erase(detailedObjects.begin() + at);
}
void ObjectDataBase::deleteTextObject(int at) {
	delete textObjects.at(at);
	textObjects.erase(textObjects.begin() + at);
}
void ObjectDataBase::deleteButtonObject(int at) {
	delete buttonObjects.at(at);
	buttonObjects.erase(buttonObjects.begin() + at);
}
void ObjectDataBase::deleteKeyInputObject(int at) {
	InputManager::Release();
	keyInputObjects.at(at) = NULL;
	delete keyInputObjects.at(at);
	keyInputObjects.erase(keyInputObjects.begin() + at);
}
void ObjectDataBase::updateObjects() {
	for (int i = 0; i < detailedObjects.size(); i++)
	{
		detailedObjects.at(i)->update();
	}
	for (int i = 0; i < textObjects.size(); i++)
	{
		textObjects.at(i)->update();
	}
	for (int i = 0; i < buttonObjects.size(); i++)
	{
		buttonObjects.at(i)->update(xoff, yoff);
	}
	for (int i = 0; i < keyInputObjects.size(); i++)
	{
		keyInputObjects.at(i)->Update();
	}
}
void ObjectDataBase::renderObjects() {
	for (int i = 0; i < detailedObjects.size(); i++)
	{
		detailedObjects.at(i)->Render(xoff, yoff);
	}
	for (int i = 0; i < textObjects.size(); i++)
	{
		textObjects.at(i)->Render();
	}
	for (int i = 0; i < buttonObjects.size(); i++)
	{
		buttonObjects.at(i)->Render(xoff, yoff);
	}
}
void ObjectDataBase::deleteObject(std::string objID) {
	for (int i = detailedObjects.size() - 1; i >= 0; i--)
	{
		if (detailedObjects.at(i)->objectID == objID) {
			detailedObjects.erase(detailedObjects.begin() + i);
		}
	}
	for (int i = buttonObjects.size() - 1; i >= 0; i--)
	{
		if (buttonObjects.at(i)->objectID == objID) {
			buttonObjects.erase(buttonObjects.begin() + i);
		}
	}
	for (int i = textObjects.size() - 1; i >= 0; i--)
	{
		if (textObjects.at(i)->objectID == objID) {
			textObjects.erase(textObjects.begin() + i);
		}
	}
}
void ObjectDataBase::deleteDetailObject(std::string objID) {
	for (int i = detailedObjects.size() - 1; i >= 0; i--)
	{
		if (detailedObjects.at(i)->objectID == objID) {
			detailedObjects.erase(detailedObjects.begin() + i);
		}
	}
}
void ObjectDataBase::deleteButtonObject(std::string objID) {
	for (int i = buttonObjects.size() - 1; i >= 0; i--)
	{
		if (buttonObjects.at(i)->objectID == objID) {
			buttonObjects.erase(buttonObjects.begin() + i);
		}
	}
}
void ObjectDataBase::deleteTextObject(std::string objID) {
	for (int i = textObjects.size() - 1; i >= 0; i--)
	{
		if (textObjects.at(i)->objectID == objID) {
			textObjects.erase(textObjects.begin() + i);
		}
	}
}
void ObjectDataBase::deleteKeyInputObject(std::string objID) {
	for (int i = keyInputObjects.size() - 1; i >= 0; i--)
	{
		if (keyInputObjects.at(i)->objectID == objID) {
			keyInputObjects.erase(keyInputObjects.begin() + i);
		}
	}
}
bool ObjectDataBase::ObjectCollide(DetailObject* initialObject, DetailObject* otherObject) {
	bool colide = false;

	if ((initialObject->xPos + initialObject->width > otherObject->xPos && initialObject->xPos < otherObject->xPos) && (initialObject->yPos + initialObject->height) > otherObject->yPos && (initialObject->yPos) < otherObject->yPos + otherObject->height) {
		colide = true;
	}
	if ((initialObject->xPos > otherObject->xPos) && (initialObject->xPos < otherObject->xPos + otherObject->width) && ((initialObject->yPos + initialObject->height) > otherObject->yPos && (initialObject->yPos) < otherObject->yPos + otherObject->height)) {
		colide = true;
	}


	return colide;
}
bool ObjectDataBase::ObjectCollide(DetailObject* initialObject, ButtonObject* otherObject) {
	bool colide = false;

	if ((initialObject->xPos + initialObject->width > otherObject->xPos && initialObject->xPos < otherObject->xPos) && (initialObject->yPos + initialObject->height) > otherObject->yPos && (initialObject->yPos) < otherObject->yPos + otherObject->height) {
		colide = true;
	}
	if ((initialObject->xPos > otherObject->xPos) && (initialObject->xPos < otherObject->xPos + otherObject->width) && ((initialObject->yPos + initialObject->height) > otherObject->yPos && (initialObject->yPos) < otherObject->yPos + otherObject->height)) {
		colide = true;
	}


	return colide;
}
bool ObjectDataBase::ObjectCollide(ButtonObject* initialObject, ButtonObject* otherObject) {
	bool colide = false;

	if ((initialObject->xPos + initialObject->width > otherObject->xPos && initialObject->xPos < otherObject->xPos) && (initialObject->yPos + initialObject->height) > otherObject->yPos && (initialObject->yPos) < otherObject->yPos + otherObject->height) {
		colide = true;
	}
	if ((initialObject->xPos > otherObject->xPos) && (initialObject->xPos < otherObject->xPos + otherObject->width) && ((initialObject->yPos + initialObject->height) > otherObject->yPos && (initialObject->yPos) < otherObject->yPos + otherObject->height)) {
		colide = true;
	}


	return colide;
}
bool ObjectDataBase::ObjectCollide(ButtonObject* initialObject, DetailObject* otherObject) {
	bool colide = false;

	if ((initialObject->xPos + initialObject->width > otherObject->xPos && initialObject->xPos < otherObject->xPos) && (initialObject->yPos + initialObject->height) > otherObject->yPos && (initialObject->yPos) < otherObject->yPos + otherObject->height) {
		colide = true;
	}
	if ((initialObject->xPos > otherObject->xPos) && (initialObject->xPos < otherObject->xPos + otherObject->width) && ((initialObject->yPos + initialObject->height) > otherObject->yPos && (initialObject->yPos) < otherObject->yPos + otherObject->height)) {
		colide = true;
	}


	return colide;
}
bool ObjectDataBase::DetailObjectCollide(std::string thisobjID, std::string otherobjID) {
	DetailObject* initialObject = getDetailObject(thisobjID);
	DetailObject* otherObject = getDetailObject(otherobjID);
	bool colide = false;
	if ((initialObject->xPos + initialObject->width > otherObject->xPos && initialObject->xPos < otherObject->xPos) && (initialObject->yPos + initialObject->height) > otherObject->yPos && (initialObject->yPos) < otherObject->yPos + otherObject->height) {
		colide = true;
	}
	if ((initialObject->xPos > otherObject->xPos) && (initialObject->xPos < otherObject->xPos + otherObject->width) && ((initialObject->yPos + initialObject->height) > otherObject->yPos && (initialObject->yPos) < otherObject->yPos + otherObject->height)) {
		colide = true;
	}



	return colide;
}
bool ObjectDataBase::ButtonObjectCollide(std::string thisobjID, std::string otherobjID) {
	ButtonObject* initialObject = getButtonObject(thisobjID);
	ButtonObject* otherObject = getButtonObject(otherobjID);
	bool colide = false;
	if ((initialObject->xPos + initialObject->width > otherObject->xPos && initialObject->xPos < otherObject->xPos) && (initialObject->yPos + initialObject->height) > otherObject->yPos && (initialObject->yPos) < otherObject->yPos + otherObject->height) {
		colide = true;
	}
	if ((initialObject->xPos > otherObject->xPos) && (initialObject->xPos < otherObject->xPos + otherObject->width) && ((initialObject->yPos + initialObject->height) > otherObject->yPos && (initialObject->yPos) < otherObject->yPos + otherObject->height)) {
		colide = true;
	}



	return colide;
}
bool ObjectDataBase::DetectObject(std::string objID) {
	bool detected = false;

	for (int i = 0; i < detailedObjects.size(); i++)
	{
		if (detailedObjects.at(i)->objectID == objID) {
			detected = true;
		}
	}
	for (int i = 0; i < keyInputObjects.size(); i++)
	{
		if (keyInputObjects.at(i)->objectID == objID) {
			detected = true;
		}
	}
	for (int i = 0; i < textObjects.size(); i++)
	{
		if (textObjects.at(i)->objectID == objID) {
			detected = true;
		}
	}
	for (int i = 0; i < buttonObjects.size(); i++)
	{
		if (buttonObjects.at(i)->objectID == objID) {
			detected = true;
		}
	}
	return detected;
}
bool ObjectDataBase::DetectDetailObject(std::string objID) {
	bool detected = false;

	for (int i = 0; i < detailedObjects.size(); i++)
	{
		if (detailedObjects.at(i)->objectID == objID) {
			detected = true;
		}
	}

	return detected;
}
bool ObjectDataBase::DetectButtonObject(std::string objID) {
	bool detected = false;

	for (int i = 0; i < buttonObjects.size(); i++)
	{
		if (buttonObjects.at(i)->objectID == objID) {
			detected = true;
		}
	}

	return detected;
}
bool ObjectDataBase::DetectTextObject(std::string objID) {
	bool detected = false;

	for (int i = 0; i < textObjects.size(); i++)
	{
		if (textObjects.at(i)->objectID == objID) {
			detected = true;
		}
	}

	return detected;
}
bool ObjectDataBase::DetectKeyInputObject(std::string objID) {
	bool detected = false;

	for (int i = 0; i < keyInputObjects.size(); i++)
	{
		if (keyInputObjects.at(i)->objectID == objID) {
			detected = true;
		}
	}

	return detected;
}
DetailObject* ObjectDataBase::getDetailObject(std::string objID) {
	bool foundReturn = false;
	for (int i = detailedObjects.size() - 1; i >= 0; i--)
	{
		if (detailedObjects.at(i)->objectID == objID) {
			foundReturn = true;
			return detailedObjects.at(i);
		}
	}
	if (foundReturn == false) {
		return NULL;
	}
}
ButtonObject* ObjectDataBase::getButtonObject(std::string objID) {
	bool foundReturn = false;
	for (int i = buttonObjects.size() - 1; i >= 0; i--)
	{
		if (buttonObjects.at(i)->objectID == objID) {
			foundReturn = true;
			return buttonObjects.at(i);
		}
	}
	if (foundReturn == false) {
		return NULL;
	}
}
TextObject* ObjectDataBase::getTextObject(std::string objID) {
	bool foundReturn = false;
	for (int i = textObjects.size() - 1; i >= 0; i--)
	{
		if (textObjects.at(i)->objectID == objID) {
			foundReturn = true;
			return textObjects.at(i);
		}
	}
	if (foundReturn == false) {
		return NULL;
	}
}
std::vector<DetailObject*> ObjectDataBase::getAllDetailObject(std::string objID) {
	std::vector<DetailObject*> objectList = { };
	for (int i = 0; i < detailedObjects.size(); i++)
	{
		if (detailedObjects.at(i)->objectID == objID) {
			objectList.push_back(detailedObjects.at(i));
		}
	}
	return objectList;
}
std::vector<TextObject*> ObjectDataBase::getAllTextObject(std::string objID) {
	std::vector<TextObject*> objectList = { };
	for (int i = 0; i < textObjects.size(); i++)
	{
		if (textObjects.at(i)->objectID == objID) {
			objectList.push_back(textObjects.at(i));
		}
	}
	return objectList;
}
std::vector<ButtonObject*> ObjectDataBase::getAllButtonObject(std::string objID) {
	std::vector<ButtonObject*> objectList = { };
	for (int i = 0; i < buttonObjects.size(); i++)
	{
		if (buttonObjects.at(i)->objectID == objID) {
			objectList.push_back(buttonObjects.at(i));
		}
	}
	return objectList;
}
std::vector<DetailObject*> ObjectDataBase::getListDetailObject(std::vector<std::string> objIDs) {
	std::vector<DetailObject*> objectList = { };
	for (int i = 0; i < objIDs.size(); i++)
	{
		objectList.push_back(getDetailObject(objIDs.at(i)));
	}
	return objectList;
}
std::vector<ButtonObject*> ObjectDataBase::getListButtonObject(std::vector<std::string> objIDs) {
	std::vector<ButtonObject*> objectList = { };
	for (int i = 0; i < objIDs.size(); i++)
	{
		objectList.push_back(getButtonObject(objIDs.at(i)));
	}
	return objectList;
}
std::vector<TextObject*> ObjectDataBase::getListTextObject(std::vector<std::string> objIDs) {
	std::vector<TextObject*> objectList = { };
	for (int i = 0; i < objIDs.size(); i++)
	{
		objectList.push_back(getTextObject(objIDs.at(i)));
	}
	return objectList;
}
DetailObject* ObjectDataBase::createDetailCopy(std::string objID, bool exact) {
	DetailObject* tempA = getDetailObject(objID);
	addObject(new DetailObject(*tempA));
	if (exact == false) {
		std::string newID = detailedObjects.at(detailedObjects.size() - 1)->objectID;
		std::string addition = "_copy";
		newID += addition;
		detailedObjects.at(detailedObjects.size() - 1)->objectID = newID;
	}
	return detailedObjects.at(detailedObjects.size() - 1);
}
ButtonObject* ObjectDataBase::createButtonCopy(std::string objID, bool exact) {
	ButtonObject* tempA = getButtonObject(objID);
	addObject(new ButtonObject(*tempA));
	if (exact == false) {
		std::string newID = buttonObjects.at(buttonObjects.size() - 1)->objectID;
		std::string addition = "_copy";
		newID += addition;
		buttonObjects.at(buttonObjects.size() - 1)->objectID = newID;
	}
	return buttonObjects.at(buttonObjects.size() - 1);
}
TextObject* ObjectDataBase::createTextCopy(std::string objID, bool exact) {
	TextObject* tempA = getTextObject(objID);
	addObject(new TextObject(*tempA));
	if (exact == false) {
		std::string newID = textObjects.at(textObjects.size() - 1)->objectID;
		std::string addition = "_copy";
		newID += addition;
		textObjects.at(textObjects.size() - 1)->objectID = newID;
	}
	return textObjects.at(textObjects.size() - 1);
}
bool ObjectDataBase::TopCollision(DetailObject* initialObject, DetailObject* otherObject) {
	int colide = false;

	if ((initialObject->yPos < otherObject->yPos + otherObject->height + 4) && (initialObject->yPos > otherObject->yPos) && (initialObject->xPos > otherObject->xPos) && (initialObject->xPos < otherObject->xPos + otherObject->width)) {
		colide = true;
	}
	if ((initialObject->yPos < otherObject->yPos + otherObject->height + 4) && (initialObject->yPos > otherObject->yPos) && (initialObject->xPos + initialObject->width > otherObject->xPos) && (initialObject->xPos + initialObject->width < otherObject->xPos + otherObject->width)) {
		colide = true;
	}
	if ((initialObject->yPos < otherObject->yPos + otherObject->height + 4) && (initialObject->yPos > otherObject->yPos) && (initialObject->xPos + (initialObject->width / 2) > otherObject->xPos) && (initialObject->xPos + (initialObject->width / 2) < otherObject->xPos + otherObject->width)) {
		colide = true;
	}

	return colide;
}
bool ObjectDataBase::BottomCollision(DetailObject* initialObject, DetailObject* otherObject) {
	int colide = false;

	if ((initialObject->yPos + initialObject->height > otherObject->yPos - 4) && (initialObject->yPos + initialObject->height < otherObject->yPos + otherObject->height) && (initialObject->xPos > otherObject->xPos) && (initialObject->xPos < otherObject->xPos + otherObject->width)) {
		colide = true;
	}
	if ((initialObject->yPos + initialObject->height > otherObject->yPos - 4) && (initialObject->yPos + initialObject->height < otherObject->yPos + otherObject->height) && (initialObject->xPos + initialObject->width > otherObject->xPos) && (initialObject->xPos + initialObject->width < otherObject->xPos + otherObject->width)) {
		colide = true;
	}
	if ((initialObject->yPos + initialObject->height > otherObject->yPos - 4) && (initialObject->yPos + initialObject->height < otherObject->yPos + otherObject->height) && (initialObject->xPos + (initialObject->width / 2) > otherObject->xPos) && (initialObject->xPos + (initialObject->width / 2) < otherObject->xPos + otherObject->width)) {
		colide = true;
	}


	return colide;
}
bool ObjectDataBase::LeftCollision(DetailObject* initialObject, DetailObject* otherObject) {
	int colide = false;

	if ((initialObject->xPos < otherObject->xPos + otherObject->width + 4 && initialObject->xPos > otherObject->xPos + 4) && (initialObject->yPos > otherObject->yPos && initialObject->yPos < otherObject->yPos + otherObject->height)) {
		colide = true;
	}
	if ((initialObject->xPos < otherObject->xPos + otherObject->width + 4 && initialObject->xPos > otherObject->xPos + 4) && (initialObject->yPos + initialObject->height > otherObject->yPos && initialObject->yPos + initialObject->height < otherObject->yPos + otherObject->height)) {
		colide = true;
	}

	return colide;
}
bool ObjectDataBase::RightCollision(DetailObject* initialObject, DetailObject* otherObject) {
	int colide = false;

	if (initialObject->xPos + initialObject->width < otherObject->xPos + otherObject->width - 4 && initialObject->xPos + initialObject->width > otherObject->xPos - 4 && ((initialObject->yPos + initialObject->height > otherObject->yPos && initialObject->yPos + initialObject->height < otherObject->yPos + otherObject->height))) {
		colide = true;
	}
	if (initialObject->xPos + initialObject->width < otherObject->xPos + otherObject->width - 4 && initialObject->xPos + initialObject->width > otherObject->xPos - 4 && ((initialObject->yPos > otherObject->yPos && initialObject->yPos < otherObject->yPos + otherObject->height))) {
		colide = true;
	}


	return colide;
}
bool ObjectDataBase::TopCollision(DetailObject* initialObject, ButtonObject* otherObject) {
	int colide = false;

	if ((initialObject->yPos < otherObject->yPos + otherObject->height + 4) && (initialObject->yPos > otherObject->yPos) && (initialObject->xPos > otherObject->xPos) && (initialObject->xPos < otherObject->xPos + otherObject->width)) {
		colide = true;
	}
	if ((initialObject->yPos < otherObject->yPos + otherObject->height + 4) && (initialObject->yPos > otherObject->yPos) && (initialObject->xPos + initialObject->width > otherObject->xPos) && (initialObject->xPos + initialObject->width < otherObject->xPos + otherObject->width)) {
		colide = true;
	}
	if ((initialObject->yPos < otherObject->yPos + otherObject->height + 4) && (initialObject->yPos > otherObject->yPos) && (initialObject->xPos + (initialObject->width / 2) > otherObject->xPos) && (initialObject->xPos + (initialObject->width / 2) < otherObject->xPos + otherObject->width)) {
		colide = true;
	}

	return colide;
}
bool ObjectDataBase::BottomCollision(DetailObject* initialObject, ButtonObject* otherObject) {
	int colide = false;

	if ((initialObject->yPos + initialObject->height > otherObject->yPos - 4) && (initialObject->yPos + initialObject->height < otherObject->yPos + otherObject->height) && (initialObject->xPos > otherObject->xPos) && (initialObject->xPos < otherObject->xPos + otherObject->width)) {
		colide = true;
	}
	if ((initialObject->yPos + initialObject->height > otherObject->yPos - 4) && (initialObject->yPos + initialObject->height < otherObject->yPos + otherObject->height) && (initialObject->xPos + initialObject->width > otherObject->xPos) && (initialObject->xPos + initialObject->width < otherObject->xPos + otherObject->width)) {
		colide = true;
	}
	if ((initialObject->yPos + initialObject->height > otherObject->yPos - 4) && (initialObject->yPos + initialObject->height < otherObject->yPos + otherObject->height) && (initialObject->xPos + (initialObject->width / 2) > otherObject->xPos) && (initialObject->xPos + (initialObject->width / 2) < otherObject->xPos + otherObject->width)) {
		colide = true;
	}


	return colide;
}
bool ObjectDataBase::LeftCollision(DetailObject* initialObject, ButtonObject* otherObject) {
	int colide = false;

	if ((initialObject->xPos < otherObject->xPos + otherObject->width + 4 && initialObject->xPos > otherObject->xPos + 4) && (initialObject->yPos > otherObject->yPos && initialObject->yPos < otherObject->yPos + otherObject->height)) {
		colide = true;
	}
	if ((initialObject->xPos < otherObject->xPos + otherObject->width + 4 && initialObject->xPos > otherObject->xPos + 4) && (initialObject->yPos + initialObject->height > otherObject->yPos && initialObject->yPos + initialObject->height < otherObject->yPos + otherObject->height)) {
		colide = true;
	}

	return colide;
}
bool ObjectDataBase::RightCollision(DetailObject* initialObject, ButtonObject* otherObject) {
	int colide = false;

	if (initialObject->xPos + initialObject->width < otherObject->xPos + otherObject->width - 4 && initialObject->xPos + initialObject->width > otherObject->xPos - 4 && ((initialObject->yPos + initialObject->height > otherObject->yPos && initialObject->yPos + initialObject->height < otherObject->yPos + otherObject->height))) {
		colide = true;
	}
	if (initialObject->xPos + initialObject->width < otherObject->xPos + otherObject->width - 4 && initialObject->xPos + initialObject->width > otherObject->xPos - 4 && ((initialObject->yPos > otherObject->yPos && initialObject->yPos < otherObject->yPos + otherObject->height))) {
		colide = true;
	}


	return colide;
}
bool ObjectDataBase::TopCollision(ButtonObject* initialObject, ButtonObject* otherObject) {
	int colide = false;

	if ((initialObject->yPos < otherObject->yPos + otherObject->height + 4) && (initialObject->yPos > otherObject->yPos) && (initialObject->xPos > otherObject->xPos) && (initialObject->xPos < otherObject->xPos + otherObject->width)) {
		colide = true;
	}
	if ((initialObject->yPos < otherObject->yPos + otherObject->height + 4) && (initialObject->yPos > otherObject->yPos) && (initialObject->xPos + initialObject->width > otherObject->xPos) && (initialObject->xPos + initialObject->width < otherObject->xPos + otherObject->width)) {
		colide = true;
	}
	if ((initialObject->yPos < otherObject->yPos + otherObject->height + 4) && (initialObject->yPos > otherObject->yPos) && (initialObject->xPos + (initialObject->width / 2) > otherObject->xPos) && (initialObject->xPos + (initialObject->width / 2) < otherObject->xPos + otherObject->width)) {
		colide = true;
	}

	return colide;
}
bool ObjectDataBase::BottomCollision(ButtonObject* initialObject, ButtonObject* otherObject) {
	int colide = false;

	if ((initialObject->yPos + initialObject->height > otherObject->yPos - 4) && (initialObject->yPos + initialObject->height < otherObject->yPos + otherObject->height) && (initialObject->xPos > otherObject->xPos) && (initialObject->xPos < otherObject->xPos + otherObject->width)) {
		colide = true;
	}
	if ((initialObject->yPos + initialObject->height > otherObject->yPos - 4) && (initialObject->yPos + initialObject->height < otherObject->yPos + otherObject->height) && (initialObject->xPos + initialObject->width > otherObject->xPos) && (initialObject->xPos + initialObject->width < otherObject->xPos + otherObject->width)) {
		colide = true;
	}
	if ((initialObject->yPos + initialObject->height > otherObject->yPos - 4) && (initialObject->yPos + initialObject->height < otherObject->yPos + otherObject->height) && (initialObject->xPos + (initialObject->width / 2) > otherObject->xPos) && (initialObject->xPos + (initialObject->width / 2) < otherObject->xPos + otherObject->width)) {
		colide = true;
	}


	return colide;
}
bool ObjectDataBase::LeftCollision(ButtonObject* initialObject, ButtonObject* otherObject) {
	int colide = false;

	if ((initialObject->xPos < otherObject->xPos + otherObject->width + 4 && initialObject->xPos > otherObject->xPos + 4) && (initialObject->yPos > otherObject->yPos && initialObject->yPos < otherObject->yPos + otherObject->height)) {
		colide = true;
	}
	if ((initialObject->xPos < otherObject->xPos + otherObject->width + 4 && initialObject->xPos > otherObject->xPos + 4) && (initialObject->yPos + initialObject->height > otherObject->yPos && initialObject->yPos + initialObject->height < otherObject->yPos + otherObject->height)) {
		colide = true;
	}

	return colide;
}
bool ObjectDataBase::RightCollision(ButtonObject* initialObject, ButtonObject* otherObject) {
	int colide = false;

	if (initialObject->xPos + initialObject->width < otherObject->xPos + otherObject->width - 4 && initialObject->xPos + initialObject->width > otherObject->xPos - 4 && ((initialObject->yPos + initialObject->height > otherObject->yPos && initialObject->yPos + initialObject->height < otherObject->yPos + otherObject->height))) {
		colide = true;
	}
	if (initialObject->xPos + initialObject->width < otherObject->xPos + otherObject->width - 4 && initialObject->xPos + initialObject->width > otherObject->xPos - 4 && ((initialObject->yPos > otherObject->yPos && initialObject->yPos < otherObject->yPos + otherObject->height))) {
		colide = true;
	}


	return colide;
}
bool ObjectDataBase::TopCollision(ButtonObject* initialObject, DetailObject* otherObject) {
	int colide = false;

	if ((initialObject->yPos < otherObject->yPos + otherObject->height + 4) && (initialObject->yPos > otherObject->yPos) && (initialObject->xPos > otherObject->xPos) && (initialObject->xPos < otherObject->xPos + otherObject->width)) {
		colide = true;
	}
	if ((initialObject->yPos < otherObject->yPos + otherObject->height + 4) && (initialObject->yPos > otherObject->yPos) && (initialObject->xPos + initialObject->width > otherObject->xPos) && (initialObject->xPos + initialObject->width < otherObject->xPos + otherObject->width)) {
		colide = true;
	}
	if ((initialObject->yPos < otherObject->yPos + otherObject->height + 4) && (initialObject->yPos > otherObject->yPos) && (initialObject->xPos + (initialObject->width / 2) > otherObject->xPos) && (initialObject->xPos + (initialObject->width / 2) < otherObject->xPos + otherObject->width)) {
		colide = true;
	}

	return colide;
}
bool ObjectDataBase::BottomCollision(ButtonObject* initialObject, DetailObject* otherObject) {
	int colide = false;

	if ((initialObject->yPos + initialObject->height > otherObject->yPos - 4) && (initialObject->yPos + initialObject->height < otherObject->yPos + otherObject->height) && (initialObject->xPos > otherObject->xPos) && (initialObject->xPos < otherObject->xPos + otherObject->width)) {
		colide = true;
	}
	if ((initialObject->yPos + initialObject->height > otherObject->yPos - 4) && (initialObject->yPos + initialObject->height < otherObject->yPos + otherObject->height) && (initialObject->xPos + initialObject->width > otherObject->xPos) && (initialObject->xPos + initialObject->width < otherObject->xPos + otherObject->width)) {
		colide = true;
	}
	if ((initialObject->yPos + initialObject->height > otherObject->yPos - 4) && (initialObject->yPos + initialObject->height < otherObject->yPos + otherObject->height) && (initialObject->xPos + (initialObject->width / 2) > otherObject->xPos) && (initialObject->xPos + (initialObject->width / 2) < otherObject->xPos + otherObject->width)) {
		colide = true;
	}


	return colide;
}
bool ObjectDataBase::LeftCollision(ButtonObject* initialObject, DetailObject* otherObject) {
	int colide = false;

	if ((initialObject->xPos < otherObject->xPos + otherObject->width + 4 && initialObject->xPos > otherObject->xPos + 4) && (initialObject->yPos > otherObject->yPos && initialObject->yPos < otherObject->yPos + otherObject->height)) {
		colide = true;
	}
	if ((initialObject->xPos < otherObject->xPos + otherObject->width + 4 && initialObject->xPos > otherObject->xPos + 4) && (initialObject->yPos + initialObject->height > otherObject->yPos && initialObject->yPos + initialObject->height < otherObject->yPos + otherObject->height)) {
		colide = true;
	}

	return colide;
}
bool ObjectDataBase::RightCollision(ButtonObject* initialObject, DetailObject* otherObject) {
	int colide = false;

	if (initialObject->xPos + initialObject->width < otherObject->xPos + otherObject->width - 4 && initialObject->xPos + initialObject->width > otherObject->xPos - 4 && ((initialObject->yPos + initialObject->height > otherObject->yPos && initialObject->yPos + initialObject->height < otherObject->yPos + otherObject->height))) {
		colide = true;
	}
	if (initialObject->xPos + initialObject->width < otherObject->xPos + otherObject->width - 4 && initialObject->xPos + initialObject->width > otherObject->xPos - 4 && ((initialObject->yPos > otherObject->yPos && initialObject->yPos < otherObject->yPos + otherObject->height))) {
		colide = true;
	}


	return colide;
}
bool ObjectDataBase::collisionDetailGroup(DetailObject* initialObject, std::vector<DetailObject*> otherObjectslist) {
	bool colide = false;

	for (int i = 0; i < otherObjectslist.size(); i++)
	{
		DetailObject* otherObject = otherObjectslist.at(i);
		if ((initialObject->xPos + initialObject->width > otherObject->xPos && initialObject->xPos < otherObject->xPos) && (initialObject->yPos + initialObject->height) > otherObject->yPos && (initialObject->yPos) < otherObject->yPos + otherObject->height) {
			colide = true;
		}
		if ((initialObject->xPos > otherObject->xPos) && (initialObject->xPos < otherObject->xPos + otherObject->width) && ((initialObject->yPos + initialObject->height) > otherObject->yPos && (initialObject->yPos) < otherObject->yPos + otherObject->height)) {
			colide = true;
		}

	}



	return colide;
}
bool ObjectDataBase::collisionDetailButtonGroup(DetailObject* initialObject, std::vector<ButtonObject*> otherObjectslist) {
	bool colide = false;

	for (int i = 0; i < otherObjectslist.size(); i++)
	{
		ButtonObject* otherObject = otherObjectslist.at(i);
		if ((initialObject->xPos + initialObject->width > otherObject->xPos && initialObject->xPos < otherObject->xPos) && (initialObject->yPos + initialObject->height) > otherObject->yPos && (initialObject->yPos) < otherObject->yPos + otherObject->height) {
			colide = true;
		}
		if ((initialObject->xPos > otherObject->xPos) && (initialObject->xPos < otherObject->xPos + otherObject->width) && ((initialObject->yPos + initialObject->height) > otherObject->yPos && (initialObject->yPos) < otherObject->yPos + otherObject->height)) {
			colide = true;
		}

	}



	return colide;
}
bool ObjectDataBase::collisionButtonGroup(ButtonObject* initialObject, std::vector<ButtonObject*> otherObjectslist) {
	bool colide = false;

	for (int i = 0; i < otherObjectslist.size(); i++)
	{
		ButtonObject* otherObject = otherObjectslist.at(i);
		if ((initialObject->xPos + initialObject->width > otherObject->xPos && initialObject->xPos < otherObject->xPos) && (initialObject->yPos + initialObject->height) > otherObject->yPos && (initialObject->yPos) < otherObject->yPos + otherObject->height) {
			colide = true;
		}
		if ((initialObject->xPos > otherObject->xPos) && (initialObject->xPos < otherObject->xPos + otherObject->width) && ((initialObject->yPos + initialObject->height) > otherObject->yPos && (initialObject->yPos) < otherObject->yPos + otherObject->height)) {
			colide = true;
		}

	}



	return colide;
}
bool ObjectDataBase::collisionButtonDetailGroup(ButtonObject* initialObject, std::vector<DetailObject*> otherObjectslist) {
	bool colide = false;

	for (int i = 0; i < otherObjectslist.size(); i++)
	{
		DetailObject* otherObject = otherObjectslist.at(i);
		if ((initialObject->xPos + initialObject->width > otherObject->xPos && initialObject->xPos < otherObject->xPos) && (initialObject->yPos + initialObject->height) > otherObject->yPos && (initialObject->yPos) < otherObject->yPos + otherObject->height) {
			colide = true;
		}
		if ((initialObject->xPos > otherObject->xPos) && (initialObject->xPos < otherObject->xPos + otherObject->width) && ((initialObject->yPos + initialObject->height) > otherObject->yPos && (initialObject->yPos) < otherObject->yPos + otherObject->height)) {
			colide = true;
		}

	}



	return colide;
}
bool ObjectDataBase::detailObjectCollisionGroup(std::string initial, std::vector<std::string> others) {
	bool colide = false;

	DetailObject* initialObject = getDetailObject(initial);
	std::vector<DetailObject*> otherObjectslist = {};
	for (int i = 0; i < others.size(); i++)
	{
		otherObjectslist.push_back(getDetailObject(others.at(i)));
	}
	for (int i = 0; i < otherObjectslist.size(); i++)
	{
		DetailObject* otherObject = otherObjectslist.at(i);
		if ((initialObject->xPos + initialObject->width > otherObject->xPos && initialObject->xPos < otherObject->xPos) && (initialObject->yPos + initialObject->height) > otherObject->yPos && (initialObject->yPos) < otherObject->yPos + otherObject->height) {
			colide = true;
		}
		if ((initialObject->xPos > otherObject->xPos) && (initialObject->xPos < otherObject->xPos + otherObject->width) && ((initialObject->yPos + initialObject->height) > otherObject->yPos && (initialObject->yPos) < otherObject->yPos + otherObject->height)) {
			colide = true;
		}

	}



	return colide;
}
bool ObjectDataBase::buttonObjectCollisionGroup(std::string initial, std::vector<std::string> others) {
	bool colide = false;

	ButtonObject* initialObject = getButtonObject(initial);
	std::vector<ButtonObject*> otherObjectslist = {};
	for (int i = 0; i < others.size(); i++)
	{
		otherObjectslist.push_back(getButtonObject(others.at(i)));
	}
	for (int i = 0; i < otherObjectslist.size(); i++)
	{
		ButtonObject* otherObject = otherObjectslist.at(i);
		if ((initialObject->xPos + initialObject->width > otherObject->xPos && initialObject->xPos < otherObject->xPos) && (initialObject->yPos + initialObject->height) > otherObject->yPos && (initialObject->yPos) < otherObject->yPos + otherObject->height) {
			colide = true;
		}
		if ((initialObject->xPos > otherObject->xPos) && (initialObject->xPos < otherObject->xPos + otherObject->width) && ((initialObject->yPos + initialObject->height) > otherObject->yPos && (initialObject->yPos) < otherObject->yPos + otherObject->height)) {
			colide = true;
		}

	}



	return colide;
}
void ObjectDataBase::directionalCollisionHandler(bool& top, bool& left, bool& bottom, bool& right, DetailObject* initialObject, DetailObject* otherObject) {
	top = TopCollision(initialObject, otherObject);
	left = LeftCollision(initialObject, otherObject);
	bottom = BottomCollision(initialObject, otherObject);
	right = RightCollision(initialObject, otherObject);
}
void ObjectDataBase::directionalCollisionHandler(bool& top, bool& left, bool& bottom, bool& right, DetailObject* initialObject, ButtonObject* otherObject) {
	top = TopCollision(initialObject, otherObject);
	left = LeftCollision(initialObject, otherObject);
	bottom = BottomCollision(initialObject, otherObject);
	right = RightCollision(initialObject, otherObject);
}
void ObjectDataBase::directionalCollisionHandler(bool& top, bool& left, bool& bottom, bool& right, ButtonObject* initialObject, ButtonObject* otherObject) {
	top = TopCollision(initialObject, otherObject);
	left = LeftCollision(initialObject, otherObject);
	bottom = BottomCollision(initialObject, otherObject);
	right = RightCollision(initialObject, otherObject);
}
void ObjectDataBase::directionalCollisionHandler(bool& top, bool& left, bool& bottom, bool& right, ButtonObject* initialObject, DetailObject* otherObject) {
	top = TopCollision(initialObject, otherObject);
	left = LeftCollision(initialObject, otherObject);
	bottom = BottomCollision(initialObject, otherObject);
	right = RightCollision(initialObject, otherObject);
}
bool ObjectDataBase::directionalCollisionDetailHandlerGroup(bool& up, bool& left, bool& down, bool& right, DetailObject* initialObject, std::vector<DetailObject*> otherObjects) {
	up = false;
	left = false;
	down = false;
	right = false;
	int overall = false;
	for (int i = 0; i < otherObjects.size(); i++)
	{
		if (up != true) {
			up = TopCollision(initialObject, otherObjects.at(i));

		}
		if (left != true) {
			left = LeftCollision(initialObject, otherObjects.at(i));

		}
		if (down != true) {
			down = BottomCollision(initialObject, otherObjects.at(i));

		}
		if (right != true) {
			right = RightCollision(initialObject, otherObjects.at(i));

		}
	}
	if (up == true || left == true || down == true || right == true) {
		overall = true;
	}
	return overall;
}
bool ObjectDataBase::directionalCollisionDetailButtonHandlerGroup(bool& up, bool& left, bool& down, bool& right, DetailObject* initialObject, std::vector<ButtonObject*> otherObjects) {
	up = false;
	left = false;
	down = false;
	right = false;
	int overall = false;
	for (int i = 0; i < otherObjects.size(); i++)
	{
		if (up != true) {
			up = TopCollision(initialObject, otherObjects.at(i));

		}
		if (left != true) {
			left = LeftCollision(initialObject, otherObjects.at(i));

		}
		if (down != true) {
			down = BottomCollision(initialObject, otherObjects.at(i));

		}
		if (right != true) {
			right = RightCollision(initialObject, otherObjects.at(i));

		}
	}
	if (up == true || left == true || down == true || right == true) {
		overall = true;
	}
	return overall;
}
bool ObjectDataBase::directionalCollisionButtonHandlerGroup(bool& up, bool& left, bool& down, bool& right, ButtonObject* initialObject, std::vector<ButtonObject*> otherObjects) {
	up = false;
	left = false;
	down = false;
	right = false;
	int overall = false;
	for (int i = 0; i < otherObjects.size(); i++)
	{
		if (up != true) {
			up = TopCollision(initialObject, otherObjects.at(i));

		}
		if (left != true) {
			left = LeftCollision(initialObject, otherObjects.at(i));

		}
		if (down != true) {
			down = BottomCollision(initialObject, otherObjects.at(i));

		}
		if (right != true) {
			right = RightCollision(initialObject, otherObjects.at(i));

		}
	}
	if (up == true || left == true || down == true || right == true) {
		overall = true;
	}
	return overall;
}
bool ObjectDataBase::directionalCollisionButtonDetailHandlerGroup(bool& up, bool& left, bool& down, bool& right, ButtonObject* initialObject, std::vector<DetailObject*> otherObjects) {
	up = false;
	left = false;
	down = false;
	right = false;
	int overall = false;
	for (int i = 0; i < otherObjects.size(); i++)
	{
		if (up != true) {
			up = TopCollision(initialObject, otherObjects.at(i));

		}
		if (left != true) {
			left = LeftCollision(initialObject, otherObjects.at(i));

		}
		if (down != true) {
			down = BottomCollision(initialObject, otherObjects.at(i));

		}
		if (right != true) {
			right = RightCollision(initialObject, otherObjects.at(i));

		}
	}
	if (up == true || left == true || down == true || right == true) {
		overall = true;
	}
	return overall;
}
void ObjectDataBase::changeText(std::string objID, std::string newText) {
	for (int i = textObjects.size() - 1; i >= 0; i--)
	{
		if (textObjects.at(i)->objectID == objID) {
			textObjects.at(i)->changeText(newText);
		}
	}
}

