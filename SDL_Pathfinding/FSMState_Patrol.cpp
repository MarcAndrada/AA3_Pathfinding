#include "FSMState_Patrol.h"
#include "FSMState_Evade.h"
#include "FSMState_Chase.h"

void FSMState_Patrol::Enter()
{
}

FSMState* FSMState_Patrol::Update(float dtime)
{
	return new FSMState();
}

void FSMState_Patrol::Exit()
{
}
