#pragma once
#include "..\\ParEngine_Source\\parResources.h"
#include "..\\ParEngine_Source\\parTexture.h"

namespace par
{
	void LoadResources()
	{
		Resources::Load<graphics::Texture>(L"Map", L"..\\Resources\\img\\map\\map_pure.png");
		Resources::Load<graphics::Texture>(L"PackMan", L"..\\Resources\\img\\pacman\\0.png");

	}
}