#include "FSMState_Patrol.h"
#include "FSMState_Evade.h"
#include "FSMState_Chase.h"
#include "Agent.h"

FSMState_Patrol::FSMState_Patrol()
	:FSMState() {}

void FSMState_Patrol::Enter()
{

}

FSMState* FSMState_Patrol::Update(Agent* agent, float dtime)
{
	currentTime += dtime;

	//agent->setTarget(punto random de la grid);

	newState = nullptr;
	if (agent->getBlackboard()->GetData()->isVisible)
	{
		if(agent->getBlackboard()->GetData()->hasGun)
			newState = new FSMState_Evade();
		else
			newState = new FSMState_Chase();
	}

	if (currentTime >= timeToChange)
		return newState;
	return nullptr;
}

void FSMState_Patrol::Exit()
{

}
