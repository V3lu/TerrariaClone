#include "World.h"
#include "ChunkManager.h"
#include "TileManager.h"

void World::InitializeWorld(int numChunks)
{
	ChunkManager chunkMaganer;
	TileManager tileManager;
	for (int i = 0; i < numChunks; i++) {
		Chunk chunk;
		chunkMaganer.BuildChunkMesh(chunk, tileManager, "Textures/WorldTextures.png");
		World::chunks.push_back(chunk);
	}
}



