#pragma once
#include "PathFindingAlgorithm.h"
class GreedyBFS :
    public PathFindingAlgorithm
{
public:
	GreedyBFS(Grid* _grid, Agent* _agent);
	~GreedyBFS() {};

	virtual void findPath(float dtime) override;
};

