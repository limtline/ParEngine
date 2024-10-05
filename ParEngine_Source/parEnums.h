#pragma once

namespace par::enums
{
	enum class eLayerType
	{
		None,
		BackGround,
		// Tree
		// character
		Player,
		Max = 16,
	};

	enum class eResourceType
	{
		Texture,	// 이미지
		AudioClip,	// 사운드
		Prefab,		// 데이터 저장
		End,
	};
}