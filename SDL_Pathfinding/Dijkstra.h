#pragma once
#include "PathFindingAlgorithm.h"
class Dijkstra : public PathFindingAlgorithm
{
public:
	Dijkstra(Grid* _grid, Agent* _agent);
	~Dijkstra() {};

	virtual void findPath(float dtime) override;
};

