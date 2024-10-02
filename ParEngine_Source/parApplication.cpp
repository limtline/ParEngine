#include "parApplication.h"
#include "parInput.h"
#include "parTime.h"
#include "parSceneManager.h"

namespace par
{
	Application::Application() : mHwnd(nullptr), mHdc(nullptr), mWidth(0), mHeight(0), mBackHdc(NULL), mBackBitmap(NULL)
	{
	}
	Application::~Application()
	{
	}
	void Application::Initialize(HWND hwnd,UINT width,UINT height)
	{
		adjustWindowRect(hwnd, width, height);	// DC생성
		createBuffer(width, height);	// 백버퍼 생성
		initializeEtc();
		
		SceneManager::Initialize();
	}

	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
	}

	void Application::Update()
	{
		Input::Update();
		Time::Update();
		SceneManager::Update();
	}

	void Application::LateUpdate()
	{
		SceneManager::LateUpdate();
	}

	void Application::Render()
	{
		clearRenderTarget();

		Time::Render(mBackHdc);
		SceneManager::Render(mBackHdc);

		copyRenderTarget(mBackHdc, mHdc);
	}

	void Application::clearRenderTarget()
	{
		// 화면 clear
		Rectangle(mBackHdc, -1, -1, 1601, 901);
	}

	void Application::copyRenderTarget(HDC source, HDC dest)
	{
		// 백버퍼에 그린 것들을 우리가 보는 버퍼에 복사해서 보여준다.
		BitBlt(dest, 0, 0, mWidth, mHeight,
			source, 0, 0, SRCCOPY);
	}

	void Application::adjustWindowRect(HWND hwnd, UINT width, UINT height)
	{
		mHwnd = hwnd;
		mHdc = GetDC(hwnd); // DC를 가져오는 함수 GetDC

		RECT rect = { 0, 0, width, height };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		mWidth = rect.right - rect.left;
		mHeight = rect.bottom - rect.top;

		mWidth = rect.right - rect.left;
		mHeight = rect.bottom - rect.top;

		SetWindowPos(mHwnd, nullptr, 0, 0, mWidth, mHeight, 0);
		ShowWindow(mHwnd, true);
	}

	void Application::createBuffer(UINT width, UINT height)
	{
		// back buffer
		// 윈도우 해상도에 맞는 백버퍼(도화지) 생성
		mBackBitmap = CreateCompatibleBitmap(mHdc, width, height);

		// 백버퍼를 가르킬 DC생성
		mBackHdc = CreateCompatibleDC(mHdc);

		HBITMAP oldBitmap = (HBITMAP)SelectObject(mBackHdc, mBackBitmap);
		DeleteObject(oldBitmap);
		// back buffer
	}

	void Application::initializeEtc()
	{
		Input::Initailize();
		Time::Initailize();
	}
}
