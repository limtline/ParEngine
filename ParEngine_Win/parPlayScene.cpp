#include "parPlayScene.h"
#include "parGameObject.h"
#include "parPlayer.h"
#include "parTransform.h"
#include "parSpriteRender.h"

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
			Player* pl = new Player();
			Transform* tr = pl->AddComponent<Transform>();
			tr->SetPos(800, 450);
			tr->SetName(L"TR");
			SpriteRender* sr = pl->AddComponent<SpriteRender>();
			sr->SetName(L"SR");
			AddGameObject(pl);
		}

		{
			Player* pl = new Player();
			Transform* tr = pl->AddComponent<Transform>();
			tr->SetPos(300, 450);
			tr->SetName(L"TR");
			SpriteRender* sr = pl->AddComponent<SpriteRender>();
			sr->SetName(L"SR");
			AddGameObject(pl);
		}

		{
			Player* pl = new Player();
			Transform* tr = pl->AddComponent<Transform>();
			tr->SetPos(100, 650);
			tr->SetName(L"TR");
			SpriteRender* sr = pl->AddComponent<SpriteRender>();
			sr->SetName(L"SR");
			AddGameObject(pl);
		}
	}

	void PlayScene::Update()
	{
		Scene::Update();
	}

	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();
	}

	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
}