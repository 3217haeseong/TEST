#include "Node.h"

Node::Node(Vector2 Position, Node* parentNode)
	: Actor("*", Color::Red)
{
	SetPosition(Position);
	parent = parentNode;
	SetSortingOrder(1);
}


bool Node::operator==(const Node& other) const
{
	return position.x == other.position.x
		&& position.y == other.position.y;
}

Vector2 Node::operator-(const Node& other)
{
	return Vector2(
		position.x - other.position.x,
		position.y - other.position.y
	);
}

void Node::Tick(float deltaTime)
{
	super::Tick(deltaTime);


}

void Node::Render()
{
	super::Render();

	//Sleep(500);
}
