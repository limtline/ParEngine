#include "parPlayScene.h"
#include "parGameObject.h"
#include "parPlayer.h"
#include "parTransform.h"
#include "parSpriteRender.h"
#include "parInput.h"
#include "parTitleScene.h"
#include "parSceneManager.h"
#include "parObject.h"

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
			//bg = new Player();
			//Transform* tr = bg->AddComponent<Transform>();
			//tr->SetPosition(Vector2(0, 0));
			//tr->SetName(L"TR");

			//SpriteRender* sr = bg->AddComponent<SpriteRender>();
			//sr->SetName(L"SR");
			//sr->ImageLoad(L"C:\\Users\\oww90\\source\\repos\\ParEngine\\Resources\\CloudOcean.png");
			//AddGameObject(bg, enums::eLayerType::BackGround);
			bg = object::Instantiate<Player>(enums::eLayerType::BackGround, Vector2(100.0f,100.0f));

			SpriteRender* sr = bg->AddComponent<SpriteRender>();
			sr->ImageLoad(L"C:\\Users\\oww90\\source\\repos\\ParEngine\\Resources\\CloudOcean.png");
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
		//Transform* tr = bg->GetComponent<Transform>();
		//tr->SetPosition(Vector2(0, 0));
	}
}