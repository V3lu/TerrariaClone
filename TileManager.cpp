#include "TileManager.h"
#include "Tile.h"

UVRectOfOneTile TileManager::GetUVRect(TileType type)
{
	int tileX = int(type) % (atlasWidth / tileSize);
	int tileY= int(type) / (atlasWidth / tileSize);

	float u1 = (tileX * tileSize) / float(atlasWidth);
	float v1 = (tileY * tileSize) / float(atlasHeight);
	float u2 = ((tileX + 1) * tileSize) / float(atlasWidth);
	float v2 = ((tileY + 1) * tileSize) / float(atlasHeight);

	return { u1, v1, u2, v2 };
}