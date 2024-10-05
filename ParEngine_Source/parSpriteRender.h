#pragma once
#include "parEntity.h"
#include "parComponent.h"
#include "parTexture.h"

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

		void SetTexture(graphics::Texture* texture) { mTexture = texture; }
		void SetSize(math::Vector2 size) { mSize = size; }

	private:
		graphics::Texture* mTexture;
		math::Vector2 mSize;
	};
}
