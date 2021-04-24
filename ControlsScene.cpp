#include "ControlsScene.h"

ControlsScene::ControlsScene(SDL_Renderer *renderer)
{
	nextScene = -1;
	this->renderer = renderer;
	loadMedia();
}

bool ControlsScene::loadMedia()
{
	bool success = false;
	backgroundTexture = loadTexture("Sprites/background_controls.spr");
	if (backgroundTexture == NULL)
	{
		printf("Failed to load texture image!\n");
		success = false;
	}
	return success;
}

void ControlsScene::update(Timer deltaTime, std::vector<SDL_Keycode> keysPressed, const Uint8 *keyboardState)
{
	for (int i = 0; i < keysPressed.size(); i++)
	{
		if (keysPressed[i] == SDLK_SPACE)
		{
			nextScene = (int)SceneList::PLAY_SCENE;
		}
	}
}

void ControlsScene::draw()
{
	SDL_SetRenderDrawColor(renderer, 0x88, 0x88, 0x88, 0xFF);
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);
	SDL_RenderPresent(renderer);
}

void ControlsScene::close()
{
	SDL_DestroyTexture(backgroundTexture);
	backgroundTexture = NULL;
}