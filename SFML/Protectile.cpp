#include "Protectile.h"

void Projectile::draw(sf::RenderWindow & window)
{
	window.draw(pro);
}

void Projectile::update(float dt)
{
	//sf::Vector2f temp = Things::getMoveMent(start, dest, speed);
	pro.move(movement.x * dt, movement.y * dt);
}