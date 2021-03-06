#pragma once
#include "Scene.h"
#include "Camera.h"
#include "Player.h"
#include "Enemy.h"
#include "Block.h"
#include "Transportation.h"

class PlayScene : public Scene
{
public:
	PlayScene() = default;
	PlayScene(SDL_Renderer * renderer);
	bool loadMedia() override;
	void update(Timer deltaTime, std::vector<SDL_Keycode> keysPressed, const Uint8 *keyboardState) override;
	void draw() override;
	void close() override;
	void loadBlocks();
	bool checkCollision(SDL_Rect *rectA, SDL_Rect *rectB);
private:
	SDL_Texture *backgroundTexture = NULL;
	SDL_Texture *playerTextures[4] = { 0 };
	SDL_Texture *enemyTextures[2] = { 0 };
	SDL_Texture *blockTexture = NULL;
	SDL_Rect backgroundRect;
	Camera camera;
	Timer deltaTime;
	Player player;
	Enemy enemy;
	std::vector<Block> blocks;
	std::vector<Transportation> transportations;
	bool movePlayer;
	std::ifstream map;
	int setInterrupt;
	Mix_Chunk *jumpSound = NULL;
	Mix_Chunk *blockSound = NULL;
	Mix_Chunk *dieSound = NULL;
	SDL_Rect victoryRect;
	SDL_Rect secretRect;

};