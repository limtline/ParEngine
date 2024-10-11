#pragma once
#include "CommonInclude.h"

using namespace par::math;

// 이름 설정 클래스 
namespace par
{
	class Entity
	{
	public:
		Entity();
		virtual ~Entity();

		void SetName(const std::wstring& name) { mName = name; }
		std::wstring& GetName() { return mName; }

	private:
		std::wstring mName;
	};
}

