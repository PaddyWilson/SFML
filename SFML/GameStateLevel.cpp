#include "GameStateLevel.h"

GameStateLevel::GameStateLevel(Game *game) : player(20, 20, 20, 20), map(50,50)
{
	this->game = game;
	view.setSize((float)Things::windowWidth, (float)Things::windowHeight);
	view.setCenter((float)Things::windowWidth / 2, (float)Things::windowHeight / 2);
}

GameStateLevel::~GameStateLevel()
{
}

void GameStateLevel::load()
{
}

void GameStateLevel::update(float dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		view.move(0, -20 * dt);
	}

	player.update(dt);
	view.setCenter(player.rectangle.getPosition());
	//cout << player.rectangle.getPosition().x << " " << player.rectangle.getPosition().y << " " << view.getCenter().x << " " << view.getCenter().y << endl;
}

void GameStateLevel::draw()
{
	game->window.setView(view);

	game->window.draw(map);
	player.draw(game->window);

}