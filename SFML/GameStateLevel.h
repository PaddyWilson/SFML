#pragma once
#include "GameState.h"
#include "Player.h"
#include "Map.h"
#include "Things.h"

class GameStateLevel : public GameState
{
public:
	GameStateLevel(Game *game);
	~GameStateLevel();

	void load();

	void update(float dt);
	void draw();

private:
	Player player;
	sf::View view;
	Map map;
};
