#include "CreditsScene.h"

CreditsScene::CreditsScene(SDL_Renderer *renderer)
{
	nextScene = -1;
	this->renderer = renderer;
	loadMedia();
}

bool CreditsScene::loadMedia()
{
	bool success = false;
	backgroundTexture = loadTexture("Sprites/background_credits.png");
	if (backgroundTexture == NULL)
	{
		printf("Failed to load texture image!\n");
		success = false;
	}
	return success;
}

void CreditsScene::update(Timer deltaTime, std::vector<SDL_Keycode> keysPressed, const Uint8 *keyboardState)
{
	for (int i = 0; i < keysPressed.size(); i++)
	{
		if (keysPressed[i] == SDLK_SPACE)
		{
			nextScene = (int)SceneList::PLAY_SCENE;
		}
		if (keysPressed[i] == SDLK_c)
		{
			nextScene = (int)SceneList::PLAY_SCENE;
		}
	}
}

void CreditsScene::draw()
{
	SDL_SetRenderDrawColor(renderer, 0x88, 0x88, 0x88, 0xFF);
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);
	SDL_RenderPresent(renderer);
}

void CreditsScene::close()
{
	SDL_DestroyTexture(backgroundTexture);
}