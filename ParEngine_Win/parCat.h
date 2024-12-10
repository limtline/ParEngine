#pragma once

#pragma once
#include "..\\ParEngine_Source\\parGameObject.h"

namespace par
{
	class Cat : public GameObject
	{
	public:
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:

	};
}
