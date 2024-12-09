#pragma once
#include "Vector2D.h"
#include "Node.h"
class Connection
{
private:
	Node* fromNode;
	Node* toNode;
	float cost;

public:
	Connection(Node* _fromNode, Node* _toNode, float _cost);
	Node* getFromNode() { return fromNode; }
	Node* getToNode() { return toNode; }
	float getCost() { return cost; }
};

