#pragma once
#include "..\\ParEngine_Source\\parScript.h"
#include "..\\ParEngine_Source\\parTransform.h"

namespace par
{
	class CatScript : public Script
	{
	public:
		enum class eState
		{
			SitDown,
			Walk,
			Sleep,
			LayDown,
			Attack
		};

		enum class eDirection
		{
			Left,
			Right,
			Down,
			Up,
			End,
		};

		CatScript();
		~CatScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:
		void sitDown();
		void move();
		void layDown();
		void PlayWalkAnimationByDriection(eDirection dir);
		void translate(Transform* tr);

	private:
		eState mState;
		class Animator* mAnimator;
		eDirection mDirection;
		float mTime;
	};
}