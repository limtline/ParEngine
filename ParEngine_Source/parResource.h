#pragma once
#include "parEntity.h"

namespace par
{

	class Resource : public Entity	// 추상 클래스 메모리 할당이 불가능 상속받아서 사용해야함
	{
	public:
		Resource(enums::eResourceType type);
		virtual ~Resource();

		virtual HRESULT Load(const std::wstring& path) = 0;	// 순수가상함수 실제메모리 할당이 불가능하다

		const std::wstring& GetPath() { return mPath; }
		void SetPath(const std::wstring& path) {  mPath = path; }

	private:
		const enums::eResourceType mType;
		std::wstring mPath;
	};
}
// 게임에서 사용되는 데이터들의 종류
// 이미지, 사운드, 3스테이지 클리어
// 저장 게임 플레이 데이터 HDD, 클라우드 저장을 해둔다
// 이것도 리소스 이다.
