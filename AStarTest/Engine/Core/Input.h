#pragma once

#include "Core.h"
#include <Math/Vector2.h>

class Engine_API Input
{
	friend class Engine;

	struct KeyState
	{
		// ���� �����ӿ� Ű�� ���ȴ��� ����.
		bool isKeyDown = false;
		// ���� �����ӿ� Ű�� ���ȴ��� ����.
		bool previousKeyDown = false;
	};

public:
	Input();



	// Ű Ȯ�� �Լ�.
	bool GetKey(int keyCode);
	bool GetKeyDown(int keyCode);
	bool GetKeyUp(int keyCode);

	Vector2 MousePosition() const;

	static Input& Get();

private:
	void ProcessInput();
	void SavePreviousKeyStates();

private:

	// Ű �Է� ���� ���� ����.
	KeyState keyStates[255] = {};

	static Input* instance;

	Vector2 mousePosition;
};