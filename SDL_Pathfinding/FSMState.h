#pragma once

class Agent;

class FSMState
{
protected:
	float currentTime;
	float timeToChange;
	FSMState *newState;

public:
	FSMState()
	{
		currentTime = 0.f;
		timeToChange = 5.f;
		newState = nullptr;
	}

	virtual void Enter() = 0;
	virtual FSMState* Update(Agent* agent, float dtime) = 0;
	virtual void Exit() = 0;
};

