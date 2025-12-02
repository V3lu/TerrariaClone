#include "Tile.h"
#include <vector>
#include"VBO.h"
#include"VAO.h"
#include"EBO.h"

#pragma once

const int CHUNK_SIZE = 32;

class Chunk
{
public:
	Tile tiles[CHUNK_SIZE][CHUNK_SIZE];
	VAO VAO;
	VBO VBO;
	EBO EBO;
	int indexCount;

	Chunk();
};
