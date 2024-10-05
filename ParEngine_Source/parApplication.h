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

		HDC GetHdc() { return mHdc; }

	private:
		void clearRenderTarget();
		void copyRenderTarget(HDC source, HDC dest);
		void adjustWindowRect(HWND hwnd, UINT width, UINT height);
		void createBuffer(UINT width, UINT height);
		void initializeEtc();

	private:
		HWND mHwnd;
		HDC mHdc;

		HDC mBackHdc;
		HBITMAP mBackBitmap; // ��ȭ��
		 

		UINT mWidth;
		UINT mHeight;

		//std::vector<Scene*> mScenes;
	};
}
