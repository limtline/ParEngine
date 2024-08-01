#include "parInput.h"

namespace par
{
	std::vector<parInput::Key> parInput::mKeys = {};

	int ASCII[(UINT)eKeyCode::End] =
	{
		'Q','W','E','R','T','Y','U','I','O','P',
		'A','S','D','F','G','H','J','K','L',
		'Z','X','C','V','B','N','M',
		VK_LEFT, VK_RIGHT, VK_DOWN, VK_UP,
	};
	void par::parInput::Initailize()
	{
		createKeys();
	}

	void parInput::createKeys()
	{
		mKeys.resize((UINT)eKeyCode::End);

		for (size_t i = 0; i < (UINT)eKeyCode::End; i++)
		{
			Key key = {};
			key.bPressed = false;
			key.state = eKeyState::None;
			key.keyCode = (eKeyCode)i;

			mKeys.push_back(key);
		}
	}

	void par::parInput::Update()
	{
		updateKeys();
	}

	void parInput::updateKeys()
	{
		std::for_each(mKeys.begin(), mKeys.end(), [](Key& key)->void
			{
				updateKey(key);
			});
	}
	void parInput::updateKey(parInput::Key& key)
	{
		if (isKeyDown(key.keyCode))
		{
			updateKeyDown(key);
		}
		else
		{
			updateKeyUp(key);
		}
	}
	bool parInput::isKeyDown(eKeyCode code)
	{
		return GetAsyncKeyState(ASCII[(UINT)code]) & 0x8000;
	}

	// 키를 눌렀을 때
	void parInput::updateKeyDown(parInput::Key& key)
	{
		if (key.bPressed == true)
			key.state = eKeyState::Pressed;	// 이전에도 키를 눌렸을 때
		else
			key.state = eKeyState::Down;	// 지금 키를 눌렀을 때

		key.bPressed = true;
	}

	// 키를 안눌렸을 때
	void parInput::updateKeyUp(parInput::Key& key)
	{
		if (key.bPressed == true)
			key.state = eKeyState::Up;	// 눌렀다 뗐을 때
		else
			key.state = eKeyState::None;	// 애초에 안눌렀을 때

		key.bPressed = false;
	}
}
