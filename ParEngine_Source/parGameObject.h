#pragma once
#include "CommonInclude.h"
#include "parComponent.h"

namespace par
{
	// Actor
	class GameObject
	{
	public:
		GameObject();
		~GameObject();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		template <typename T>
		T* AddComponent()
		{
			T* comp = new T();
			comp->Initialize();
			comp->SetOwner(this);
			mComponents.push_back(comp);
			
			return comp;
		}

		template <typename T>
		T* GetComponent()
		{
			T* component = nullptr;
			for (Component* comp : mComponents)
			{
				component = dynamic_cast<T*>(comp);
				if (component)
					break;
			}

			return component;
		}
	private:
		// GameObject 생성시 위치 초기화
		void initializeTransform();

	private:
		std::vector<Component*> mComponents;
	};
}
