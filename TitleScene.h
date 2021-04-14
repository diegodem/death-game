#pragma once
#include "Scene.h"

class TitleScene : public Scene
{
public:
	TitleScene() = default;
	TitleScene(SDL_Renderer * renderer);
	bool loadMedia() override;
	void update(Timer deltaTime, std::vector<SDL_Keycode> keysPressed, const Uint8 *keyboardState) override;
	void draw() override;
	void close() override;
private:
	SDL_Texture *backgroundTexture = NULL;
};