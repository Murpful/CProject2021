#include "CardEvent.h"
CardEvent::CardEvent(cardAction act, std::vector<int> actionData) {
	action = act;
	data = actionData;
}