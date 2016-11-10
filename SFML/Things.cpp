#include "Things.h"

int Things::windowWidth = 800;
int Things::windowHeight = 600;
sf::Time Things::frametime = sf::seconds(0.1f);

void Things::updateDT(sf::Time dt)
{
	frametime = dt;
}

sf::Time Things::getDT()
{
	return frametime;
}

float Things::power(float num, float power)
{
	return std::pow(num, power);
}

float Things::squareRoot(float num)
{
	return std::sqrt(num);
}

sf::Vector2f Things::getMoveMent(float xStart, float yStart, float xDest, float yDest, float speed)
{
	/*float t1 = std::pow((xDest - xStart), 2);
	float t2 = std::pow((yDest - yStart), 2);
	float dist = std::sqrt(t1 + t2);
	float xPos = (xDest - xStart) / dist * speed;
	float yPos = (yDest - yStart) / dist * speed;
	return sf::Vector2f(xPos, yPos);*/
	float dist = std::sqrt(power((xDest - xStart), 2) + power((yDest - yStart), 2));
	return sf::Vector2f((xDest - xStart) / dist * speed, (yDest - yStart) / dist * speed);
}

sf::Vector2f Things::getMoveMent(sf::Vector2f start, sf::Vector2f Dest, float speed)
{
	float dist = std::sqrt(power((Dest.x - start.x), 2) + power((Dest.y - start.y), 2));
	return sf::Vector2f((Dest.x - start.x) / dist * speed, (Dest.y - start.y) / dist * speed);
}
sf::Vector2f Things::getMoveMent(sf::Vector2f start, sf::Vector2f Dest, sf::Vector2f speed)
{
	float dist = std::sqrt(power((Dest.x - start.x), 2) + power((Dest.y - start.y), 2));
	return sf::Vector2f((Dest.x - start.x) / dist * speed.x, (Dest.y - start.y) / dist * speed.y);
}
