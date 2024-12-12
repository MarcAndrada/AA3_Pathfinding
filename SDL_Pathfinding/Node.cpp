#include "Node.h"
#include "SDL_SimpleApp.h"

Node::Node(Vector2D _position, int _type)
{
	position = _position;
	type = _type;
}

void Node::draw(Vector2D pos)
{
	draw_circle(TheApp::Instance()->getRenderer(), (int)pos.x, (int)pos.y, 15, 0, 255, 0, 255);
}
