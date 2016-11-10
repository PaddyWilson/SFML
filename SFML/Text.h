#pragma once
#include <SFML\Graphics.hpp>

#include "IDraw.h"

class Text :public IDraw
{
public:
	sf::Text text;
	
	Text() {}
	Text(std::string text, sf::Font& font);
	~Text();

	void draw(sf::RenderWindow &window);
	//void update(float dt);

	void setSize(int size);
	void setColor(sf::Color color);
	void setFont(sf::Font& font);

	void setText(std::string text);

private:
	
};
