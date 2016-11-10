#pragma once
#include <SFML/Graphics.hpp>

class IDraw
{
public:
	virtual void draw(sf::RenderWindow &window) = 0;
	virtual void update(float dt) {}
	//virtual void update(float dt) = 0;
private:

};