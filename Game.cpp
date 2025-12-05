#include "World.h"
#include "Game.h"
#include "Chunk.h"

void Game::InitializeGame(int numChunks)
{
	World world;
	world.InitializeWorld(numChunks);
}