#pragma once
#include <SFML\Graphics.hpp>
#include <stack>

#include "Things.h"
#include "GameState.h"

#include "TextureManager.h"
#include "FontManager.h"

//add gamestate classes here so they are precompled
class GameState;
class GameStateTest;
class GameStateLevel;
class GSMainMenu;

class Game
{
public:
	sf::RenderWindow window;

	TextureManager textureManager;
	FontManager fontManager;

	std::stack<GameState*> gameState;

	Game();
	~Game();

	void draw();
	void update(float dt);
	void run();

private:

};