#pragma once
#include "Scene.h"

class SceneManager final
{
private:
	SceneManager() {}
	~SceneManager() {}
public:
	SceneManager(const SceneManager&) = delete;
	SceneManager& operator=(const SceneManager&) = delete;

public:
	enum sceneNo
	{
		TITLE, NEWGAME, GAMEPLAY, GAMECLEAR
	};

public:
	static SceneManager* Instance();
	void ChangeScene(int sceneNo);
	void Update();
	void Draw();

private:
	Scene* scene = nullptr;
};
