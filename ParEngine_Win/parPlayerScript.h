#pragma once
#include "..\\ParEngine_Source\\parScript.h"

namespace par
{
	class PlayerScript : public Script
	{
	public:
		enum class eState
		{
			Idle,
			Walk,
			Sleep,
			GiveWater,
			Attack
		};

		PlayerScript();
		~PlayerScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:
		void idle();
		void move();
		void giveWater();

	private:
		eState mState;
		class Animator* mAnimator;
		

	};
}
