#include "Blackboard.h"
#include "PlayerManager.h"

Blackboard::Blackboard()
{
	hasGun = false;
	isVisible = false;
	playerPosition = Vector2D();
	lastPlayerPosition = Vector2D();
}

void Blackboard::UpdateAgentState(int _percentatgeVision)
{
	playerPosition = PLAYER.GetPlayer().getPosition();
	hasGun = PLAYER.GetHasGun();

	ChooseBehaviour(_percentatgeVision);
}

void Blackboard::ChooseBehaviour(int _percentatgeVision)
{
	if (_percentatgeVision >= 100)
	{
		isVisible = true;
		lastPlayerPosition = playerPosition;
		if (hasGun)
		{
			//evade
		}
		else
		{
			//chase
		}
	}
	else if (_percentatgeVision > 50)
	{
		//patrol towards a direction
	}
	else
	{
		//patrol
	}
}
