#include<iostream>
#include<glad/glad.h>
#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include<string>
#include<vector>

#include"ChunkManager.h"
#include"Chunk.h"
#include"Tile.h"
#include"TileManager.h"

void ChunkManager::BuildChunkMesh(Chunk& chunk, TileManager& tileManager, std::string textureAtlasPath)
{
	sf::Image image;
	if (!image.loadFromFile(textureAtlasPath))
	{
		// handle error
	}

	image.flipVertically();

	sf::Texture chunkTextureAtlas;
	if (!chunkTextureAtlas.loadFromImage(image)) {
		// Handle error
	}

	GLuint texID = chunkTextureAtlas.getNativeHandle();
	glGenTextures(1, &texID);
	glBindTexture(GL_TEXTURE_2D, texID);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	// TileManager.BuildTile 

	for (int i = 0; i < CHUNK_SIZE; i++) {
		for (int j = 0; j < CHUNK_SIZE; i++) {

		}
	}
}