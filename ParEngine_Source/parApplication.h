#pragma once
#include "CommonInclude.h"
#include "parGameObject.h"

namespace par
{
	class parApplication
	{
	public:
		parApplication();
		~parApplication();

		void Initialize(HWND hwnd );
		void Run();

		void Update();
		void LateUpdate();
		void Render();

	private:
		HWND mHwnd;
		HDC mHdc;
		parGameObject mPlayer;
	};
}
