#pragma once

class Input
{
private:
	Input() {}
	~Input() {}
public:
	Input(const Input&) = delete;
	Input& operator=(const Input&) = delete;

private:
	// 最新のキーボード情報用
	char keys[256] = { 0 };

	// 1ループ(フレーム)前のキーボード情報
	char oldkeys[256] = { 0 };
public:
	static Input* Instance();
	void Update();
	bool Trigger(char key);
};

