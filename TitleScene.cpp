#include "TitleScene.h"

TitleScene::TitleScene(SDL_Renderer *renderer)
{
	nextScene = -1;
	this->renderer = renderer;
	loadMedia();
}

bool TitleScene::loadMedia()
{
	bool success = false;
	backgroundTexture = loadTexture("Sprites/background_title.png");
	if (backgroundTexture == NULL)
	{
		printf("Failed to load texture image!\n");
		success = false;
	}
	return success;
}

void TitleScene::update(Timer deltaTime, std::vector<SDL_Keycode> keysPressed, const Uint8 *keyboardState)
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

void TitleScene::draw()
{
	SDL_SetRenderDrawColor(renderer, 0x88, 0x88, 0x88, 0xFF);
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);
	SDL_RenderPresent(renderer);
}

void TitleScene::close()
{
	SDL_DestroyTexture(backgroundTexture);
}