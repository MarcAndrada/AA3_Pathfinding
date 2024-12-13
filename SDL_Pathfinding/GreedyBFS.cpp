#include "GreedyBFS.h"

GreedyBFS::GreedyBFS(Grid* _grid, Agent* _agent)
	: PathFindingAlgorithm(_grid, _agent) {}

void GreedyBFS::findPath(float dtime)
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

	for (Node* nextNode : grid->getNeighbours(node))
	{
		bool alreadyVisited = false;
		for (Connection* connection : cameFrom)
		{
			if (connection->getToNode() == nextNode)
			{
				alreadyVisited = true;
				break;
			}
		}

		if (nextNode->getType() == 0 || alreadyVisited)
			continue;

		int priority = heuristic(goal->getPosition(), nextNode->getPosition());
		frontierPriorityQueue.push({ nextNode, priority });
		cameFrom.push_back(new Connection(node, nextNode));
		nodesToPrint.push_back(nextNode);
	}
}


