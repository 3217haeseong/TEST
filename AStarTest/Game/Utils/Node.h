#pragma once
#include "Actor/Actor.h"

//struct Position
//{
//	Position(int x = 0, int y = 0)
//		: x(x), y(y)
//	{
//	}
//
//	// 비교 연산자 오버로딩.
//	bool operator==(const Position& other)
//	{
//		return x == other.x && y == other.y;
//	}
//
//	int x = 0;
//	int y = 0;
//};

class Node : public Actor
{
	RTTI_DECLARATIONS(Node, Actor)

public:
	Node(Vector2 Position, Node* parentNode = nullptr);

	bool operator==(const Node& other) const;

	Vector2 operator-(const Node& other);

	virtual void Tick(float deltaTime) override;
	virtual void Render() override;

public:
	float gCost = 0.0f;
	float hCost = 0.0f;
	float fCost = 0.0f;
	Node* parent = nullptr;
};