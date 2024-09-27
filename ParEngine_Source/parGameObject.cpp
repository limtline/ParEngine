#include "parGameObject.h"
#include "parInput.h"
#include "parTime.h"

namespace par
{
	par::GameObject::GameObject() : mX(0.0f), mY(0.0f)
	{
	}

	par::GameObject::~GameObject()
	{
	}

	void par::GameObject::Update()
	{
		const float speed = 100.0f;

		if (Input::GetKey(eKeyCode::A))
		{
			mX -= speed * Time::DelatTime();
		}
		if (Input::GetKey(eKeyCode::D))
		{
			mX += speed * Time::DelatTime();
		}
		if (Input::GetKey(eKeyCode::W))
		{
			mY -= speed * Time::DelatTime();
		}
		if (Input::GetKey(eKeyCode::S))
		{
			mY += speed * Time::DelatTime();
		}
	}

	void par::GameObject::LateUpdate()
	{
	}

	void par::GameObject::Render(HDC hdc)
	{
		HBRUSH blueBresh = CreateSolidBrush(RGB(rand() % 255, rand() % 255 , rand() % 255));

		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, blueBresh);

		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(rand() % 255, rand() % 255, rand() % 255));
		HPEN oldPen = (HPEN)SelectObject(hdc, redPen);
		SelectObject(hdc, oldPen);

		Ellipse(hdc, mX, mY, 100 + mX, 100 + mY);

		SelectObject(hdc, oldBrush);
		DeleteObject(blueBresh);
		DeleteObject(redPen);
	}
}