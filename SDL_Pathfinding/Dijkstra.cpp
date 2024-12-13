#include "Dijkstra.h"

Dijkstra::Dijkstra(Grid* _grid, Agent* _agent)
	: PathFindingAlgorithm(_grid, _agent) {}

void Dijkstra::findPath(float dtime)
{
	if (frontierPriorityQueue.empty())
		return;

	Node* node = frontierPriorityQueue.top().first;

	if (node->getPosition() == goal->getPosition()) {
		goalCompleted = true;
		initPath();
		return;
	}

	//Recorremos los vecinos
	for (Node* nextNode : grid->getNeighbours(node))
	{
		costSoFar.emplace(node, node->getType());
		float newCost = costSoFar[node] + nextNode->getType();

		if (costSoFar.find(nextNode) == costSoFar.end() || newCost < costSoFar[nextNode])
		{
			costSoFar.emplace(nextNode, newCost);
			frontierPriorityQueue.push({ nextNode, newCost });
			cameFrom.push_back(new Connection(node, nextNode));
		}
	}
}
