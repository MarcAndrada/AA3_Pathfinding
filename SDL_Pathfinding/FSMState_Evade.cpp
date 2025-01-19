#include "FSMState_Evade.h"
#include "FSMState_Patrol.h"
#include "FSMState_Chase.h"
#include "Agent.h"
#include "PathFindingAlgorithm.h"
#include "GridManager.h"

FSMState_Evade::FSMState_Evade()
	:FSMState() {}

void FSMState_Evade::Enter()
{
	evadeDirection = Vector2D();
	currentTime = 0;
}

FSMState* FSMState_Evade::Update(Agent* agent, float dtime)
{
	currentTime += dtime;

	//std::cout << "Evade" << std::endl;
	//agent->setTarget(ir en direccion opuesta al player);

	/*std::cout << "TargetPos  " << targetPosition.x << "," << targetPosition.y
		<< " | CurrentPlayerPos = " << MAZE.GetGrid()->pix2cell(agent->getPosition()).x
		<< "," << MAZE.GetGrid()->pix2cell(agent->getPosition()).y << std::endl;*/

	if (evadeDirection == Vector2D() ||
		agent->getBlackboard()->GetData()->isVisible && 
		MAZE.GetGrid()->pix2cell(agent->getPosition()) == targetPosition)
	{
		agent->setMaxSpeed(evadeVelocity, evadeForce);

		evadeDirection = (agent->getPosition() - agent->getBlackboard()->GetData()->lastSeenPlayerPosition).Normalize();
		targetPosition = agent->getPosition() + (evadeDirection * targetOffset);
		while (!MAZE.GetGrid()->isValidCell(MAZE.GetGrid()->pix2cell(targetPosition)))
		{
			targetPosition -= evadeDirection * 0.5f;
		}

		targetPosition = MAZE.GetGrid()->pix2cell(targetPosition);

		agent->clearPath();
		agent->getAlgorithm()->initAlgorithm(new Node(targetPosition, 1));
	}

	newState = nullptr;
	if (agent->getBlackboard()->GetData()->isVisible && agent->getBlackboard()->GetData()->hasGun)
		newState = new FSMState_Chase();
	else
		newState = new FSMState_Patrol();
	
	if (currentTime >= timeToChange)
		return newState;
	return nullptr;
}

void FSMState_Evade::Exit()
{
}
