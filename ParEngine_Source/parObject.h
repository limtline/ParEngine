#pragma once
#include "parComponent.h"
#include "parGameObject.h"
#include "parLayer.h"
#include "parScene.h"
#include "parSceneManager.h"
#include "parTransform.h"

// ����Ƽ�� Instantiate ���
namespace par::object
{
	// ��ü ���� �� ��ġ �ʱ�ȭ 0,0
	template <typename T>
	static T* Instantiate(par::enums::eLayerType type)
	{
		T* gameObject = new T();
		Scene* activeScene = SceneManager::GetActiveScene();
		Layer* layer = activeScene->GetLayer(type);
		layer->AddGameObject(gameObject);
		
		return gameObject;
	}

	// ��ü ���� �� ���ϴ� �� ��ġ ���ϴ� ��
	template <typename T>
	static T* Instantiate(par::enums::eLayerType type, math::Vector2 position)
	{
		T* gameObject = new T();
		Scene* activeScene = SceneManager::GetActiveScene();
		Layer* layer = activeScene->GetLayer(type);
		layer->AddGameObject(gameObject);

		Transform* tr = gameObject->GetComponent<Transform>();
		tr->SetPosition(position);

		return gameObject;
	}
}