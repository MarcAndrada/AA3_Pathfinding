#include "BFS.h"
#include "Grid.h"

BFS::~BFS()
{
}

void BFS::initAlgorithm(Node* _start, Node* _goal)
{
	start = _start;
	goal = _goal;
	goalCompleted = false;
}

void BFS::initFinding()
{
	frontier.push(start);
	cameFrom.push_back(new Connection(start, start));
}

void BFS::findPath(float dtime)
{
	Node* currentNode = frontier.front();
	frontier.pop();

	if (currentNode == goal) {
		goalCompleted = true;
		return; 
	}

	//Recorremos los vecinos
	for (Node* nextNode : grid->getNeighbours(currentNode)) 
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
			frontier.push(nextNode);
			cameFrom.push_back(new Connection(currentNode, nextNode));
		}
	}

	//Reconstruimos el camino
	currentNode = goal;
	std::vector<Node*> path = { currentNode };
	while (currentNode != start) {
		currentNode = cameFrom[cameFrom.size() - 1]->getFromNode();
		path.push_back(currentNode);
	}
}
