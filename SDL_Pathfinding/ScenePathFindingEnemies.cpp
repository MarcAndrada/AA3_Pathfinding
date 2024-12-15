#include "ScenePathFindingEnemies.h"

using namespace std;

ScenePathFindingEnemies::ScenePathFindingEnemies()
{
	draw_grid = false;
	maze = new Grid("../res/maze.csv");

	loadTextures("../res/maze.png", "../res/coin.png");

	srand((unsigned int)time(NULL));

	Agent* agent = new Agent;
	agent->loadSpriteTexture("../res/soldier.png", 4);
	agent->setBehavior(new PathFollowing);
	agent->setTarget(Vector2D(-20, -20));
	agents.push_back(agent);


	// set agent position coords to the center of a random cell
	Vector2D rand_cell(-1, -1);
	while (!maze->isValidCell(rand_cell))
		rand_cell = Vector2D((float)(rand() % maze->getNumCellX()), (float)(rand() % maze->getNumCellY()));
	agents[0]->setPosition(maze->cell2pix(rand_cell));

	// set the coin in a random cell (but at least 3 cells far from the agent)
	coinPosition = Vector2D(-1, -1);
	while ((!maze->isValidCell(coinPosition)) || (Vector2D::Distance(coinPosition, rand_cell) < 3))
		coinPosition = Vector2D((float)(rand() % maze->getNumCellX()), (float)(rand() % maze->getNumCellY()));

	algorithm = new Dijkstra(maze, agents[0]);


	//Inicializar Enemigos
	Agent* currentEnemy = new Agent(true, 5, 10);
	currentEnemy->loadSpriteTexture("../res/soldier.png", 4);
	currentEnemy->setBehavior(new PathFollowing);
	#pragma region Enemy 1 Path
	currentEnemy->setPosition(maze->cell2pix(Vector2D(3, 11)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(3,11)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(3,10)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(4,10)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(5,10)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(6,10)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(7,10)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(7,11)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(7,12)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(7,13)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(7,14)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(8,14)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(9,14)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(10,14)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(11,14)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(12,14)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(13,14)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(14,14)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(15,14)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(16,14)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(17,14)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(17, 15)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(17, 16)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(17, 17)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(17, 18)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(16, 18)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(16, 19)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(16, 20)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(16, 21)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(15, 21)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(14, 21)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(13, 21)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(12, 21)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(11, 21)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(10, 21)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(10, 20)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(10, 19)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(10, 18)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(9, 18)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(8, 18)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(7, 18)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(6, 18)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(6, 19)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(6, 20)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(6, 21)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(5, 21)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(4, 21)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(3, 21)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(2, 21)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(2, 20)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(2, 19)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(2, 18)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(2, 17)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(2, 16)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(2, 15)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(2, 14)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(2, 13)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(2, 12)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(2, 11)));
#pragma endregion
	agents.push_back(currentEnemy);


	currentEnemy = new Agent(true, 5, 10);
	currentEnemy->loadSpriteTexture("../res/soldier.png", 4);
	currentEnemy->setBehavior(new PathFollowing);
	currentEnemy->setPosition(maze->cell2pix(Vector2D(32, 3)));
	#pragma region Enemy 2 Path
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(32, 3)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(32, 4)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(32, 5)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(32, 6)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(31, 6)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(30, 6)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(29, 6)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(28, 6)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(27, 6)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(26, 6)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(25, 6)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(24, 6)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(23, 6)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(22, 6)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(21, 6)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(20, 6)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(19, 6)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(18, 6)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(17, 6)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(16, 6)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(15, 6)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(14, 6)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(13, 6)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(12, 6)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(11, 6)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(10, 6)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(9, 6)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(8, 6)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(7, 6)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(6, 6)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(5, 6)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(4, 6)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(3, 6)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(2, 6)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(2, 5)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(2, 4)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(2, 3)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(2, 2)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(3, 2)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(4, 2)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(5, 2)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(6, 2)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(7, 2)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(8, 2)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(9, 2)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(10, 2)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(11, 2)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(12, 2)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(13, 2)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(14, 2)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(15, 2)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(16, 2)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(17, 2)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(18, 2)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(19, 2)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(20, 2)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(21, 2)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(22, 2)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(23, 2)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(24, 2)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(25, 2)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(26, 2)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(27, 2)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(28, 2)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(29, 2)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(30, 2)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(31, 2)));
	currentEnemy->addPathPoint(maze->cell2pix(Vector2D(32, 2)));
	#pragma endregion
	agents.push_back(currentEnemy);

}

