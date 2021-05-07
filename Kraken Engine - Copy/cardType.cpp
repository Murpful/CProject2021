#include "cardType.h"

void CardType::act() {
	if (cardName == "Atk") {

	}
	if (cardName == "Ddg") {

	}
}
CardType::CardType(std::string setCardName) {
	if (setCardName == "Atk") {
		cardName = setCardName;
		cooldown = 1;
	}
	if(setCardName == "Ddg") {
		cardName = setCardName;
		cooldown = 1;
	}
}