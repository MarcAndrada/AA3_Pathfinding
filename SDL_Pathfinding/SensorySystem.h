#pragma once
#include "Vector2D.h"

class SensorySystem
{
private:
	float externalRadius, internalRadius, fordwardRadius, backwardRadius;
	float fordwardAngle, visionAngle;
	int visionPercentage;
	Vector2D playerPos;

public:
	SensorySystem();
	int CheckVision(Vector2D agentPos);
};

