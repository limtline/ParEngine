#pragma once
#include "CommonInclude.h"
#include "parGameObject.h"

namespace par
{
	class Application
	{
	public:
		Application();
		~Application();

		void Initialize(HWND hwnd, UINT width, UINT height);
		void Run();

		void Update();
		void LateUpdate();
		void Render();

	private:
		HWND mHwnd;
		HDC mHdc;

		HDC mBackHdc;
		HBITMAP mBackBitmap; // µµÈ­Áö
		 

		UINT mWidth;
		UINT mHeight;

		GameObject mPlayer;
	};
}
