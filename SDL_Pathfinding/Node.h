#pragma once
#include "Vector2D.h"
#include "utils.h"

class Node
{
private:
	Vector2D position;
	int type;

public:
	Node(Vector2D _position, int _type);
	Vector2D getPosition() { return position; }
	int getType() { return type; }

	void draw(Vector2D pos);
};

