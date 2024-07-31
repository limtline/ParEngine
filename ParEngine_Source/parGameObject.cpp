#include "parGameObject.h"
#include "parInput.h"

namespace par
{
	par::parGameObject::parGameObject()
	{
	}

	par::parGameObject::~parGameObject()
	{
	}

	void par::parGameObject::Update()
	{
		if (parInput::GetKey(eKeyCode::A))
		{
			mX -= 0.01f;
		}
		if (parInput::GetKey(eKeyCode::D))
		{
			mX += 0.01f;
		}
		if (parInput::GetKey(eKeyCode::W))
		{
			mY -= 0.01;
		}
		if (parInput::GetKey(eKeyCode::S))
		{
			mY += 0.01f;
		}
	}

	void par::parGameObject::LateUpdate()
	{
	}

	void par::parGameObject::Render(HDC hdc)
	{
	}
}