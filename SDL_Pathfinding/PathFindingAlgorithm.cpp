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
	frontier = std::queue<Node*>();

	initFinding();
}

void PathFindingAlgorithm::initFinding()
{
	frontier.push(start);
	cameFrom.push_back(new Connection(start, start));
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
};

