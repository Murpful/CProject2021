#pragma once
#include <vector>
#include <string>
class Event
{
public:
	std::string ID;
	std::vector<int> integers;
	Event(std::string,std::vector<int>);
	Event(std::string);
};

