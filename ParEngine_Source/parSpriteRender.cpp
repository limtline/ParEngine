#include "parSpriteRender.h"
#include "parGameObject.h"
#include "parTransform.h"

namespace par
{
	SpriteRender::SpriteRender()
		: mImage(nullptr)
		, mWidth(0)
		, mHeight(0)
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
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		Gdiplus::Graphics graphcis(hdc);
		graphcis.DrawImage(mImage, Gdiplus::Rect(pos.x, pos.y, mWidth, mHeight));
	}

	void SpriteRender::ImageLoad(const std::wstring& path)
	{
		mImage = Gdiplus::Image::FromFile(path.c_str());
		mWidth = mImage->GetWidth();
		mHeight = mImage->GetHeight();
	}
}