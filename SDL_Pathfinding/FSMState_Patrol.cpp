#include "FSMState_Patrol.h"
#include "FSMState_Evade.h"
#include "FSMState_Chase.h"
#include "Agent.h"
#include "GridManager.h"
#include "PathFindingAlgorithm.h"

FSMState_Patrol::FSMState_Patrol()
	:FSMState() {}

void FSMState_Patrol::Enter()
{
	nearToTarget = true;
	
}

FSMState* FSMState_Patrol::Update(Agent* agent, float dtime)
{
	currentTime += dtime;
	if (nearToTarget) 
	{
		agent->clearPath();
		agent->setTarget(MAZE.GetRandomGridPoint());
		agent->getAlgorithm()->initAlgorithm(new Node(agent->getTarget(), 1));
		agent->setMaxSpeed(patrolVelocity, patrolForce);
	}

	nearToTarget = MAZE.GetGrid()->pix2cell(agent->getPosition()) == MAZE.GetGrid()->pix2cell(agent->getTarget());

	newState = nullptr;
	if (agent->getBlackboard()->GetData()->isVisible)
	{
		if(agent->getBlackboard()->GetData()->hasGun)
			newState = new FSMState_Evade();
		else
			newState = new FSMState_Chase();
	}
	
	return newState;
}

void FSMState_Patrol::Exit()
{

}
