#pragma once
#include "FSMState.h"
class FSMState_Chase : public FSMState
{
private:

public:
	FSMState_Chase();
	virtual void Enter() override;
	virtual FSMState* Update(Agent* agent, float dtime) override;
	virtual void Exit() override;
};

