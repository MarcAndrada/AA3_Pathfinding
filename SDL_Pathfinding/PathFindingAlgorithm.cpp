#include "PathFindingAlgorithm.h"

PathFindingAlgorithm::PathFindingAlgorithm(Grid* _grid, Agent* _agent)
{
	grid = _grid;
	agent = _agent;
}

void PathFindingAlgorithm::initAlgorithm(Node* _goal)
{
	start = new Node(grid->pix2cell(agent->getPosition()), 1);
	goal = _goal;
	goalCompleted = false;
	currentNode = nullptr;
	nodesToPrint.clear();
	cameFrom.clear();
	frontierQueue = std::queue<Node*>();
	frontierPriorityQueue = std::priority_queue<std::pair<Node*, int>, std::vector<std::pair<Node*, int>>, PriorityQueueComparator>();
	costSoFar.clear();

	initFinding();
}

void PathFindingAlgorithm::initFinding()
{
	frontierQueue.push(start);
	frontierPriorityQueue.push({start, heuristic(goal->getPosition(), start->getPosition())});
	cameFrom.push_back(new Connection(start, start));
	costSoFar.emplace(start, 0);
}

void PathFindingAlgorithm::initPath()
{
	currentNode = goal;
	path = { currentNode };
}

void PathFindingAlgorithm::pathFinded()
{
	//Reconstruimos el camino
	if (currentNode->getPosition() != start->getPosition())
	{
		for (Connection* connection : cameFrom)
		{
			if (connection->getToNode()->getPosition() == currentNode->getPosition())
			{
				path.push_back(connection->getToNode());
				currentNode = connection->getFromNode();
				break;
			}
		}
	}
	else
	{
		std::reverse(path.begin(), path.end());
		for (Node* node : path)
		{
			Vector2D position = grid->cell2pix(node->getPosition());
			agent->addPathPoint(position);
			std::cout << nodesToPrint.size();

		}
		path.clear();
	}
}

void PathFindingAlgorithm::update(float dtime)
{
	if (!goalCompleted)
	{
		findPath(dtime);
		return;
	}

	pathFinded();
}

void PathFindingAlgorithm::draw()
{
	for (Node* node : nodesToPrint)
	{
		Vector2D pos = grid->cell2pix(node->getPosition());
		node->draw(pos);
	}
}

float PathFindingAlgorithm::heuristic(Vector2D v1, Vector2D v2)
{
	float dx = abs(v1.x - v2.x);
	float dy = abs(v1.y - v2.y);
	return (dx + dy);
}


