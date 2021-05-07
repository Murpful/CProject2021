#include "Event.h"

Event::Event(std::string id) {
	ID = id;
}
Event::Event(std::string id,std::vector<int> numbs) {
	ID = id;
	integers = numbs;
}