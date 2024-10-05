#pragma once
#include "parResource.h"

namespace par::graphics
{
	class Texture : public Resource
	{
	public:
		enum class eTextureType
		{
			Bmp,
			Png,
			none,
		};

		Texture();
		~Texture();

		virtual HRESULT Load(const std::wstring& path) override;
		
		UINT GetWidth() { return mWidth; }
		UINT GetHeight() { return mHeight; }
		HDC GetHdc() { return mHdc; }
		eTextureType GetTextureType() { return mType; }
		Gdiplus::Image* GetImage() { return mImage; }

	private:
		eTextureType mType;

		Gdiplus::Image* mImage;	// png ���� �̿��Ҷ� ���
		HBITMAP mBitmap;	// bmp ���� �̿��Ҷ� ��� (gdi ��� �θ�)
		HDC mHdc;			// bmp ���� �̿��Ҷ� ��� (gdi ��� �θ�)

		UINT mWidth;
		UINT mHeight;
	};
}
