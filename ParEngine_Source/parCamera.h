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
		class GameObject* mTarget;	// ī�޶��� �߽� (������ ó�� ĳ���Ͱ� �߽��� �Ǽ� ī�޶� �����϶�)
		Vector2 mDistance;		// ī�޶��� ���� ��ġ
		Vector2 mResolution;	// ȭ�� �ػ�
		Vector2 mLookPosition;	// ī�޶� �ٶ󺸴� ��ġ
	};
}
