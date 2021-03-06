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
		free(currentScene);
	}

	if (scene == SceneList::TITLE_SCENE)
	{
		currentScene = new TitleScene(renderer);
	}
	else if (scene == SceneList::INTRO_SCENE)
	{
		Mix_PlayMusic(music, -1);
		currentScene = new IntroScene(renderer);
	}
	else if (scene == SceneList::CONTROLS_SCENE)
	{
		currentScene = new ControlsScene(renderer);
	}
	else if (scene == SceneList::PLAY_SCENE)
	{
		if (!Mix_PlayingMusic())
		{
			Mix_PlayMusic(music, -1);
		}
		
		currentScene = new PlayScene(renderer);
	}
	else if (scene == SceneList::GAME_OVER_SCENE)
	{
		Mix_PlayChannel(-1, dieSound, 0);
		Mix_HaltMusic();
		currentScene = new GameOverScene(renderer);
	}
	else if (scene == SceneList::VICTORY_SCENE)
	{
		Mix_HaltMusic();
		currentScene = new VictoryScene(renderer);
	}
	else if (scene == SceneList::CREDITS_SCENE)
	{
		currentScene = new CreditsScene(renderer);
	}
	else if (scene == SceneList::SECRET_SCENE)
	{
		Mix_HaltMusic();
		currentScene = new SecretScene(renderer);
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

		window = SDL_CreateWindow("Death, is that you?", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
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
	loadMusic();
	deltaTime.start();
	return success;
}
void Engine::loadMusic()
{
	music = Mix_LoadMUS("Music/music.wav");
	if (music == NULL)
	{
		printf("Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError());
	}

	dieSound = Mix_LoadWAV("Sounds/die.wav");
	if (dieSound == NULL)
	{
		printf("Failed to load change sound effect! SDL_mixer Error: %s\n", Mix_GetError());
	}
}

void Engine::close()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	renderer = NULL;
	window = NULL;

	Mix_FreeMusic(music);
	music = NULL;

	Mix_Quit();
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}