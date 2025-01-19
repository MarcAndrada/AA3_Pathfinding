#pragma once
#include "FSMState.h"
#include "Vector2D.h"
class FSMState_Chase : public FSMState
{
private:
	Vector2D lastPlayerSeenPos;
public:
	FSMState_Chase();
	virtual void Enter() override;
	virtual FSMState* Update(Agent* agent, float dtime) override;
	virtual void Exit() override;
};

