#pragma once
#include "PathFindingAlgorithm.h"
class A :
    public PathFindingAlgorithm
{
public:
	A(Grid* _grid, Agent* _agent);
	~A() {};

	virtual void findPath(float dtime) override;
};

