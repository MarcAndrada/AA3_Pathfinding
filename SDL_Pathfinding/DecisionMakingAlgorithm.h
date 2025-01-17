#pragma once
#include "Blackboard.h"

class DecisionMakingAlgorithm
{
public:
	virtual void Update(Blackboard* blackboard, Vector2D* target, float dtime) = 0;
};
