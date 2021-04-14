#include "Engine.h"
#include <vector>

Engine::Engine()
{

}

void Engine::loop()
{
	bool quit = false;
	SDL_Event e;
	std::vector<SDL_Keycode> keysPressed;

	while (!quit)
	{
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
			else if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
			{
				keysPressed.push_back(e.key.keysym.sym);
			}
		}
		const Uint8 *keyboardState = SDL_GetKeyboardState(NULL);

		currentScene->update(deltaTime, keysPressed, keyboardState);

		deltaTime.updateDT();
		keysPressed.clear();

		currentScene->draw();

		if (currentScene->getNextScene() != -1)
		{
			loadScene((SceneList)currentScene->getNextScene());
		}

	}
}

void Engine::loadScene(SceneList scene)
{
	if (currentScene != NULL)
	{
		currentScene->close();
	}

	if (scene == SceneList::TITLE_SCENE)
	{
		titleScene = TitleScene(renderer);
		currentScene = &titleScene;
	}
	else if (scene == SceneList::PLAY_SCENE)
	{
		playScene = PlayScene(renderer);
		currentScene = &playScene;
	}
}

bool Engine::init()
{
	bool success = true;
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{

		window = SDL_CreateWindow("Attack of the Shapes", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
			if (renderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				SDL_RenderSetLogicalSize(renderer, RESOLUTION_WIDTH, RESOLUTION_HEIGHT);

				SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
					success = false;
				}

				if (TTF_Init() == -1)
				{
					printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
					success = false;
				}

				if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
				{
					printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
					success = false;
				}
			}
		}
	}
	deltaTime.start();
	return success;
}

void Engine::close()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	renderer = NULL;
	window = NULL;

	Mix_Quit();
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}