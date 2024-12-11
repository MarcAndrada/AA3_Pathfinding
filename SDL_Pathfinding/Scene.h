#pragma once
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <time.h>
#include "Agent.h"
#include "Seek.h"
#include "PathFollowing.h"
#include "Grid.h"


class Scene
{
public:
	Scene();
	virtual ~Scene();
	virtual void update(float dtime, SDL_Event *event) = 0;
	virtual void draw() = 0;
	virtual const char* getTitle() { return ""; };

protected:
	std::vector<Agent*> agents;
	Vector2D coinPosition;

	Grid* maze;
	bool draw_grid;

	virtual void drawMaze();
	virtual void drawCoin();
	SDL_Texture* background_texture;
	SDL_Texture* coin_texture;
	virtual bool loadTextures(char* filename_bg, char* filename_coin);
};

