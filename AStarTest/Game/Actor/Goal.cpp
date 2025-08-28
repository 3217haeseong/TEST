#include "Goal.h"

Goal::Goal(int x, int y)
	:Actor("<G>",Color::Red)
{
	SetPosition(Vector2(x, y));
	goalNode = new Node(Vector2(x, y));
}

Goal::~Goal()
{
	SafeDelete(goalNode);
}
