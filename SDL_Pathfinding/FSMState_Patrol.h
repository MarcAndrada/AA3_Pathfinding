#pragma once
#include "FSMState.h"
class FSMState_Patrol : public FSMState
{
private:

public:
	FSMState_Patrol();
	virtual void Enter() override;
	virtual FSMState* Update(Agent* agent, float dtime) override;
	virtual void Exit() override;
};

