#include "Player.h"
#include "Engine.h"

Player::Player(int x, int y)
	:Actor("<A>", Color::Blue)
{
	int xPosition = x;
	int yPosition = y;
	SetPosition(Vector2(xPosition, yPosition));
	playerNode = new Node(Vector2(xPosition,yPosition));
	playerExist = false;
}

Player::~Player()
{
	SafeDelete(playerNode);
}

void Player::Tick(float deltaTime)
{
	super::Tick(deltaTime);

	// 입력 처리.
	if (Input::Get().GetKeyDown(VK_ESCAPE))
	{
		// 게임 종료.
		QuitGame();
		return;
	}

	if (Input::Get().GetKey(VK_LEFT))
	{
		Vector2 position = Position();
		position.x -= 1;
		if (position.x >= 0)
		{
			SetPosition(position);
		}
	}

	if (Input::Get().GetKey(VK_RIGHT))
	{
		Vector2 position = Position();
		position.x += 1;
		if (position.x + width < Engine::Get().Width())
		{
			SetPosition(position);
		}
	}

	if (Input::Get().GetKey(VK_UP))
	{
		Vector2 position = Position();
		position.y -= 1;
		if (position.y >= 0)
		{
			SetPosition(position);
		}
	}

	if (Input::Get().GetKey(VK_DOWN))
	{
		Vector2 position = Position();
		position.y += 1;
		if (position.y < Engine::Get().Height())
		{
			SetPosition(position);
		}

	}
}

