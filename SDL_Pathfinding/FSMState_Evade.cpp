#include "FSMState_Evade.h"
#include "FSMState_Patrol.h"
#include "FSMState_Chase.h"

void FSMState_Evade::Enter()
{
}

FSMState* FSMState_Evade::Update(float dtime)
{
	return new FSMState();
}

void FSMState_Evade::Exit()
{
}
