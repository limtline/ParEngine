#include "parGameObject.h"

par::parGameObject::parGameObject()
{
}

par::parGameObject::~parGameObject()
{
}

void par::parGameObject::Update()
{
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		mX -= 0.01f;
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		mX += 0.01f;
	}
	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		mY -= 0.01;
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
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
