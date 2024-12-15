#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

#include "SDL_SimpleApp.h"
#include "ScenePathFindingMouse.h"
#include "SceneTSP.h"

using namespace std;


/*******************************************************************************
 * Main function of the SDL_Pathfinding project.
 *
 * @param  argc An integer argument count of the command line arguments
 * @param  argv An argument array of the command line arguments
 * @return an integer 0 upon exit success
 ******************************************************************************/

int main(int argc, char ** argv)
{
	bool quit = false;
	SDL_Event event;
	
	SDL_SimpleApp *app = SDL_SimpleApp::Instance();

	Scene *curr_scene = new ScenePathFindingMouse;
	app->setWindowTitle(curr_scene->getTitle());

	
	if (argc > 1) {
		cout << argv[1] << endl; 
		exit(0);
	}

	while (!quit)
	{
		// run app frame by frame
		event = app->run(curr_scene);

		/* Keyboard events */
		switch (event.type)
		{
		case SDL_KEYDOWN:
			if (event.key.keysym.scancode == SDL_SCANCODE_1)
			{
				delete curr_scene;
				curr_scene = new ScenePathFindingMouse;
			}
			if (event.key.keysym.scancode == SDL_SCANCODE_2)
			{
			}
			if (event.key.keysym.scancode == SDL_SCANCODE_3)
			{
				delete curr_scene;
				curr_scene = new SceneTSP;
			}
			if (event.key.keysym.scancode == SDL_SCANCODE_4)
			{
			}
			if ((event.key.keysym.scancode == SDL_SCANCODE_Q) || (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE))
			{
				quit = true;
			}
			if (event.key.keysym.scancode == SDL_SCANCODE_F)
			{
				app->setFullScreen();
			}
			break;
		case SDL_QUIT:
			quit = true;
			break;
		}

	}

	return 0;
}