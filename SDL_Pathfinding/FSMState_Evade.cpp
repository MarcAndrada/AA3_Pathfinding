#include "FSMState_Evade.h"
#include "FSMState_Patrol.h"
#include "FSMState_Chase.h"
#include "Agent.h"

FSMState_Evade::FSMState_Evade()
	:FSMState() {}

void FSMState_Evade::Enter()
{

}

FSMState* FSMState_Evade::Update(Agent* agent, float dtime)
{
	currentTime += dtime;

	//agent->setTarget(ir en direccion opuesta al player);

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
