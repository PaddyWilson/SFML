#pragma once
#include "IDraw.h"

class Player : public IDraw
{
public:
	Player(float x, float y, float xSize, float ySize);
	~Player();

	void draw(sf::RenderWindow &window);
	void update(float dt);
	void collision();
	void shoot(float dt);
	sf::RectangleShape rectangle;
private:
	float speed = 200;
};
