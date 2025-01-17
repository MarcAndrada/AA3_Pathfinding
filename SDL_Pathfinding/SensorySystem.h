#pragma once
#include "Vector2D.h"
#include "BlackboardData.h"

class SensorySystem
{
private:
	float externalRadius, internalRadius, fordwardRadius, backwardRadius;
	float fordwardAngle, visionAngle;
	int visionPercentage;
	Vector2D playerPos;

	BlackboardData *data;

public:
	SensorySystem();
	int CheckVision();
	void Update(Vector2D agentPos, Vector2D playerPos, float dtime);

	inline BlackboardData* GetData() { return data; }
};

