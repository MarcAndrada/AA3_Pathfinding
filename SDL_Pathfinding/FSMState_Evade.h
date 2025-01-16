#pragma once
#include "FSMState.h"
class FSMState_Evade : public FSMState
{
private:

public:
	virtual void Enter() override;
	virtual FSMState* Update(float dtime) override;
	virtual void Exit() override;
};

