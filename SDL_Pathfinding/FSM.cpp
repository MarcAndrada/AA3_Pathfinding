#include "FSM.h"
#include "FSMState_Patrol.h"

void FSM::ChangeState(FSMState* newState)
{
	currentState->Exit();
	currentState = newState;
	currentState->Enter();
}

FSM::FSM()
{
	currentState = new FSMState_Patrol();
	currentState->Enter();
}

void FSM::Update(Agent *agent, float dtime)
{
	FSMState* newState = currentState->Update(agent, dtime);
	if (newState != nullptr)
		ChangeState(newState);
}
