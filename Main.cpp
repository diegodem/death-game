// Code by Diego de Miguel (https://github.com/diegodem) - March 2021

#include "Engine.h"
#include "SceneList.h"


int main(int argc, char *args[])
{
	Engine engine = Engine();

	engine.init();

	engine.loadScene(SceneList::TITLE_SCENE);

	engine.loop();

	engine.close();

	return 0;
}