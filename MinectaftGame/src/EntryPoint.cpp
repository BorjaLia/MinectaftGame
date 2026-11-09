#include "MinecraftGame.h"
#include "EntryPoint.h"

Engine::IGame* CreateGame()
{
	return new MinecraftGame();
}