#pragma once
#include "parEntity.h"
#include "parGameObject.h"

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
		void AddGameObject(GameObject* gameObject);

	private:
		std::vector<GameObject*> mGameObjects;
	};
}

