#pragma once
#include "Scene.h"

class ScenePathFindingMouse :
	public Scene
{
public:
	ScenePathFindingMouse() {};
	~ScenePathFindingMouse() {};
	void update(float dtime, SDL_Event *event);
	void draw();
	virtual const char* getTitle() override;
};
