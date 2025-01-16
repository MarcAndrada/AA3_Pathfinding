#include "FSMState_Chase.h"
#include "FSMState_Patrol.h"
#include "FSMState_Evade.h"

void FSMState_Chase::Enter()
{
}

FSMState* FSMState_Chase::Update(float dtime)
{
	return new FSMState();
}

void FSMState_Chase::Exit()
{
}
