#include "FSM.h"

void FSM::ChangeState(FSMState* newState)
{
	currentState->Exit();
	currentState = newState;
	currentState->Enter();
}

void FSM::Update(float dtime)
{
	FSMState* newState = currentState->Update(dtime);
	if (newState != nullptr)
		ChangeState(newState);
}
