#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <vector>
#include <string>
#include <algorithm>
#include "SceneList.h"
#include "Timer.h"

class Scene
{
public:
	virtual bool loadMedia();
	virtual void update(Timer deltaTime, std::vector<SDL_Keycode> keysPressed, const Uint8 *keyboardState);
	virtual void draw();
	virtual void close();
	int getNextScene();
	SDL_Texture *loadTexture(std::string path);
protected:
	int nextScene;
	SDL_Renderer *renderer;
};