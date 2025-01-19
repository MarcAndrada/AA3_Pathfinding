#include "SceneDecisionMaking.h"
#include "PlayerManager.h"
#include "GridManager.h"
using namespace std;

SceneDecisionMaking::SceneDecisionMaking()
{
	draw_grid = false;
	MAZE.SetGrid(new Grid("../res/maze.csv"));

	loadTextures("../res/maze.png", "../res/coin.png");

	srand((unsigned int)time(NULL));

	Agent* player = new Agent;
	player->loadSpriteTexture("../res/soldier.png", 4);
	player->setBehavior(new PathFollowing);
	player->setTarget(Vector2D(-20, -20));
	agents.push_back(player);

	Agent* enemy = new Agent(true, 50, 50);
	enemy->loadSpriteTexture("../res/soldier.png", 4);
	enemy->setBehavior(new PathFollowing);
	enemy->setTarget(Vector2D(-20, -20));
	agents.push_back(enemy);

	// set agent position coords to the center of a random cell
	
	PLAYER.SetPlayer(player);
	PLAYER.GetPlayer()->setPosition(MAZE.GetGrid()->cell2pix(MAZE.GetRandomGridPoint()));
	player->setAlgorithm(new A(MAZE.GetGrid(), PLAYER.GetPlayer()));

	enemy->setPosition(MAZE.GetGrid()->cell2pix(MAZE.GetRandomGridPoint()));
	enemy->setAlgorithm(new A(MAZE.GetGrid(), enemy));
}

SceneDecisionMaking::~SceneDecisionMaking()
{
	if (background_texture)
		SDL_DestroyTexture(background_texture);

	for (int i = 0; i < (int)agents.size(); i++)
	{
		delete agents[i];
	}
}

void SceneDecisionMaking::update(float dtime, SDL_Event* event)
{
	/* Keyboard & Mouse events */
	switch (event->type) {
	case SDL_KEYDOWN:
		if (event->key.keysym.scancode == SDL_SCANCODE_SPACE)
			draw_grid = !draw_grid;
		break;
	case SDL_MOUSEMOTION:
	case SDL_MOUSEBUTTONDOWN:
		if (event->button.button == SDL_BUTTON_LEFT)
		{
			Vector2D cell = MAZE.GetGrid()->pix2cell(Vector2D((float)(event->button.x), (float)(event->button.y)));
			if (MAZE.GetGrid()->isValidCell(cell)) {
				//Aqui calcular el path del player y añadirle cada punto del camino al player
				agents[0]->clearPath();
				agents[0]->getAlgorithm()->initAlgorithm(new Node(cell, 1));
			}
		}
		break;
	default:
		break;
	}


	for (Agent* currentAgent : agents)
	{
		currentAgent->update(dtime, event);
	}
}

void SceneDecisionMaking::draw()
{
	drawMaze();

	if (draw_grid)
	{
		SDL_SetRenderDrawColor(TheApp::Instance()->getRenderer(), 255, 255, 255, 127);
		for (int i = 0; i < SRC_WIDTH; i += CELL_SIZE)
		{
			SDL_RenderDrawLine(TheApp::Instance()->getRenderer(), i, 0, i, SRC_HEIGHT);
		}
		for (int j = 0; j < SRC_HEIGHT; j = j += CELL_SIZE)
		{
			SDL_RenderDrawLine(TheApp::Instance()->getRenderer(), 0, j, SRC_WIDTH, j);
		}
	}

	for (Agent* currentAgent : agents)
	{
		currentAgent->draw();
	}
}

const char* SceneDecisionMaking::getTitle()
{
	return "SDL Path Finding :: Decision Making";
}

void SceneDecisionMaking::drawMaze()
{
	SDL_SetRenderDrawColor(TheApp::Instance()->getRenderer(), 0, 0, 255, 255);
	SDL_Rect rect;
	Vector2D coords;
	for (int j = 0; j < MAZE.GetGrid()->getNumCellY(); j++)
	{
		for (int i = 0; i < MAZE.GetGrid()->getNumCellX(); i++)
		{
			if (!MAZE.GetGrid()->isValidCell(Vector2D((float)i, (float)j)))
			{
				SDL_SetRenderDrawColor(TheApp::Instance()->getRenderer(), 0, 0, 255, 255);
				coords = MAZE.GetGrid()->cell2pix(Vector2D((float)i, (float)j)) - Vector2D((float)CELL_SIZE / 2, (float)CELL_SIZE / 2);
				rect = { (int)coords.x, (int)coords.y, CELL_SIZE, CELL_SIZE };
				SDL_RenderFillRect(TheApp::Instance()->getRenderer(), &rect);
			}
			else {
				// Do not draw if it is not necessary (bg is already black)
			}


		}
	}
	//Alternative: render a backgroud texture:
	//SDL_RenderCopy(TheApp::Instance()->getRenderer(), background_texture, NULL, NULL );
}

void SceneDecisionMaking::drawCoin()
{
	Vector2D coin_coords = MAZE.GetGrid()->cell2pix(coinPosition);
	int offset = CELL_SIZE / 2;
	SDL_Rect dstrect = { (int)coin_coords.x - offset, (int)coin_coords.y - offset, CELL_SIZE, CELL_SIZE };
	SDL_RenderCopy(TheApp::Instance()->getRenderer(), coin_texture, NULL, &dstrect);
}

bool SceneDecisionMaking::loadTextures(char* filename_bg, char* filename_coin)
{
	SDL_Surface* image = IMG_Load(filename_bg);
	if (!image) {
		cout << "IMG_Load: " << IMG_GetError() << endl;
		return false;
	}
	background_texture = SDL_CreateTextureFromSurface(TheApp::Instance()->getRenderer(), image);

	if (image)
		SDL_FreeSurface(image);

	image = IMG_Load(filename_coin);
	if (!image) {
		cout << "IMG_Load: " << IMG_GetError() << endl;
		return false;
	}
	coin_texture = SDL_CreateTextureFromSurface(TheApp::Instance()->getRenderer(), image);

	if (image)
		SDL_FreeSurface(image);

	return true;
}

