#pragma once
#include "CommonInclude.h"


namespace par
{
	class Time
	{
	public:
		static void Initailize();
		static void Update();
		static void Render(HDC hdc);

		static float DeltaTime() { return mDeltaTime; }

	private:
		static LARGE_INTEGER CpuFrequency;
		static LARGE_INTEGER PreFrequency;
		static LARGE_INTEGER CurFrequency;
		static float mDeltaTime;
	};
}

