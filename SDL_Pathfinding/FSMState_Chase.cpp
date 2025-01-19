#include "FSMState_Chase.h"
#include "FSMState_Patrol.h"
#include "FSMState_Evade.h"
#include "Agent.h"
#include "GridManager.h"
#include "PlayerManager.h"
#include "PathFindingAlgorithm.h"

FSMState_Chase::FSMState_Chase()
	:FSMState() {}

void FSMState_Chase::Enter()
{
	currentTime = 0;
	lastPlayerSeenPos = Vector2D();
}

FSMState* FSMState_Chase::Update(Agent* agent, float dtime)
{
	/*std::cout << "Chase" << std::endl;*/
	if (lastPlayerSeenPos == Vector2D()) {
		lastPlayerSeenPos = MAZE.GetGrid()->pix2cell(agent->getBlackboard()->GetData()->lastSeenPlayerPosition);
		agent->clearPath();
		agent->getAlgorithm()->initAlgorithm(new Node(lastPlayerSeenPos, 1));
	}

	currentTime += dtime;
	
	//Si lo ve
	
	/*std::cout << "TargetPos  " << lastPlayerSeenPos.x << "," << lastPlayerSeenPos.y 
		<< " | CurrentPlayerPos = " << MAZE.GetGrid()->pix2cell(agent->getPosition()).x 
		<< "," << MAZE.GetGrid()->pix2cell(agent->getPosition()).y << std::endl;*/
	
	if (lastPlayerSeenPos == MAZE.GetGrid()->pix2cell(agent->getPosition()) && agent->getBlackboard()->GetData()->isVisible)
	{
		lastPlayerSeenPos = MAZE.GetGrid()->pix2cell(agent->getBlackboard()->GetData()->lastSeenPlayerPosition);
		agent->clearPath();
		agent->getAlgorithm()->initAlgorithm(new Node(lastPlayerSeenPos, 1));
	}

	newState = nullptr;
	if (agent->getBlackboard()->GetData()->isVisible && agent->getBlackboard()->GetData()->hasGun)
		newState = new FSMState_Evade();
	else if (!agent->getBlackboard()->GetData()->isVisible && lastPlayerSeenPos == MAZE.GetGrid()->pix2cell(agent->getPosition()))
		newState = new FSMState_Patrol();

	if (currentTime >= timeToChange)
		return newState;
	return nullptr;
}

void FSMState_Chase::Exit()
{
}
