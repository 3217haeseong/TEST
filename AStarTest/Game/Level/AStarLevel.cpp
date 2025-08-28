#include <vector>
#include <iostream>
#include <Windows.h>

#include "AStarLevel.h"
#include "Actor/Player.h"
#include "Engine.h"
#include "Actor/Goal.h"
#include "AStar/AStar.h"


AStarLevel::AStarLevel()
{
	InitailizeGrid();

}

AStarLevel::~AStarLevel()
{

}

void AStarLevel::BeginPlay()
{
	super::BeginPlay();
}

void AStarLevel::Tick(float deltaTime)
{
	super::Tick(deltaTime);

	if (Input::Get().GetKeyDown(VK_SPACE) && playerExist && goalExist && path.size() == 0)
	{
		AStar astar;

		path=astar.FindPath(player->GetNode(), goal->GetNode(), grid);

		for (Node* node : path)
		{
			if (!node->HasBeganPlay())
			{
				AddActor(node);
			}
		}
	}
	
	if (Input::Get().GetKeyDown(VK_LBUTTON) && !playerExist)
	{		
		player = new Player(Input::Get().MousePosition().x, Input::Get().MousePosition().y);
		AddActor(player);
		playerExist = true;
	}

	if (Input::Get().GetKeyDown(VK_RBUTTON) && !goalExist)
	{
		goal = new Goal(Input::Get().MousePosition().x, Input::Get().MousePosition().y);
		AddActor(goal);
		goalExist = true;
	}

	
	
}

void AStarLevel::Render()
{
	super::Render();
}

void AStarLevel::InitailizeGrid()
{
	int width = Engine::Get().Width();
	int height = Engine::Get().Height();
	grid.resize(width);

	for (int ix = 0; ix < height; ++ix)
	{
		grid[ix].resize(width);
		for (int jx = 0; jx < width; ++jx)
		{
			grid[ix][jx] = 0;
		}
	}
}
