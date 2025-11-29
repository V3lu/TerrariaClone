#pragma once

class Game
{
public:
	enum State
	{
		LOAD,
		PLAY,
		END
	};

	void InitializeGame();
};