#include "parApplication.h"
#include "parInput.h"

namespace par
{
	parApplication::parApplication(): mHwnd(nullptr),mHdc(nullptr)
	{
	}
	parApplication::~parApplication()
	{
	}
	void parApplication::Initialize(HWND hwnd)
	{
		mHwnd = hwnd;
		mHdc = GetDC(hwnd); // DC를 가져오는 함수 GetDC

		mPlayer.SetPosition(0.0f, 0.0f);

		parInput::Initailize();
	}

	void parApplication::Run()
	{
		Update();
		LateUpdate();
		Render();
	}

	void parApplication::Update()
	{
		parInput::Update();

		mPlayer.Update();
	}

	void parApplication::LateUpdate()
	{
	}

	void parApplication::Render()
	{
		
	}
}
