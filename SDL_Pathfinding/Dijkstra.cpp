#include "Dijkstra.h"

Dijkstra::Dijkstra(Grid* _grid, Agent* _agent)
	: PathFindingAlgorithm(_grid, _agent) {}

void Dijkstra::findPath(float dtime)
{
	if (frontierPriorityQueue.empty())
		return;

	Node* node = frontierPriorityQueue.top().first;
	frontierPriorityQueue.pop();

	if (node->getPosition() == goal->getPosition()) {
		goalCompleted = true;
		initPath();
		return;
	}

	//Recorremos los vecinos
	for (Node* nextNode : grid->getNeighbours(node))
	{
		bool alreadyVisited = false;
		costSoFar.emplace(nextNode, nextNode->getType());
		float newCost = costSoFar[nextNode] + nextNode->getType();

		if (costSoFar.find(nextNode) == costSoFar.end() || newCost < costSoFar[nextNode])
		{
			costSoFar[nextNode] = newCost;
			frontierPriorityQueue.push({ nextNode, newCost });
			cameFrom.push_back(new Connection(node, nextNode));
		}
	}
}
