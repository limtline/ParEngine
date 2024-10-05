#pragma once
#include "..\\ParEngine_Source\\parResources.h"
#include "..\\ParEngine_Source\\parTexture.h"

namespace par
{
	void LoadResources()
	{
		Resources::Load<graphics::Texture>(L"BG", L"C:\\Users\\oww90\\source\\repos\\ParEngine\\Resources\\CloudOcean.png");
	}
}