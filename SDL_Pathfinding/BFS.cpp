#include "BFS.h"

BFS::BFS(Grid* _grid, Agent* _agent)
	: PathFindingAlgorithm(_grid, _agent) {}

void BFS::findPath(float dtime)
{
	if (frontierQueue.empty())
		return;

	Node* node = frontierQueue.front();
	frontierQueue.pop();

	if (node->getPosition() == goal->getPosition()) {
		goalCompleted = true;
		initPath();
		return; 
	}

	//Recorremos los vecinos
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

		if (!alreadyVisited && nextNode->getType() != 0)
		{
			frontierQueue.push(nextNode);
			cameFrom.push_back(new Connection(node, nextNode));
			nodesToPrint.push_back(nextNode);
		}
	}
}