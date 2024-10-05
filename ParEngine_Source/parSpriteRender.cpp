#include "parSpriteRender.h"
#include "parGameObject.h"
#include "parTransform.h"
#include "parTexture.h"

namespace par
{
	SpriteRender::SpriteRender()
		: Component(),
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
		
		// 이미지 그려주는 부분
		if (mTexture->GetTextureType() == graphics::Texture::eTextureType::Bmp)
		{
			TransparentBlt(hdc, pos.x, pos.y,
							mTexture->GetWidth(), mTexture->GetHeight(),
							mTexture->GetHdc(), 0, 0, mTexture->GetWidth() * mSize.x, mTexture->GetHeight() * mSize.y,
							RGB(255, 0, 255));
		}
		else if (mTexture->GetTextureType() == graphics::Texture::eTextureType::Png)
		{
			Gdiplus::Graphics graphics(hdc);
			graphics.DrawImage(mTexture->GetImage(),
								Gdiplus::Rect(pos.x, pos.y, mTexture->GetWidth() * mSize.x, mTexture->GetHeight() * mSize.y));
		}
	}


}