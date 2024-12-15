#pragma once
#include "Vector2D.h"
#include "utils.h"

class Node
{
private:
	Vector2D position;
	int type;
	int weight;
public:
	Node(Vector2D _position, int _type);
	Vector2D getPosition() { return position; }
	void setWeight(int _weight) { weight = _weight; }
	int getType() { return type + weight; }

	void draw(Vector2D pos);
};

