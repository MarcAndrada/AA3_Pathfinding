#pragma once
#include "FSMState.h"
#include "Vector2D.h"

class FSMState_Evade : public FSMState
{
private:
	Vector2D evadeDirection;
	Vector2D targetPosition;

	float targetOffset = 2000;

	float evadeVelocity = 250;
	float evadeForce = 200;
public:
	FSMState_Evade();
	virtual void Enter() override;
	virtual FSMState* Update(Agent* agent, float dtime) override;
	virtual void Exit() override;
};

