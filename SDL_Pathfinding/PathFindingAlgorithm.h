#pragma once
#include "Grid.h"
#include <queue>

struct PriorityQueueComparator {
	bool operator()(const std::pair<Node*, int>& a, const std::pair<Node*, int>& b) const {
		return a.second > b.second;
	}
};

class PathFindingAlgorithm
{
public:
	PathFindingAlgorithm(Grid* _grid, Agent* _agent);
	virtual ~PathFindingAlgorithm() {};

	void initAlgorithm(Node* _goal);
	void initFinding();
	void initPath();
	virtual void findPath(float dtime) = 0;
	void pathFinded();
	
	virtual void update(float dtime);
	virtual void draw();

protected:
	Grid* grid;
	std::vector<Node*> nodesToPrint;

	Node* start;
	Node* goal;
	bool goalCompleted;
	Node* currentNode;
	std::vector<Node*> path;

	std::queue<Node*> frontier;
	std::vector<Connection*> cameFrom;

	Agent* agent;
};

