#pragma once
#include "DecisionMakingAlgorithm.h"
#include "FSMState.h"

class FSM : public DecisionMakingAlgorithm
{
private:
	FSMState* currentState;

	void ChangeState(FSMState* newState);

public:
	virtual void Update(float dtime) override;
};

