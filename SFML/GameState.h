#pragma once
#include "Game.h"

class Game;

class GameState
{
public:
	Game *game;

	virtual void load() = 0;
	virtual void update(float dt) = 0;
	virtual void draw() = 0;

private:

};