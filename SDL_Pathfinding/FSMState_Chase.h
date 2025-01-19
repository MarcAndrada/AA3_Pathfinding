#pragma once
#include "FSMState.h"
#include "Vector2D.h"
class FSMState_Chase : public FSMState
{
private:
	Vector2D lastPlayerSeenPos;

	float chaseVelocity = 125;
	float chaseForce = 100;
public:
	FSMState_Chase();
	virtual void Enter() override;
	virtual FSMState* Update(Agent* agent, float dtime) override;
	virtual void Exit() override;
};

