#include "parTime.h"


namespace par
{
	LARGE_INTEGER Time::CpuFrequency = {};
	LARGE_INTEGER Time::PreFrequency = {};
	LARGE_INTEGER Time::CurFrequency = {};
	float Time::mDeltaTime = 0.0f;

	void par::Time::Initailize()
	{
		// Cpu 고유 진동수
		QueryPerformanceFrequency(&CpuFrequency);

		// 프로그램이 시작 했을 때 현재 진동 수
		QueryPerformanceCounter(&PreFrequency);
	}

	void par::Time::Update()
	{
		QueryPerformanceCounter(&CurFrequency);

		float differenceFrequency = static_cast<float>(CurFrequency.QuadPart - PreFrequency.QuadPart); // 현재 진동 수 - 이전 진동 수

		mDeltaTime = differenceFrequency / static_cast<float>(CpuFrequency.QuadPart); // 게임 실행 후 경과 시간 (현재 진동 수와 이전 진동 수의 차이를 cpu고유 진동수로 나눈다)
		PreFrequency.QuadPart = CurFrequency.QuadPart;
	}
	void Time::Render(HDC hdc)
	{
		static float time = 0.0f;

		time += mDeltaTime; // 게임 실행 후 경과 시간
		float fps = 1.0f / mDeltaTime; // 프레임

		wchar_t str[50] = L"";
		swprintf_s(str, 50, L"Time : %d", (int)fps); 
		int len = wcsnlen_s(str,50);


		TextOut(hdc, 0, 0, str, len); 
	}
}
