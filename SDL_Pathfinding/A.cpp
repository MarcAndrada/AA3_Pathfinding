#include "A.h"

A::A(Grid* _grid, Agent* _agent)
	: PathFindingAlgorithm(_grid, _agent) {}


void A::findPath(float dtime)
{
	if (frontierPriorityQueue.empty())
		return;

	Node* node = frontierPriorityQueue.top().first;

	if (node->getPosition() == goal->getPosition()) {
		goalCompleted = true;
		initPath();
		return;
	}

	for (Node* nextNode : grid->getNeighbours(node))
	{
		costSoFar.emplace(node, node->getType());
		float newCost = costSoFar[node] + nextNode->getType();

		if (costSoFar.find(nextNode) == costSoFar.end() || newCost < costSoFar[nextNode])
		{
			costSoFar.emplace(nextNode, newCost);
			int priority = newCost + heuristic(goal->getPosition(), nextNode->getPosition());
			frontierPriorityQueue.push({ nextNode, priority });
			cameFrom.push_back(new Connection(node, nextNode));
		}
	}
}
