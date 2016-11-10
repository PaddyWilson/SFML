#pragma once
#include <SFML\Graphics.hpp>
#include <math.h>

class Things
{
public:
	//Things();
	//~Things();

	static int windowWidth;// = 800;
	static int windowHeight;// = 600;//window size

	static sf::Time frametime;// = 0;//frametime
	static void updateDT(sf::Time dt);
	static sf::Time getDT();

	static float power(float num, float power);
	static float squareRoot(float num);

	static sf::Vector2f getMoveMent(float xStart, float yStart, float xDest, float yDest, float speed);
	static sf::Vector2f getMoveMent(sf::Vector2f start, sf::Vector2f Dest, float speed);
	static sf::Vector2f getMoveMent(sf::Vector2f start, sf::Vector2f Dest, sf::Vector2f speed);

private:

};
