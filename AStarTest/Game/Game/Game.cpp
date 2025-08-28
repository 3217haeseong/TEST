#include "Game.h"
#include "Level/AStarLevel.h"

Game::Game()
{
	AddLevel(new AStarLevel());
}
