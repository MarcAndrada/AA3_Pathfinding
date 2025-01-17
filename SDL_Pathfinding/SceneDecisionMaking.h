#pragma once
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <time.h>

#include "Scene.h"
#include "Seek.h"
#include "PathFollowing.h"
#include "A.h"

class SceneDecisionMaking :	public Scene
{
public:
	SceneDecisionMaking();
	~SceneDecisionMaking();
	void update(float dtime, SDL_Event* event);
	void draw();
	virtual const char* getTitle() override;

protected:
	std::vector<Agent*> agents;
	Vector2D coinPosition;

	Grid* maze;
	bool draw_grid;

	PathFindingAlgorithm* algorithm;

	virtual void drawMaze();
	virtual void drawCoin();
	SDL_Texture* background_texture;
	SDL_Texture* coin_texture;
	virtual bool loadTextures(char* filename_bg, char* filename_coin);
	virtual void setAlgorithm(PathFindingAlgorithm*);
};
