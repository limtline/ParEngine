#include "parSpriteRender.h"
#include "parGameObject.h"
#include "parTransform.h"
#include "parTexture.h"
#include "parRenderer.h"

namespace par
{
	SpriteRender::SpriteRender()
		: Component(enums::eComponentType::SpriteRenderer),
		mTexture(nullptr),
		mSize(Vector2::One)
	{
	}

	SpriteRender::~SpriteRender()
	{
	}

	void SpriteRender::Initialize()
	{
	}

	void SpriteRender::Update()
	{
	}

	void SpriteRender::LateUpdate()
	{
	}

	void SpriteRender::Render(HDC hdc)
	{
		if (mTexture == nullptr)	// 텍스처 없을시 정지, 세팅 해줘야 오류 해결
			assert(false);

		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		float rot = tr->GetRotation();
		Vector2 scale = tr->GetScale();

		pos = renderer::mainCamera->CaluatePosition(pos);

		// 이미지 그려주는 부분
		if (mTexture->GetTextureType() == graphics::Texture::eTextureType::Bmp)
		{

			TransparentBlt(hdc, pos.x, pos.y,
						mTexture->GetWidth() * mSize.x * scale.x, mTexture->GetHeight() * mSize.y * scale.y,
						mTexture->GetHdc(), 0, 0, mTexture->GetWidth() * mSize.x, mTexture->GetHeight() * mSize.y,
						RGB(255, 0, 255));
		}
		else if (mTexture->GetTextureType() == graphics::Texture::eTextureType::Png)
		{
			// 원하는 필셀을 투명화 시킬 때
			Gdiplus::ImageAttributes imgAtt = {};

			// 투명화 시킬 픽셀의 색 범위
			imgAtt.SetColorKey(Gdiplus::Color(200, 200, 200), Gdiplus::Color(255, 255, 255));

			Gdiplus::Graphics graphics(hdc);

			graphics.TranslateTransform(pos.x, pos.y);
			graphics.RotateTransform(rot);
			graphics.TranslateTransform(-pos.x, -pos.y);

			graphics.DrawImage(mTexture->GetImage(),
			Gdiplus::Rect(pos.x, pos.y,
						mTexture->GetWidth() * mSize.x * scale.x, mTexture->GetHeight() * mSize.y * scale.y),
						0,0,
						mTexture->GetWidth(), mTexture->GetHeight(),
						Gdiplus::UnitPixel, nullptr /*&imgAtt*/);
}
	}


}