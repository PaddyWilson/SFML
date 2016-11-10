#include "GameStateTest.h"

GameStateTest::GameStateTest(Game *game) : player(10, 10, 20, 20)
{
	this->game = game;
	text = Text("Hello", game->fontManager.getRef("arial"));
}

GameStateTest::~GameStateTest()
{
}

void GameStateTest::load()
{
}

sf::Clock r, l;

void GameStateTest::update(float dt)
{
	//clean up project tiles
	for (size_t i = 0; i < pros.size(); i++)
	{
		if (pros.at(i).getTime() > 10)
		{
			pros.erase(pros.begin() + i);
		}
	}


	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && l.getElapsedTime().asSeconds() >= 1)
	{
		l.restart();
		pros.push_back(Projectile(player.rectangle.getPosition(), (sf::Vector2f)sf::Mouse::getPosition(game->window), sf::Vector2f(150, 150), 10, sf::Color::Blue));
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right) && r.getElapsedTime().asSeconds() >= 1)
	{
		r.restart();

		pros.push_back(Projectile(player.rectangle.getPosition(), (sf::Vector2f)sf::Mouse::getPosition(game->window), sf::Vector2f(0, 0), 100, sf::Color::Red));
		pros.at(pros.size() - 1).pro.setOutlineThickness(20);
		pros.at(pros.size() - 1).pro.setOutlineColor(sf::Color::Red);
		pros.at(pros.size() - 1).pro.setFillColor(sf::Color(100, 0, 0, 0));
		/*for (int i = -10; i < 20; i++)
		{
			pros.push_back(Projectile(player.rectangle.getPosition(), player.rectangle.getPosition() + sf::Vector2f(-10, i), sf::Vector2f(150, 150), 10, sf::Color::Blue));
		}
		for (int i = -10; i < 20; i++)
		{
			pros.push_back(Projectile(player.rectangle.getPosition(), player.rectangle.getPosition() + sf::Vector2f(i, -10), sf::Vector2f(150, 150), 10, sf::Color::Blue));
		}
		for (int i = 10; i > -20; i--)
		{
			pros.push_back(Projectile(player.rectangle.getPosition(), player.rectangle.getPosition() + sf::Vector2f(10, i), sf::Vector2f(150, 150), 10, sf::Color::Blue));
		}
		for (int i = 10; i > -20; i--)
		{
			pros.push_back(Projectile(player.rectangle.getPosition(), player.rectangle.getPosition() + sf::Vector2f(i, 10), sf::Vector2f(150, 150), 10, sf::Color::Blue));
		}*/
		/*for (size_t i = -5; i < 5; i++)
		{
			pros.push_back(Projectile(player.rectangle.getPosition(), player.rectangle.getPosition() + sf::Vector2f(i, -5), sf::Vector2f(150, 150), 10, sf::Color::Blue));
		}*/
		/*for (size_t i = -5; i < 5; i++)
		{
			pros.push_back(Projectile(player.rectangle.getPosition(), player.rectangle.getPosition() + sf::Vector2f(-5, i), sf::Vector2f(150, 150), 10, sf::Color::Blue));
		}
		for (size_t i = -5; i < 5; i++)
		{
			pros.push_back(Projectile(player.rectangle.getPosition(), player.rectangle.getPosition() + sf::Vector2f(-5, i), sf::Vector2f(150, 150), 10, sf::Color::Blue));
		}*/
	}


	for (size_t i = 0; i < pros.size(); i++)
	{
		pros.at(i).update(dt);
	}
	player.update(dt);
	
	text.setText( std::to_string((int)Things::getDT().asMicroseconds()) +
		"\n" + std::to_string(player.rectangle.getPosition().x) + " " + std::to_string(player.rectangle.getPosition().y) +
		"\n" + std::to_string(pros.size()) +
		"\n" + std::to_string(pros.capacity()) +
		"\n" + std::to_string(pros.max_size()));
}

void GameStateTest::draw()
{
	/*sf::VertexArray quad(sf::Quads, 4);
	quad[0].position = sf::Vector2f(10, 10);
	quad[1].position = sf::Vector2f(110, 10);
	quad[2].position = sf::Vector2f(110, 110);
	quad[3].position = sf::Vector2f(10, 110);

	quad[0].texCoords = sf::Vector2f(0, 0);
	quad[1].texCoords = sf::Vector2f(25, 0);
	quad[2].texCoords = sf::Vector2f(25, 50);
	quad[3].texCoords = sf::Vector2f(0, 50);

	game->window.draw(quad);*/
player.draw(game->window);
	for (size_t i = 0; i < pros.size(); i++)
	{
		pros.at(i).draw(game->window);
	}
	
	text.draw(game->window);
}
