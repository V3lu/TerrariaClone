#include "World.h"

void World::InitializeWorld(int numChunks)
{
	for (int i = 0; i < numChunks; i++) {
		Chunk chunk;
		World::chunks.push_back(chunk);
	}
}



