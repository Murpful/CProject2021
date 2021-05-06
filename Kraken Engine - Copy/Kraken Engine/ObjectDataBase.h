#pragma once
#include "TextObject.h"




class ObjectDataBase
{
public:
	int xoff = 10;
	int yoff = 10;
	std::vector<DetailObject*> detailedObjects = {};
	std::vector<TextObject*> textObjects = {};
	std::vector<ButtonObject*> buttonObjects = {};
	std::vector<KeyInputObject*> keyInputObjects = {};
	std::vector<AdvancedButtonObject*> advancedButtonObjects = {};
	std::vector<AdvancedHexagonalButtonObject*> advancedHexagonalButtonObjects = {};
	void addObject(DetailObject* newObject);
	void addObject(TextObject* newObject);
	void addObject(ButtonObject* newObject);
	void addObject(KeyInputObject* newObject);
	void addObject(AdvancedButtonObject* newObject);//
	void addObject(AdvancedHexagonalButtonObject* newObject);//
	void deleteDetailObject(int at);
	void deleteTextObject(int at);
	void deleteButtonObject(int at);
	void deleteAdvancedButtonObject(int at);//
	void deleteAdvancedHexagonalButtonObject(int at);//
	void deleteKeyInputObject(int at);
	void deleteAll();//
	void deleteAllDetailObject();
	void deleteAllButtonObject();
	void deleteAllAdvancedButtonObject();//
	void deleteAllAdvancedHexagonalButtonObject();//
	void deleteAllTextObject();
	void deleteAllKeyInputObject();
	void updateObjects();//
	void renderObjects();//
	void deleteObject(std::string objectID);//
	void deleteDetailObject(std::string objectID);
	void deleteButtonObject(std::string objectID);
	void deleteAdvancedButtonObject(std::string objectID);//
	void deleteAdvancedHexagonalButtonObject(std::string objectID);//
	void deleteTextObject(std::string objectID);
	void deleteKeyInputObject(std::string objectID);
	bool ObjectCollide(DetailObject* initialObject, DetailObject* otherObject);
	bool ObjectCollide(DetailObject* initialObject, ButtonObject* otherObject);
	bool ObjectCollide(ButtonObject* initialObject, ButtonObject* otherObject);
	bool ObjectCollide(ButtonObject* initialObject, DetailObject* otherObject);
	bool DetailObjectCollide(std::string thisobjID, std::string otherobjID);
	bool ButtonObjectCollide(std::string thisobjID, std::string otherobjID);
	bool DetectObject(std::string objectID);
	bool DetectDetailObject(std::string objectID);
	bool DetectButtonObject(std::string objectID);
	bool DetectAdvancedButtonObject(std::string objectID);//
	bool DetectAdvancedHexagonalButtonObject(std::string objectID);//
	bool DetectTextObject(std::string objectID);
	bool DetectKeyInputObject(std::string objectID);
	KeyInputObject* getKeyInputObject(std::string objectID);
	DetailObject* getDetailObject(std::string objectID);
	ButtonObject* getButtonObject(std::string objectID);
	AdvancedButtonObject* getAdvancedButtonObject(std::string objectID);//
	AdvancedHexagonalButtonObject* getAdvancedHexagonalButtonObject(std::string objectID);//
	TextObject* getTextObject(std::string objectID);
	std::vector<DetailObject*> getAllDetailObject(std::string objectID);
	std::vector<ButtonObject*> getAllButtonObject(std::string objectID);
	std::vector<TextObject*> getAllTextObject(std::string objectID);
	std::vector<DetailObject*> getListDetailObject(std::vector<std::string> objectIDs);
	std::vector<ButtonObject*> getListButtonObject(std::vector<std::string> objectIDs);
	std::vector<TextObject*> getListTextObject(std::vector<std::string> objectIDs);
	DetailObject* createDetailCopy(std::string objID, bool exact = false);
	ButtonObject* createButtonCopy(std::string objID, bool exact = false);
	TextObject* createTextCopy(std::string objID, bool exact = false);
	bool TopCollision(DetailObject* initialObject, DetailObject* otherObject);
	bool BottomCollision(DetailObject* initialObject, DetailObject* otherObject);
	bool LeftCollision(DetailObject* initialObject, DetailObject* otherObject);
	bool RightCollision(DetailObject* initialObject, DetailObject* otherObject);
	bool TopCollision(DetailObject* initialObject, ButtonObject* otherObject);
	bool BottomCollision(DetailObject* initialObject, ButtonObject* otherObject);
	bool LeftCollision(DetailObject* initialObject, ButtonObject* otherObject);
	bool RightCollision(DetailObject* initialObject, ButtonObject* otherObject);
	bool TopCollision(ButtonObject* initialObject, ButtonObject* otherObject);
	bool BottomCollision(ButtonObject* initialObject, ButtonObject* otherObject);
	bool LeftCollision(ButtonObject* initialObject, ButtonObject* otherObject);
	bool RightCollision(ButtonObject* initialObject, ButtonObject* otherObject);
	bool TopCollision(ButtonObject* initialObject, DetailObject* otherObject);
	bool BottomCollision(ButtonObject* initialObject, DetailObject* otherObject);
	bool LeftCollision(ButtonObject* initialObject, DetailObject* otherObject);
	bool RightCollision(ButtonObject* initialObject, DetailObject* otherObject);
	bool collisionDetailGroup(DetailObject* initialObject, std::vector<DetailObject*> otherObjects);
	bool collisionDetailButtonGroup(DetailObject* initialObject, std::vector<ButtonObject*> otherObjects);
	bool collisionButtonGroup(ButtonObject* initialObject, std::vector<ButtonObject*> otherObjects);
	bool collisionButtonDetailGroup(ButtonObject* initialObject, std::vector<DetailObject*> otherObjects);
	bool detailObjectCollisionGroup(std::string initialObject, std::vector<std::string> otherObjects);
	bool buttonObjectCollisionGroup(std::string initialObject, std::vector<std::string> otherObjects);
	void directionalCollisionHandler(bool& up, bool& left, bool& down, bool& right, DetailObject* initialObject, DetailObject* otherObject);
	void directionalCollisionHandler(bool& up, bool& left, bool& down, bool& right, DetailObject* initialObject, ButtonObject* otherObject);
	void directionalCollisionHandler(bool& up, bool& left, bool& down, bool& right, ButtonObject* initialObject, ButtonObject* otherObject);
	void directionalCollisionHandler(bool& up, bool& left, bool& down, bool& right, ButtonObject* initialObject, DetailObject* otherObject);
	bool directionalCollisionDetailHandlerGroup(bool& up, bool& left, bool& down, bool& right, DetailObject* initialObject, std::vector<DetailObject*> otherObjects);
	bool directionalCollisionDetailButtonHandlerGroup(bool& up, bool& left, bool& down, bool& right, DetailObject* initialObject, std::vector<ButtonObject*> otherObjects);
	bool directionalCollisionButtonHandlerGroup(bool& up, bool& left, bool& down, bool& right, ButtonObject* initialObject, std::vector<ButtonObject*> otherObjects);
	bool directionalCollisionButtonDetailHandlerGroup(bool& up, bool& left, bool& down, bool& right, ButtonObject* initialObject, std::vector<DetailObject*> otherObjects);
	void changeText(std::string, std::string);
};


