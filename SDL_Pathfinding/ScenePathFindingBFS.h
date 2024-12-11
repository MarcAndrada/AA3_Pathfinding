#pragma once

#include "Scene.h"
#include "BFS.h"

class ScenePathFindingBFS :
    public Scene
{
public:
	ScenePathFindingBFS() {}
	~ScenePathFindingBFS() {}
	void update(float dtime, SDL_Event* event);
	void draw();
	const char* getTitle();
};

