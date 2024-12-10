#include "parCatScript.h"
#include "parInput.h"
#include "parTransform.h"
#include "parTime.h"
#include "parGameObject.h"
#include "parAnimator.h"

namespace par
{
	CatScript::CatScript()
		: mState(CatScript::eState::SitDown),
		mAnimator(nullptr),
		mTime(0.0f)
	{
	}
	CatScript::~CatScript()
	{
	}
	void CatScript::Initialize()
	{
	}
	void CatScript::Update()
	{
		if (mAnimator == nullptr)
		{
			mAnimator = GetOwner()->GetComponent<Animator>();
		}

		switch (mState)
		{
		case par::CatScript::eState::SitDown:
			sitDown();
			break;
		case par::CatScript::eState::Walk:
			move();
			break;
		case par::CatScript::eState::Sleep:
			break;
		case par::CatScript::eState::LayDown:
			break;
		case par::CatScript::eState::Attack:
			break;
		default:
			break;
		}
	}
	void CatScript::LateUpdate()
	{
	}
	void CatScript::Render(HDC hdc)
	{
	}
	void CatScript::sitDown()
	{
		mTime += Time::DeltaTime();
		if (mTime > 3.0f)
		{
			mState = CatScript::eState::Walk;
			int direction = rand() % 4;
			mDirection = (eDirection)direction;
			PlayWalkAnimationByDriection(mDirection);
			mTime = 0.0f;
		}
	}
	void CatScript::move()
	{
		mTime += Time::DeltaTime();
		if (mTime > 2.0f)
		{
			int isLayDown = rand() % 2;
			if (isLayDown)
			{
				mState = eState::LayDown;
				mAnimator->PlayAnimation(L"LayDown", false);
			}
			else
			{
				mState = eState::SitDown;
				mAnimator->PlayAnimation(L"SitDown", false);
			}
		}

		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		translate(tr);
	}

	void CatScript::layDown()
	{

	}

	void CatScript::PlayWalkAnimationByDriection(eDirection dir)
	{
		switch (dir)
		{
		case par::CatScript::eDirection::Left:
			mAnimator->PlayAnimation(L"LeftWalk", true);
			break;
		case par::CatScript::eDirection::Right:
			mAnimator->PlayAnimation(L"RightWalk", true);
			break;
		case par::CatScript::eDirection::Down:
			mAnimator->PlayAnimation(L"DownWalk", true);
			break;
		case par::CatScript::eDirection::Up:
			mAnimator->PlayAnimation(L"UpWalk", true);
			break;
		defalult:
			assert(false);
			break;
		}
	}
	void CatScript::translate(Transform* tr)
	{
		Vector2 pos = tr->GetPosition();
		switch (mDirection)
		{
		case par::CatScript::eDirection::Left:
			pos.x -= 100.0f * Time::DeltaTime();
			break;
		case par::CatScript::eDirection::Right:
			pos.x += 100.0f * Time::DeltaTime();
			break;
		case par::CatScript::eDirection::Down:
			pos.y += 100.0f * Time::DeltaTime();
			break;
		case par::CatScript::eDirection::Up:
			pos.y -= 100.0f * Time::DeltaTime();
			break;
		drefault:
			assert(false);
			break;
		}
		tr->SetPosition(pos);
	}
}