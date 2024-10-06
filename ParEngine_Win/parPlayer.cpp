#include "parPlayer.h"
#include "parInput.h"
#include "parTransform.h"
#include "parTime.h"

namespace par
{
	void Player::Initialize()
	{
		GameObject::Initialize();
	}

	void Player::Update()
	{
		GameObject::Update();
	}

	void Player::LateUpdate()
	{
		GameObject::LateUpdate(); 


	}

	void Player::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
}