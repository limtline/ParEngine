#include "parPlayScene.h"
#include "parGameObject.h"
#include "parPlayer.h"
#include "parTransform.h"
#include "parSpriteRender.h"
#include "parInput.h"
#include "parTitleScene.h"
#include "parSceneManager.h"

namespace par
{
	PlayScene::PlayScene()
	{
	}

	PlayScene::~PlayScene()
	{
	}

	void PlayScene::Initialize()
	{
		{
			bg = new Player();
			Transform* tr = bg->AddComponent<Transform>();
			tr->SetPos(Vector2(0, 0));
			tr->SetName(L"TR");

			SpriteRender* sr = bg->AddComponent<SpriteRender>();
			sr->SetName(L"SR");
			sr->ImageLoad(L"C:\\Users\\oww90\\source\\repos\\ParEngine\\Resources\\CloudOcean.png");
			AddGameObject(bg, eLayerType::BackGround);
		}
	}

	void PlayScene::Update()
	{
		Scene::Update();
	}

	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();

 		if (Input::GetKeyDown(eKeyCode::N))
		{
			SceneManager::LoadScene(L"TitleScene");
		}
	}

	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
		wchar_t str[50] = L"Play Scene";
		TextOut(hdc, 0, 0, str, 10);
	}

	void PlayScene::OnEnter()
	{
	}

	void PlayScene::OnExit()
	{
		Transform* tr = bg->GetComponent<Transform>();
		tr->SetPos(Vector2(0, 0));
	}
}