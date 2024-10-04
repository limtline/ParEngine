#pragma once
#include "parComponent.h"
#include "parGameObject.h"
#include "parLayer.h"
#include "parScene.h"
#include "parSceneManager.h"
#include "parTransform.h"

// 유니티에 Instantiate 기능
namespace par::object
{
	// 물체 생성 시 위치 초기화 0,0
	template <typename T>
	static T* Instantiate(par::enums::eLayerType type)
	{
		T* gameObject = new T();
		Scene* activeScene = SceneManager::GetActiveScene();
		Layer* layer = activeScene->GetLayer(type);
		layer->AddGameObject(gameObject);
		
		return gameObject;
	}

	// 물체 생성 시 원하는 곳 위치 정하는 곳
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