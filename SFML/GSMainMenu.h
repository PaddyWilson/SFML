#pragma once
#include "GameState.h"
#include "Text.h"
#include "TextButton.h"

class GSMainMenu : public GameState
{
public:
	GSMainMenu(Game *game);
	~GSMainMenu();

	void load();
	void update(float dt);
	void draw();

private:
	TextButton btnTextlvl;

};

GSMainMenu::GSMainMenu(Game *game)
{
	this->game = game;
	btnTextlvl = TextButton("Test Level", game->fontManager.getRef("arial"), 30, 30, 30, sf::Color::Red, sf::Color::Blue);
}

GSMainMenu::~GSMainMenu()
{
}

void GSMainMenu::load()
{
}


sf::Vector2f perv = sf::Vector2f();
void GSMainMenu::update(float dt)
{

	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && btnTextlvl.IsSelected())
	{
		game->gameState.push(new GameStateTest(game));
	}

	btnTextlvl.update(dt, (sf::Vector2f)sf::Mouse::getPosition(game->window));
}

inline void GSMainMenu::draw()
{
	btnTextlvl.draw(game->window);
}
