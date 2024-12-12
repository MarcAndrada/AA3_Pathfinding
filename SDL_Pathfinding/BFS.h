#pragma once
#include "PathFindingAlgorithm.h"

class BFS :
	public PathFindingAlgorithm
{
public:
	BFS(Grid* _grid, Agent* _agent);
	~BFS() {};
	
	virtual void findPath(float dtime) override;
};

