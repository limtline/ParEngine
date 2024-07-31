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
		for (size_t i = 0; i < mKeys.size(); i++)
		{
			// 키가 눌렸다
			if (GetAsyncKeyState(ASCII[i]) & 0x8000)
			{
				if (mKeys[i].bPressed == true) 
					mKeys[i].state = eKeyState::Pressed; // 이전부터 키가 눌려있을 때
				else
					mKeys[i].state = eKeyState::Down; // 지금 눌렸을 때

				mKeys[i].bPressed = true;
			}
			else  // 키가 안눌렸다
			{
				if (mKeys[i].bPressed == true)
					mKeys[i].state = eKeyState::Up; // 눌렀다 뗐을 때
				else
					mKeys[i].state = eKeyState::None; // 애초에 안눌렀을 때

				mKeys[i].bPressed = false;
			}
		}
	}
}
