#include "World.h"
#include "Game.h"
#include "Chunk.h"

void Game::InitializeGame()
{
	World world;
	world.InitializeWorld(20);
}