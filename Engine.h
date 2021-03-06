// Code by Diego de Miguel (https://github.com/diegodem) - March 2021

#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <stdio.h>
#include <time.h>
#include <string>
#include <cmath>
#include <vector>
#include "Timer.h"
#include "SceneList.h"
#include "Scene.h"
#include "TitleScene.h"
#include "IntroScene.h"
#include "ControlsScene.h"
#include "PlayScene.h"
#include "GameOverScene.h"
#include "VictoryScene.h"
#include "CreditsScene.h"
#include "SecretScene.h"

const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 768;

const int RESOLUTION_WIDTH = 256;
const int RESOLUTION_HEIGHT = 192;

class Engine
{
public:
	Engine();
	bool init();
	void close();
	void loadScene(SceneList scene);
	void loop();
	void loadMusic();

private:
	bool initSuccess;
	SDL_Window *window = NULL;
	SDL_Renderer *renderer = NULL;
	Scene *currentScene = NULL;
	Timer deltaTime;
	Mix_Music *music;
	Mix_Chunk *dieSound = NULL;
};
