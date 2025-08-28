#pragma once
#include "Actor/Actor.h"
#include "Utils/Node.h"

class Goal : public Actor
{
public:
	Goal(int x, int y);
	~Goal();

	inline Node*& GetNode() { return goalNode; }
	inline bool GetExist() { return goalExist; }
	inline void SetExist(bool change) { goalExist = change; }

private:
	Node* goalNode;
	bool goalExist = false;
};