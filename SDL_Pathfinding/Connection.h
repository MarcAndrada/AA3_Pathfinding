#pragma once
#include "Vector2D.h"
#include "Node.h"
class Connection
{
private:
	Node* fromNode;
	Node* toNode;

public:
	Connection(Node* _fromNode, Node* _toNode);
	Node* getFromNode() { return fromNode; }
	Node* getToNode() { return toNode; }
};

