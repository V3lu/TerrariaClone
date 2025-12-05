#pragma once

enum State
{
	LOAD,
	PLAY,
	END
};

class Game
{
public:
	State state;
	void InitializeGame(int numChunks);
};