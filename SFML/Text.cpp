#include "Text.h"

Text::Text(std::string text, sf::Font& font)
{
	this->text.setFont(font);
	this->text.setString(text);
}

Text::~Text()
{
}

void Text::draw(sf::RenderWindow & window)
{
	window.draw(this->text);
}

void Text::setSize(int size)
{
	this->text.setCharacterSize(size);
}

void Text::setColor(sf::Color color)
{
	this->text.setFillColor(color);
}

void Text::setFont(sf::Font& font)
{
	this->text.setFont(font);
}

void Text::setText(std::string text)
{
	this->text.setString(text);
}
