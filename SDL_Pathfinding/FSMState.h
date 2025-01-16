#pragma once
class FSMState
{
private:

public:
	FSMState() = default;
	virtual void Enter() {};
	virtual FSMState* Update(float dtime) {};
	virtual void Exit() {};
};

