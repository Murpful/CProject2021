#include "PlayerCard.h"
PlayerCard::PlayerCard(std::string title, std::vector<CardEvent> acts, const char* image) {
	cardTitle = title;
	cardEvents = acts;
	cardImage = image;
}
std::vector<CardEvent> PlayerCard::getCardEvent() {
	return cardEvents;
}