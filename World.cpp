#include "World.h"

void World::InitializeWorld(int numChunks, int chunkWidth)
{
	for (int i = 0; i < numChunks; i++) {
		Chunk chunk(chunkWidth);
		World::chunks.emplace_back(chunk);
	}
}



