#include "Component.h"
Component::Component(stats chess, std::vector<int> checkers, moveTypes monopoly = random)
{
	witch = chess;
	if (chess == moveStats)
	{
		crtrMvmt = monopoly;
	}
	value = checkers;
}
