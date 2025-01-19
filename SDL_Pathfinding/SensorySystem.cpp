#include "SensorySystem.h"
#include "PlayerManager.h"
#include "GridManager.h"

SensorySystem::SensorySystem()
{
	internalRadius = 150.0f;
	externalRadius = 300.0f;
	backwardRadius = 75.f;
	fordwardRadius = 200.0f;

	fordwardAngle = 30.f;
	visionAngle = 90.f;

	visionPercentage = 0;
	playerPos = Vector2D();
	data = new BlackboardData();
}

int SensorySystem::CheckVision()
{
	playerPos = PLAYER.GetPlayer()->getPosition();

	float playerDistance;
	playerDistance = Vector2D::Distance(data->agentPosition,playerPos);
	if (playerDistance > externalRadius)
		return 0;	

	
	Vector2D playerToAgentDirection = (playerPos - data->agentPosition).Normalize();

	float angleAgentPlayer = Vector2D::Dot(data->agentForward, playerToAgentDirection);
	if (angleAgentPlayer < 0)
	{
		if (playerDistance > backwardRadius)
			return 0;
		else 
			return 80;
	}

	if (playerDistance < fordwardRadius && angleAgentPlayer < fordwardAngle)
		return 100;

	if (angleAgentPlayer < visionAngle)
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

void SensorySystem::Update(Vector2D agentPos, Vector2D agentVelocity, Vector2D playerPos, float dtime)
{
	data->agentPosition = agentPos;

	Vector2D currentPlayerForward = agentVelocity.Normalize();

	if (currentPlayerForward == Vector2D(0, 0))
		currentPlayerForward = data->agentForward;

	data->agentForward = currentPlayerForward;

	data->percentatgeVision = CheckVision();
	data->isVisible = data->percentatgeVision > 0 && CheckWallsBetweenAgentAndPlayer(agentPos);

	if(data->isVisible)
		data->lastSeenPlayerPosition = playerPos;
}


bool SensorySystem::CheckWallsBetweenAgentAndPlayer(Vector2D agentPosition)
{
	Vector2D posToCheck = agentPosition;
	Vector2D agentToPlayerDirection = (PLAYER.GetPlayer()->getPosition() - posToCheck).Normalize();
	float distanceFromPlayer = Vector2D::Distance(PLAYER.GetPlayer()->getPosition(), agentPosition);

	while (Vector2D::Distance(posToCheck, agentPosition) < externalRadius &&
		Vector2D::Distance(posToCheck, agentPosition) < distanceFromPlayer)
	{
		if (!MAZE.GetGrid()->isValidCell(MAZE.GetGrid()->pix2cell(posToCheck))) 
		{
			//std::cout << "Hay una pared a una distancia de " << Vector2D::Distance(posToCheck, agentPosition) << std::endl;
			return false;
		}
		posToCheck += agentToPlayerDirection * checkCellOffset;

	}
	
	//std::cout << "No hay paredes en medio" << std::endl;
	return true;
}
