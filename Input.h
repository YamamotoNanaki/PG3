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
	// �ŐV�̃L�[�{�[�h���p
	char keys[256] = { 0 };

	// 1���[�v(�t���[��)�O�̃L�[�{�[�h���
	char oldkeys[256] = { 0 };
public:
	static Input* Instance();
	void Update();
	bool Trigger(char key);
};

