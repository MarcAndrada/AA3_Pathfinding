#pragma once
#include "Grid.h"
#include "Agent.h"
#include <queue>
#include <unordered_map>

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

	float heuristic(Vector2D v1, Vector2D v2);

protected:
	Grid* grid;
	std::vector<Node*> nodesToPrint;

	Node* start;
	Node* goal;
	bool goalCompleted;
	Node* currentNode;
	std::vector<Node*> path;

	std::queue<Node*> frontierQueue;
	std::priority_queue<std::pair<Node*, int>, std::vector<std::pair<Node*, int>>, PriorityQueueComparator> frontierPriorityQueue;
	std::vector<Connection*> cameFrom;
	std::unordered_map<Node*, int> costSoFar;

	Agent* agent;
};

