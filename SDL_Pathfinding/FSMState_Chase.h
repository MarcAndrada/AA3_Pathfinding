#pragma once
#include "FSMState.h"
class FSMState_Chase : public FSMState
{
private:

public:
	virtual void Enter() override;
	virtual FSMState* Update(float dtime) override;
	virtual void Exit() override;
};

