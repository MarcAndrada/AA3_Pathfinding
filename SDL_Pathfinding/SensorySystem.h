#pragma once
#include "Vector2D.h"

class SensorySystem
{
private:
	float externalRadius, internalRadius, fordwardRadius, backwardRadius;
	float fordwardAngle, visionAngle;
	int visionPercentage;
public:
	SensorySystem();
	int CheckVision(Vector2D playerPos, Vector2D agentPos);
	int Update(Vector2D playerPos, Vector2D agentPos, float dtime);
};

