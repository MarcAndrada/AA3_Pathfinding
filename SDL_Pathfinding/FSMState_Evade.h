#pragma once
#include "FSMState.h"
class FSMState_Evade : public FSMState
{
private:

public:
	FSMState_Evade();
	virtual void Enter() override;
	virtual FSMState* Update(Agent* agent, float dtime) override;
	virtual void Exit() override;
};

