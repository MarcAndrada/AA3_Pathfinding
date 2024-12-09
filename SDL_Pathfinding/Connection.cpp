#include "Connection.h"

Connection::Connection(Node* _fromNode, Node* _toNode, float _cost)
{
	fromNode = _fromNode;
	toNode = _toNode;
	cost = _cost;
}
