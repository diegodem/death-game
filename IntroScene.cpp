#include "IntroScene.h"

IntroScene::IntroScene(SDL_Renderer *renderer)
{
	nextScene = -1;
	this->renderer = renderer;
	loadMedia();
}

bool IntroScene::loadMedia()
{
	bool success = false;
	backgroundTexture = loadTexture("Sprites/background_intro.spr");
	if (backgroundTexture == NULL)
	{
		printf("Failed to load texture image!\n");
		success = false;
	}
	return success;
}

void IntroScene::update(Timer deltaTime, std::vector<SDL_Keycode> keysPressed, const Uint8 *keyboardState)
{
	for (int i = 0; i < keysPressed.size(); i++)
	{
		if (keysPressed[i] == SDLK_SPACE)
		{
			nextScene = (int)SceneList::CONTROLS_SCENE;
		}
	}
}

void IntroScene::draw()
{
	SDL_SetRenderDrawColor(renderer, 0x88, 0x88, 0x88, 0xFF);
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);
	SDL_RenderPresent(renderer);
}

void IntroScene::close()
{
	SDL_DestroyTexture(backgroundTexture);
	backgroundTexture = NULL;
}