#include "parInput.h"
#include "parApplication.h"

extern par::Application application;

namespace par
{
	std::vector<Input::Key> Input::Keys = {};
	math::Vector2 Input::mMousePosition = math::Vector2::One;

	int ASCII[(UINT)eKeyCode::End] =
	{
		'Q','W','E','R','T','Y','U','I','O','P',
		'A','S','D','F','G','H','J','K','L',
		'Z','X','C','V','B','N','M',
		VK_LEFT, VK_RIGHT, VK_DOWN, VK_UP,
		VK_LBUTTON, VK_MBUTTON, VK_RBUTTON,
	};
	void Input::Initailize()
	{
		CreateKeys();
	}

	void Input::CreateKeys()
	{
		for (size_t i = 0; i < (UINT)eKeyCode::End; i++)
		{
			Key key = {};
			key.bPressed = false;
			key.state = eKeyState::None;
			key.keyCode = (eKeyCode)i;

			Keys.push_back(key);
		}
	}

	void Input::Update()
	{
		UpdateKeys();
	}

	void Input::UpdateKeys()
	{
		std::for_each(Keys.begin(), Keys.end(), [](Key& key)->void
			{
				UpdateKey(key);
			});
	}
	void Input::UpdateKey(Input::Key& key)
	{
		if (GetFocus())	// ���� ������ ������ �Է�ó�� �ϰڴ�.
		{
			if (IsKeyDown(key.keyCode))
				UpdateKeyDown(key);
			else
				UpdateKeyUp(key);

			getMousePositionByWindow();
		}
		else
		{
			clearKeys();
		}
	}
	bool Input::IsKeyDown(eKeyCode code)
	{
		return GetAsyncKeyState(ASCII[(UINT)code]) & 0x8000;
	}

	// Ű�� ������ ��
	void Input::UpdateKeyDown(Input::Key& key)
	{
		if (key.bPressed == true)
			key.state = eKeyState::Pressed;	// �������� Ű�� ������ ��
		else
			key.state = eKeyState::Down;	// ���� Ű�� ������ ��

		key.bPressed = true;
	}

	// Ű�� �ȴ����� ��
	void Input::UpdateKeyUp(Input::Key& key)
	{
		if (key.bPressed == true)
			key.state = eKeyState::Up;	// ������ ���� ��
		else
			key.state = eKeyState::None;	// ���ʿ� �ȴ����� ��

		key.bPressed = false;
	}
	void Input::getMousePositionByWindow()
	{
		POINT mousePos = {};
		GetCursorPos(&mousePos);
		ScreenToClient(application.GetHwnd(), &mousePos);

		mMousePosition.x = mousePos.x;
		mMousePosition.y = mousePos.y;
	}
	void Input::clearKeys()
	{
		for (Key& key : Keys)
		{
			if (key.state == eKeyState::Down || key.state == eKeyState::Pressed)
				key.state = eKeyState::Up;
			else if (key.state == eKeyState::Up)
				key.state = eKeyState::None;

			key.bPressed = false;
		}
	}
}
