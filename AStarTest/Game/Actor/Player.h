#pragma once
#pragma once
#include "Actor/Actor.h"
#include "Utils/Node.h"


class Player :public Actor
{
	RTTI_DECLARATIONS(Player, Actor)

public:
	Player(int x, int y);
	~Player();

	virtual void Tick(float deltaTime) override;

	inline Node*& GetNode() { return playerNode; }
	inline bool GetExist() { return playerExist; }
	inline void SetExist(bool change) { playerExist = change; }

private:
	Node* playerNode=nullptr;
	bool playerExist = false;
};