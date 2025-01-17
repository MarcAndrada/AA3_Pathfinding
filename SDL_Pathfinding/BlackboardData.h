#pragma once
#include "Vector2D.h"

struct BlackboardData
{
	bool hasGun;
	bool isVisible;

	Vector2D realPlayerPosition;
	Vector2D lastSeenPlayerPosition;

	Vector2D agentPosition;

	int percentatgeVision;

	BlackboardData()
	{
		hasGun = false;
		isVisible = false;
		realPlayerPosition = Vector2D();
		lastSeenPlayerPosition = Vector2D();
		agentPosition = Vector2D();
		percentatgeVision = 0;
	}
};
