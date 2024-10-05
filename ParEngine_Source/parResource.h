#pragma once
#include "parEntity.h"

namespace par
{

	class Resource : public Entity	// �߻� Ŭ���� �޸� �Ҵ��� �Ұ��� ��ӹ޾Ƽ� ����ؾ���
	{
	public:
		Resource(enums::eResourceType type);
		virtual ~Resource();

		virtual HRESULT Load(const std::wstring& path) = 0;	// ���������Լ� �����޸� �Ҵ��� �Ұ����ϴ�

		const std::wstring& GetPath() { return mPath; }
		void SetPath(const std::wstring& path) {  mPath = path; }

	private:
		const enums::eResourceType mType;
		std::wstring mPath;
	};
}
// ���ӿ��� ���Ǵ� �����͵��� ����
// �̹���, ����, 3�������� Ŭ����
// ���� ���� �÷��� ������ HDD, Ŭ���� ������ �صд�
// �̰͵� ���ҽ� �̴�.
