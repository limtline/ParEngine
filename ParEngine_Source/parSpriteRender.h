#pragma once
#include "parEntity.h"
#include "parComponent.h"

namespace par
{
	class SpriteRender : public Component
	{
	public:
		SpriteRender();
		~SpriteRender();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:
		
	};
}