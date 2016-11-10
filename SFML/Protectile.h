#pragma once
#include <SFML\Graphics.hpp>

#include "IDraw.h"

#include "Things.h"

class Projectile : public IDraw
{
public:
	Projectile(float x, float y, float size, sf::Color color, float xP, float yP)
	{
		pro = sf::CircleShape(size);
		pro.setPosition(x, y);
		pro.setFillColor(color);
		start.x = x;
		start.y = y;
		dest.x = xP;
		dest.y = yP;
		movement = Things::getMoveMent(start, dest, speed);
	}
	Projectile(float x, float y,  float xP, float yP, float xS, float yS, float size, sf::Color color)
	{
		pro = sf::CircleShape(size);
		pro.setPosition(x, y);
		pro.setFillColor(color);
		start.x = x;
		start.y = y;
		dest.x = xP;
		dest.y = yP;
		speed.x = xS;
		speed.y = yS;
		movement = Things::getMoveMent(start, dest, speed);
	}
	Projectile(sf::Vector2f start, sf::Vector2f dest, sf::Vector2f speed, float size, sf::Color color):start(start), dest(dest), speed(speed)
	{
		pro = sf::CircleShape(size);
		pro.setPosition(start);
		pro.setFillColor(color);
		movement = Things::getMoveMent(start, dest, speed);
	}
	~Projectile() {}
	
	void draw(sf::RenderWindow &window);
	void update(float dt);

	float getTime() { return aliveTime.getElapsedTime().asSeconds(); }
sf::CircleShape pro;
	//static Projectile make(float x, float y, float size, sf::Color color, float xV, float yV);
private:
	
	sf::Vector2f start;
	sf::Vector2f dest;
	sf::Vector2f movement;
	sf::Vector2f speed;
	sf::Clock aliveTime;
};
