#pragma once
#include "FSMState.h"
class FSMState_Patrol : public FSMState
{
private:
	bool nearToTarget;

	float patrolVelocity = 50;
	float patrolForce = 50;
public:
	FSMState_Patrol();
	virtual void Enter() override;
	virtual FSMState* Update(Agent* agent, float dtime) override;
	virtual void Exit() override;
};

