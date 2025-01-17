#pragma once
#include "FSMState.h"

class FSM 
{
private:
	FSMState* currentState;


	void ChangeState(FSMState* newState);

public:
	FSM();
	virtual void Update(Agent* agent, float dtime);
};

