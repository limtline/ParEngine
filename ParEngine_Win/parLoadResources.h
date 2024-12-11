#pragma once
#include "..\\ParEngine_Source\\parResources.h"
#include "..\\ParEngine_Source\\parTexture.h"

namespace par
{
	void LoadResources()
	{
		Resources::Load<graphics::Texture>(L"Cat", L"..\\Resources\\ChickenAlpha.bmp");
		Resources::Load<graphics::Texture>(L"Player", L"..\\Resources\\Player.bmp");




	}
}