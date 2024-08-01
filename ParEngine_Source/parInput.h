#pragma once
#include "CommonInclude.h"

namespace par
{
	enum class eKeyState
	{
		Down,
		Pressed,
		Up,
		None,
	};
	enum class eKeyCode
	{
		Q, W, E, R, T, Y, U, I, O, P,
		A, S, D, F, G, H, J, K, L,
		Z, X, C, V, B, N, M,
		Left, Right, Down, Up,
		End,
	};

	class parInput
	{
	public:
		struct Key
		{
			eKeyCode keyCode;
			eKeyState state;
			bool bPressed;
		};
		static void Initailize();
		static void Update();

		static bool GetKeyDown(eKeyCode code) { return mKeys[(UINT)code].state == eKeyState::Down; }
		static bool GetKeyUP(eKeyCode code) { return mKeys[(UINT)code].state == eKeyState::Up; }
		static bool GetKey(eKeyCode code) { return mKeys[(UINT)code].state == eKeyState::Pressed; }

	private:
		static void createKeys();
		static void updateKeys();
		static void updateKey(parInput::Key& key);
		static bool isKeyDown(eKeyCode code);
		static void updateKeyDown(parInput::Key& key);
		static void updateKeyUp(parInput::Key& key);

	private:
		static std::vector<Key> mKeys;
	};
}

