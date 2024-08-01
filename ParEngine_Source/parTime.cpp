#include "parTime.h"


namespace par
{
	LARGE_INTEGER Time::CpuFrequency = {};
	LARGE_INTEGER Time::PreFrequency = {};
	LARGE_INTEGER Time::CurFrequency = {};
	float Time::mDeltaTime = 0.0f;

	void par::Time::Initailize()
	{
		// Cpu ���� ������
		QueryPerformanceFrequency(&CpuFrequency);

		// ���α׷��� ���� ���� �� ���� ���� ��
		QueryPerformanceCounter(&PreFrequency);
	}

	void par::Time::Update()
	{
		QueryPerformanceCounter(&CurFrequency);

		float differenceFrequency = static_cast<float>(CurFrequency.QuadPart - PreFrequency.QuadPart); // ���� ���� �� - ���� ���� ��

		mDeltaTime = differenceFrequency / static_cast<float>(CpuFrequency.QuadPart); // ���� ���� �� ��� �ð� (���� ���� ���� ���� ���� ���� ���̸� cpu���� �������� ������)
		PreFrequency.QuadPart = CurFrequency.QuadPart;
	}
	void Time::Render(HDC hdc)
	{
		static float time = 0.0f;

		time += mDeltaTime; // ���� ���� �� ��� �ð�
		float fps = 1.0f / mDeltaTime; // ������

		wchar_t str[50] = L"";
		swprintf_s(str, 50, L"Time : %d", (int)fps); 
		int len = wcsnlen_s(str,50);


		TextOut(hdc, 0, 0, str, len); 
	}
}
