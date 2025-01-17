#pragma once
#include "BlackboardData.h"

class Blackboard
{
private:
	BlackboardData* data;

public:
	Blackboard()
	{
		data = new BlackboardData();
	}

	inline BlackboardData *GetData() { return data; }
	inline void SetData(BlackboardData* _data) { data = _data; }
};

