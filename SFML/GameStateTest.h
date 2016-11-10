#pragma once
#include <vector>

#include "GameState.h"

#include "Player.h"
#include "Text.h"
#include "Protectile.h"

class GameStateTest : public GameState
{
public:
	GameStateTest(Game *game);
	~GameStateTest();

	void load();
	void update(float dt);
	void draw();


private:
	Player player;
	Text text;
	std::vector<Projectile> pros;
};