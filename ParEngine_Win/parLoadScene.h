#pragma once
#include "..\\ParEngine_Source\\parSceneManager.h"

#include "parPlayScene.h"
#include "parTitleScene.h"

//#ifdef _DEBUG
//#pragma comment(lib,"..\\x64\\Debug\\parEngine_win.lib")
//#else
//#pragme comment(lib,"..\\x64\\Release\\parEngine_win.lib")
//#endif

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