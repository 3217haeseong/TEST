#include "Input.h"
#include "Engine.h"
#include "Windows.h"

Input* Input::instance = nullptr;

Input::Input()
{
	// �̱��� ������ ���� instance ���� ����.
	instance = this;
}

void Input::ProcessInput()
{
	// �Է� �ڵ� ������ & ���콺 �Է� Ȱ��ȭ ����.
	static HANDLE inputHandle = GetStdHandle(STD_INPUT_HANDLE);
	static bool initialized = false;
	if (!initialized)
	{
		// ���콺 �̺�Ʈ Ȱ��ȭ.
		DWORD mode = ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS;
		mode &= ~ENABLE_QUICK_EDIT_MODE;
		BOOL result = SetConsoleMode(inputHandle, mode);

		if (result == FALSE)
		{
			int errorCode = GetLastError();
			OutputDebugStringA("���콺 �Է� ���� ����\n");
			__debugbreak();
		}

		initialized = true;
	}

	const int recordCount = 256;
	INPUT_RECORD records[recordCount] = {};
	DWORD eventReadCount = 0;

	if (PeekConsoleInput(inputHandle, records, recordCount, &eventReadCount) && eventReadCount > 0)
	{
		if (ReadConsoleInput(inputHandle, records, recordCount, &eventReadCount))
		{
			// @Test: �о�� �̺�Ʈ �� Ȯ��.
			//char eventCountAndTypeString[50] = {};
			//sprintf_s(eventCountAndTypeString, 50, "EventCount: %d \n", eventReadCount);
			//OutputDebugStringA(eventCountAndTypeString);

			for (int ix = 0; ix < (int)eventReadCount; ++ix)
			{
				INPUT_RECORD& record = records[ix];

				// @Test: �о�� �̺�Ʈ ���� Ÿ�� Ȯ��.
				//char eventCountAndTypeString[50] = {};
				//sprintf_s(eventCountAndTypeString, 50, "EventCount: %d | EventType: %s \n",
				//	eventReadCount, 
				//	record.EventType == WINDOW_BUFFER_SIZE_EVENT ? "BufferSizeEvent" : 
				//	record.EventType == KEY_EVENT ? "KeyEvent" : 
				//	record.EventType == MOUSE_EVENT ? "MouseEvent" : 
				//	record.EventType == FOCUS_EVENT ? "FocusEvent" : 
				//	"MenuEvent" 
				//);
				//OutputDebugStringA(eventCountAndTypeString);

				switch (record.EventType)
				{
				case KEY_EVENT:
				{
					if (record.Event.KeyEvent.bKeyDown)
					{
						keyStates[record.Event.KeyEvent.wVirtualKeyCode].isKeyDown = true;
					}
					else
					{
						keyStates[record.Event.KeyEvent.wVirtualKeyCode].isKeyDown = false;
					}
				}
				break;

				case MOUSE_EVENT:
				{
					mousePosition.x = record.Event.MouseEvent.dwMousePosition.X;
					mousePosition.x = mousePosition.x < 0 ? 0
						: mousePosition.x >= Engine::Get().Width() - 1 ? Engine::Get().Width() - 1
						: mousePosition.x;
					mousePosition.y = record.Event.MouseEvent.dwMousePosition.Y;
					mousePosition.y = mousePosition.y < 0 ? 0
						: mousePosition.y >= Engine::Get().Height() - 1 ? Engine::Get().Height() - 1
						: mousePosition.y;

					keyStates[VK_LBUTTON].isKeyDown
						= (record.Event.MouseEvent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED) != 0;

					keyStates[VK_RBUTTON].isKeyDown
						= (record.Event.MouseEvent.dwButtonState & RIGHTMOST_BUTTON_PRESSED) != 0;
				}
				break;
				}
			}
		}
	}
}

void Input::SavePreviousKeyStates()
{
	// ���� �������� �Է��� ���.
	for (int ix = 0; ix < 255; ++ix)
	{
		keyStates[ix].previousKeyDown = keyStates[ix].isKeyDown;
	}
}

bool Input::GetKey(int keyCode)
{

	return keyStates[keyCode].isKeyDown;
}

bool Input::GetKeyDown(int keyCode)
{
	return !keyStates[keyCode].previousKeyDown
		&& keyStates[keyCode].isKeyDown;
}

bool Input::GetKeyUp(int keyCode)
{
	return keyStates[keyCode].previousKeyDown
		&& !keyStates[keyCode].isKeyDown;
}

Vector2 Input::MousePosition() const
{
	return mousePosition;
}

Input& Input::Get()
{
	return *instance;
}