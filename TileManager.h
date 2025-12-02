#include "Tile.h"
#pragma once

struct UVRectOfOneTile
{
	float u1, v1; //bottom-left corner
	float u2, v2; //top-right corner
};

class TileManager
{
	int tileSize;
	int atlasWidth;
	int atlasHeight;

	UVRectOfOneTile GetUVRect(TileType type);
};
