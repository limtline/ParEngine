#include "parPlayScene.h"
#include "parGameObject.h"
#include "parPlayer.h"
#include "parTransform.h"
#include "parSpriteRender.h"
#include "parInput.h"
#include "parTitleScene.h"
#include "parSceneManager.h"
#include "parObject.h"
#include "parTexture.h"
#include "parResources.h"
#include "parPlayerScript.h"
#include "parCamera.h"
#include "parRenderer.h"
#include "parAnimator.h"

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
		// main camera
		GameObject* camera = object::Instantiate<GameObject>(enums::eLayerType::None, Vector2(344.0f, 442.0f));
		Camera* cameraComp = camera->AddComponent<Camera>();
		renderer::mainCamera = cameraComp;
		//camera->AddComponent<PlayerScript>(); // ī�޶� �̵�

		// ���� ������Ʈ ����� ���� ���ҽ��� ���� Load�صθ� ����.
		// player
		mPlayer = object::Instantiate<Player>(enums::eLayerType::Player);
		//SpriteRender* sr = mPlayer->AddComponent<SpriteRender>();
		//sr->SetSize(Vector2(3.0f, 3.0f));
		mPlayer->AddComponent<PlayerScript>();

		graphics::Texture* pacmanTexture = Resources::Find<graphics::Texture>(L"Cat");
		Animator* animator = mPlayer->AddComponent<Animator>();
		animator->CreateAnimation(L"CatFrontMove", pacmanTexture,
									Vector2(0.0f, 0.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.5f);
		animator->PlayAnimation(L"CatFrontMove", true);
		//sr->SetTexture(pacmanTexture);

		// map, background
		GameObject* bg = object::Instantiate<GameObject>(enums::eLayerType::BackGround);
		SpriteRender* bgsr = bg->AddComponent<SpriteRender>();
		bgsr->SetSize(Vector2(3.0f, 3.0f));

		graphics::Texture* bgTexture = Resources::Find<graphics::Texture>(L"Map");
		bgsr->SetTexture(bgTexture);
		
		// ���� ������Ʈ �����Ŀ� ���̾�� ���ӿ�����Ʈ���� init�Լ��� ȣ��
		Scene::Initialize();
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
		//wchar_t str[50] = L"Play Scene";
		//TextOut(hdc, 0, 0, str, 10);
	}

	void PlayScene::OnEnter()
	{
	}

	void PlayScene::OnExit()
	{
		//Transform* tr = mPlayer->GetComponent<Transform>();
		//tr->SetPosition(Vector2(0, 0));
	}
}