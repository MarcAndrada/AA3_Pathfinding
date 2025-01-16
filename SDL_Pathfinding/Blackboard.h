#include "Vector2D.h"

#pragma once
class Blackboard
{
private:
	bool hasGun;
	bool isVisible;
	Vector2D playerPosition;
	Vector2D lastPlayerPosition;

public:
	Blackboard();
	void UpdateAgentState(int _percentatgeVision);
	void ChooseBehaviour(int _percentatgeVision);
};

