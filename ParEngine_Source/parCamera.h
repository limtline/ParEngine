#pragma once
#include "parComponent.h"

namespace par
{
	using namespace par::math;
	class Camera : public Component
	{
	public:
		Vector2 CaluatePosition(Vector2 pos) { return pos - mDistance; }

		Camera();
		~Camera();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render(HDC hdc) override;

	private:
		//std::vector<GameObject*> mGameObjects;
		class GameObject* mTarget;	// 카메라의 중심 (메이플 처럼 캐릭터가 중심이 되서 카메라가 움직일때)
		Vector2 mDistance;		// 카메라의 실제 위치
		Vector2 mResolution;	// 화면 해상도
		Vector2 mLookPosition;	// 카메라가 바라보는 위치
	};
}
