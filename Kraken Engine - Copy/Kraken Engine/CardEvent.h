#pragma once
#include <vector>
enum cardAction
{
	attack,heal, move
};
class CardEvent
{
public:
	cardAction action;
	std::vector<int> data;
	CardEvent(cardAction, std::vector<int>);
};

/*move event definition:
* First Number: movement type:
* 0- move target
* 1- wander random
* Second Number: 
* 0- within range
* Thrid Number:
* 0- closest range
* 
* 
* 
* 
* 
* 
* */
