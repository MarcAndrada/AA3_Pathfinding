#pragma once
#include "Vector2D.h"
class Node
{
private:
	Vector2D position;
	int type;

public:
	Node(Vector2D _position, int _type);
	Vector2D getPosition() { return position; }
	float getWeight() { return type; }
};

