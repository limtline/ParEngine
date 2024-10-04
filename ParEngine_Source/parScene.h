#pragma once
#include "parEntity.h"
#include "parGameObject.h"
#include "parLayer.h"

namespace par
{
	class Scene : public Entity
	{
	public:
		Scene();
		~Scene();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);
		
		virtual void OnEnter();
		virtual void OnExit();

		void AddGameObject(GameObject* gameObj, const enums::eLayerType type);
		Layer* GetLayer(const enums::eLayerType type) { return mLayers[(UINT)type]; }

	private:
		void createLayers();
		
	private:
		std::vector<Layer*> mLayers;
	};
}

