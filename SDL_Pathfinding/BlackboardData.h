#pragma once
#include "Vector2D.h"

struct BlackboardData
{
	bool hasGun;
	bool isVisible;

	Vector2D lastSeenPlayerPosition;

	Vector2D agentPosition;
	Vector2D agentForward;

	int percentatgeVision;

	BlackboardData()
	{
		hasGun = false;
		isVisible = false;
		lastSeenPlayerPosition = Vector2D();
		agentPosition = Vector2D();
		agentForward = Vector2D(1, 0);
		percentatgeVision = 0;
	}
};
