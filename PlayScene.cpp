#include "PlayScene.h"

PlayScene::PlayScene(SDL_Renderer *renderer)
{
	nextScene = -1;
	this->renderer = renderer;
	loadMedia();
	backgroundRect = { 0, 0, 1024, 192 };
	camera = Camera();
	deltaTime.start();
}

bool PlayScene::loadMedia()
{
	bool success = false;
	backgroundTexture = loadTexture("Sprites/test_background.png");
	if (backgroundTexture == NULL)
	{
		printf("Failed to load texture image!\n");
		success = false;
	}
	return success;
}

void PlayScene::loadBlocks()
{
	for (int i = 0; i < 64; i++)
	{
		blocks.push_back(Block(160, i * 16));
	}
}

void PlayScene::update(Timer deltaTime, std::vector<SDL_Keycode> keysPressed, const Uint8 *keyboardState)
{
	for (int i = 0; i < keysPressed.size(); i++)
	{
		if (keysPressed[i] == SDLK_SPACE)
		{
			player.jump();
		}

	}
	if (keyboardState[SDL_SCANCODE_D])
	{
		player.moveRight(deltaTime.getTime() * 50);

		if (player.getX() >= 64)
		{
			camera.moveRight(deltaTime.getTime() * 50);
		}
		player.getRect()->x = (int)round(player.getX() - camera.getX());
	}
	backgroundRect.x = - camera.getX();

	player.update(deltaTime.getTime());

	enemy.getRect()->x = (int)round(enemy.getX() - camera.getX());

	deltaTime.start();
}

void PlayScene::draw()
{
	SDL_SetRenderDrawColor(renderer, 0x88, 0x88, 0x88, 0xFF);
	SDL_RenderClear(renderer);
	//SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);
	SDL_RenderCopy(renderer, backgroundTexture, NULL, &backgroundRect);
	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
	SDL_RenderDrawRect(renderer, player.getRect());
	SDL_RenderDrawRect(renderer, enemy.getRect());
	
	SDL_RenderPresent(renderer);
}

void PlayScene::close()
{
	SDL_DestroyTexture(backgroundTexture);
}

bool PlayScene::checkCollision(SDL_Rect *rectA, SDL_Rect *rectB)
{
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	leftA = rectA->x;
	rightA = rectA->x + rectA->w;
	topA = rectA->y;
	bottomA = rectA->y + rectA->h;

	leftB = rectB->x;
	rightB = rectB->x + rectB->w;
	topB = rectB->y;
	bottomB = rectB->y + rectB->h;

	if (bottomA <= topB)
	{
		return false;
	}

	if (topA >= bottomB)
	{
		return false;
	}

	if (rightA <= leftB)
	{
		return false;
	}

	if (leftA >= rightB)
	{
		return false;
	}

	return true;
}