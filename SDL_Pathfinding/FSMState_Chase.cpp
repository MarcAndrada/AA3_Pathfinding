#include "FSMState_Chase.h"
#include "FSMState_Patrol.h"
#include "FSMState_Evade.h"
#include "Agent.h"

FSMState_Chase::FSMState_Chase()
	:FSMState() {}

void FSMState_Chase::Enter()
{

}

FSMState* FSMState_Chase::Update(Agent* agent, float dtime)
{
	currentTime += dtime;

	agent->setTarget(Vector2D(agent->getBlackboard()->GetData()->lastSeenPlayerPosition));

	newState = nullptr;
	if (agent->getBlackboard()->GetData()->isVisible && agent->getBlackboard()->GetData()->hasGun)
		newState = new FSMState_Evade();
	else
		newState = new FSMState_Patrol();

	if (currentTime >= timeToChange)
		return newState;
	return nullptr;
}

void FSMState_Chase::Exit()
{
}
