#include "Game.h"

Game::Game()
{
	sf::ContextSettings settings;
	//settings.attributeFlags = settings.Core;
	//settings.majorVersion = 4;
	//settings.minorVersion = 1;
	//settings.antialiasingLevel = 0;

	window.create(sf::VideoMode(Things::windowWidth, Things::windowHeight), "Game Title", sf::Style::Default, settings);
	window.setFramerateLimit(60);
	//window.setVerticalSyncEnabled(true);
	fontManager.load("arial", "Ubuntu-R.ttf");
	textureManager.load("potato", "potato.png");
	textureManager.load("grid1", "grid1.png");
}

Game::~Game()
{

}

void Game::draw()
{
}

void Game::update(float dt)
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			window.close();

		if (event.type == sf::Event::Resized)
		{
			Things::windowHeight = window.getSize().x;
			Things::windowWidth = window.getSize().y;
			std::cout << "Window resized " << window.getSize().x << " " << window.getSize().y << std::endl;
			
			sf::View g = window.getDefaultView();
			g.setSize((sf::Vector2f)window.getSize());
			g.setCenter((float)window.getSize().x / 2, (float)window.getSize().y / 2);
			window.setView(g);
		}

		/*if (event.key.code == sf::Keyboard::F1)
		{
			gameState.push(new GameStateTest(this));
		}*/
	}// end window events


}

void Game::run()
{
	sf::Clock frameTime;
	while (window.isOpen())
	{
		sf::Time t = frameTime.getElapsedTime();
		frameTime.restart();
		float time = t.asSeconds();//frameTime.restart().asSeconds();
		Things::updateDT(t);
		update(time);

		if (this->gameState.empty()) 
		{
			window.clear();
			window.display();
		}
		gameState.top()->update(time);

		window.clear();
		gameState.top()->draw();
		//draw();
		window.display();
	}
}
