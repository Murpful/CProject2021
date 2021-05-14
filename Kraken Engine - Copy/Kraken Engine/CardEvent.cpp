#include "CardEvent.h"
CardEvent::CardEvent(cardAction act, std::vector<int> actionData, const char* actAnim) {
	action = act;
	data = actionData;
	actionAnimation = actAnim;
}