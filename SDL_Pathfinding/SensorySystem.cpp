#include "SensorySystem.h"

SensorySystem::SensorySystem()
{
	internalRadius = 200.0f;
	externalRadius = 400.0f;
	backwardRadius = 50.0;
	fordwardRadius = 250.0f;
	fordwardAngle = 0.9f;
	visionAngle = 0.4f;
	visionPercentage = 0;
}

int SensorySystem::CheckVision(Vector2D playerPos, Vector2D agentPos)
{
	float playerDistance;
	playerDistance = Vector2D::Distance(agentPos,playerPos);
	if (playerDistance > externalRadius)
		return 0;

	float angleAgentPlayer = Vector2D::Dot(playerPos.Normalize(), agentPos.Normalize());
	if (angleAgentPlayer < 0)
	{
		if (playerDistance > backwardRadius)
			return 0;
		else 
			return 80;
	}

	if (playerDistance < fordwardRadius && angleAgentPlayer < fordwardAngle)
		return 100;

	if (angleAgentPlayer > visionAngle)
	{
		if (playerDistance > internalRadius)
			return 30;
		else
			return 80;
	}
	else if (playerDistance < internalRadius)
		return 30;

	return 0;
}

int SensorySystem::Update(Vector2D playerPos, Vector2D agentPos, float dtime)
{
	visionPercentage = CheckVision(playerPos, agentPos);

	if(visionPercentage==100) 
	{
		//Shoot
	}
	
}
