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

bool Input::Trigger(char key)
{
	return keys[key] && !oldkeys[key];
}
