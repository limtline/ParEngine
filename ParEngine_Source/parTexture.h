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

		Gdiplus::Image* mImage;	// png 파일 이용할때 사용
		HBITMAP mBitmap;	// bmp 파일 이용할때 사용 (gdi 라고 부름)
		HDC mHdc;			// bmp 파일 이용할때 사용 (gdi 라고 부름)

		UINT mWidth;
		UINT mHeight;
	};
}
