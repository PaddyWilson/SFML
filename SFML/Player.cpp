#include "Player.h"

Player::Player(float x, float y, float xSize, float ySize)
{
	rectangle = sf::RectangleShape(sf::Vector2f(xSize, ySize));
	//rectangle.setOrigin(sf::Vector2f(xSize / 2, ySize / 2));
	rectangle.setPosition(x, y);
}

Player::~Player()
{

}

void Player::draw(sf::RenderWindow &window)
{
	window.draw(rectangle);
}

void Player::update(float frameTime)
{
	//sf::Vector2u a = sf::Window::getSize().x;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		rectangle.move(-speed * frameTime, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		rectangle.move(0, -speed * frameTime);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		rectangle.move(0, speed * frameTime);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		rectangle.move(speed * frameTime, 0);
	}
}

void Player::collision()
{

}

 void Player::shoot(float dt)
{
	this->rectangle.getPosition();
	sf::Mouse::getPosition();



}