ScenePathFindingEnemies::~ScenePathFindingEnemies()
{
	if (background_texture)
		SDL_DestroyTexture(background_texture);
	if (coin_texture)
		SDL_DestroyTexture(coin_texture);

	for (int i = 0; i < (int)agents.size(); i++)
	{
		delete agents[i];
	}
}

void ScenePathFindingEnemies::update(float dtime, SDL_Event *event)
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
			Vector2D cell = maze->pix2cell(Vector2D((float)(event->button.x), (float)(event->button.y)));
			if (maze->isValidCell(cell)) {
				//Aqui calcular el path del player y añadirle cada punto del camino al player
				algorithm->initAlgorithm(new Node(cell, 1));
			}
		}
		break;
	default:
		break;
	}

	algorithm->update(dtime);
	for (Agent* currentAgent : agents)
	{
		currentAgent->update(dtime, event);
	}

	// if we have arrived to the coin, replace it in a random cell!
	if ((agents[0]->getCurrentTargetIndex() == -1) && (maze->pix2cell(agents[0]->getPosition()) == coinPosition))
	{
		coinPosition = Vector2D(-1, -1);
		while ((!maze->isValidCell(coinPosition)) || (Vector2D::Distance(coinPosition, maze->pix2cell(agents[0]->getPosition()))<3))
			coinPosition = Vector2D((float)(rand() % maze->getNumCellX()), (float)(rand() % maze->getNumCellY()));
	}
}

void ScenePathFindingEnemies::draw()
{
	drawMaze();
	drawCoin();

	if (draw_grid)
	{
		SDL_SetRenderDrawColor(TheApp::Instance()->getRenderer(), 255, 255, 255, 127);
		for (int i = 0; i < SRC_WIDTH; i+=CELL_SIZE)
		{
			SDL_RenderDrawLine(TheApp::Instance()->getRenderer(), i, 0, i, SRC_HEIGHT);
		}
		for (int j = 0; j < SRC_HEIGHT; j = j += CELL_SIZE)
		{
			SDL_RenderDrawLine(TheApp::Instance()->getRenderer(), 0, j, SRC_WIDTH, j);
		}
	}

	algorithm->draw();
	for (Agent* currentAgent : agents)
	{
		currentAgent->draw();
	}
	
}

const char* ScenePathFindingEnemies::getTitle()
{
	return "SDL Path Finding :: PathFinding Enemies";
}

void ScenePathFindingEnemies::drawMaze()
{
	SDL_SetRenderDrawColor(TheApp::Instance()->getRenderer(), 0, 0, 255, 255);
	SDL_Rect rect;
	Vector2D coords;
	for (int j = 0; j < maze->getNumCellY(); j++)
	{
		for (int i = 0; i < maze->getNumCellX(); i++)
		{
			if (!maze->isValidCell(Vector2D((float)i, (float)j)))
			{
				SDL_SetRenderDrawColor(TheApp::Instance()->getRenderer(), 0, 0, 255, 255);
				coords = maze->cell2pix(Vector2D((float)i, (float)j)) - Vector2D((float)CELL_SIZE / 2, (float)CELL_SIZE / 2);
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

void ScenePathFindingEnemies::drawCoin()
{
	Vector2D coin_coords = maze->cell2pix(coinPosition);
	int offset = CELL_SIZE / 2;
	SDL_Rect dstrect = { (int)coin_coords.x - offset, (int)coin_coords.y - offset, CELL_SIZE, CELL_SIZE };
	SDL_RenderCopy(TheApp::Instance()->getRenderer(), coin_texture, NULL, &dstrect);
}

bool ScenePathFindingEnemies::loadTextures(char* filename_bg, char* filename_coin)
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

void ScenePathFindingEnemies::setAlgorithm(PathFindingAlgorithm* _algorithm)
{
	algorithm = _algorithm;
}
