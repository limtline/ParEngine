#pragma once
#include "..\\ParEngine_Source\\parSceneManager.h"

#include "parPlayScene.h"
#include "parTitleScene.h"

namespace par
{
	void LoadScenes()
	{
		SceneManager::CreateScene<TitleScene>(L"TitleScene");
		SceneManager::CreateScene<PlayScene>(L"PlayScene");
		//SceneManager::CreateScene<EndScene>(L"EndScene");

		SceneManager::LoadScene(L"PlayScene");
	}
}