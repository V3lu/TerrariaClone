#include "Chunk.h"
#include<vector>
#pragma once

class World
{
public:
	std::vector<Chunk> chunks;

	void InitializeWorld(int numChunks, int chunkWidth);
};