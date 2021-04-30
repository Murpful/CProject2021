#include "PlayerCard.h"
PlayerCard::PlayerCard(std::string title, std::vector<CardEvent> acts,int cool, const char* image) {
	cardTitle = title;
	cardEvents = acts;
	cardImage = image;
	coolDown = cool;
}
std::vector<CardEvent> PlayerCard::getCardEvent() {
	return cardEvents;
}