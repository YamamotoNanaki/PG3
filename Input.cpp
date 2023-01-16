#include "Input.h"
#include "DxLib.h"

Input* Input::Instance()
{
	static Input inst;
	return &inst;
}

void Input::Update()
{
	for (size_t i = 0; i < 256; i++)oldkeys[i] = keys[i];
	GetHitKeyStateAll(keys);
}

bool Input::Trigger()
{
	return keys[KEY_INPUT_SPACE] && !oldkeys[KEY_INPUT_SPACE];
}
