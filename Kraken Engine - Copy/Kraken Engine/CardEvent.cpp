#include "CardEvent.h"
CardEvent::CardEvent(cardAction act, std::vector<int> actionData, const char* actAn) {
	action = act;
	data = actionData;
	actionAnim = actAn;
}