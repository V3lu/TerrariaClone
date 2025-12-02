#include"Chunk.h"
#include"TileManager.h"

#pragma once

class ChunkManager
{
public:
	void BuildChunkMesh(Chunk& chunk, TileManager& tileManager, std::string textureAtlasPath);

};