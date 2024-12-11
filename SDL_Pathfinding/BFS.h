#pragma once
#include "Agent.h"
#include "Vector2D.h"
#include <queue>

class BFS :
	public Agent::PathFindingAlgorithm
{
public:
	BFS(Grid* _grid) : PathFindingAlgorithm(_grid) {}
	~BFS();
	void initAlgorithm(Node* _start, Node* _goal);
	void initFinding();
	void findPath(float dtime);

private:
	Node* start;
	Node* goal;
	bool goalCompleted;

	std::queue<Node*> frontier;
	std::vector<Connection*> cameFrom;

};

