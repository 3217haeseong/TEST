#pragma once
#include "Level/Level.h"
#include "Actor/Player.h"
#include "Actor/Goal.h"
#include <Windows.h>

class AStarLevel : public Level
{
	RTTI_DECLARATIONS(AStarLevel, Level)

public:
	AStarLevel();
	~AStarLevel();

	virtual void BeginPlay() override;
	virtual void Tick(float deltaTime) override;
	virtual void Render() override;

	void InitailizeGrid();

private:
	std::vector<std::vector<int>> grid;
	bool playerExist = false;
	bool goalExist = false;
	
	Player* player;
	Goal* goal;
	std::vector<Node*> path;

	
};