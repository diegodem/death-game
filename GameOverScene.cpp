#include "GameOverScene.h"

GameOverScene::GameOverScene(SDL_Renderer *renderer)
{
	nextScene = -1;
	this->renderer = renderer;
	loadMedia();
}

bool GameOverScene::loadMedia()
{
	bool success = false;
	backgroundTexture = loadTexture("Sprites/background_gameover.png");
	if (backgroundTexture == NULL)
	{
		printf("Failed to load texture image!\n");
		success = false;
	}
	return success;
}

void GameOverScene::update(Timer deltaTime, std::vector<SDL_Keycode> keysPressed, const Uint8 *keyboardState)
{
	for (int i = 0; i < keysPressed.size(); i++)
	{
		if (keysPressed[i] == SDLK_SPACE)
		{
			nextScene = (int)SceneList::PLAY_SCENE;
		}
		if (keysPressed[i] == SDLK_c)
		{
			nextScene = (int)SceneList::CREDITS_SCENE;
		}
	}
}

void GameOverScene::draw()
{
	SDL_SetRenderDrawColor(renderer, 0x88, 0x88, 0x88, 0xFF);
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);
	SDL_RenderPresent(renderer);
}

void GameOverScene::close()
{
	SDL_DestroyTexture(backgroundTexture);
}