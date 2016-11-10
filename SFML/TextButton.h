#pragma once
#include "Game.h"
#include "IDraw.h"

#include "Text.h"


class TextButton : public IDraw
{
public:
	TextButton() {}
	TextButton(std::string text, sf::Font& font, int size, float x, float y, sf::Color c1, sf::Color c2);
	//TextButton(std::string text, sf::Font& font, int size, sf::Vector2f pos, sf::Color c1, sf::Color c2);
	~TextButton();

	void update(float dt, sf::Vector2f mousePoint);
	void draw(sf::RenderWindow &window);

	void SelectColor(int i);
	bool PointInBounds(sf::Vector2f point);
	bool IsSelected();

	Text text;
private:
	bool selected = false;
	sf::Color c1, c2;
};

TextButton::TextButton(std::string text, sf::Font& font, int size, float x, float y, sf::Color c1, sf::Color c2)
{
	this->text = Text(text, font);
	this->text.setSize(size);
	this->text.text.setPosition(x, y);
	this->text.setColor(c1);
	this->c1 = c1;
	this->c2 = c2;
}

TextButton::~TextButton()
{
}

void TextButton::update(float dt, sf::Vector2f mousePoint)
{
	if (PointInBounds(mousePoint))
	{
		SelectColor(1);
		selected = true;
	}
	else
	{
		SelectColor(0);
		selected = false;
	}
}

void TextButton::draw(sf::RenderWindow & window)
{
	text.draw(window);
}

void TextButton::SelectColor(int i)
{
	if (i >= 1)
		text.setColor(c2);
	else
		text.setColor(c1);
}

bool TextButton::PointInBounds(sf::Vector2f point)
{
	auto a = text.text.getGlobalBounds();
	//std::cout << a.left << " " << a.top << " " << a.width << " " << a.height << " " << std::endl;
	//make sure to add to the origin point
	return (point.x >= a.left) && (point.x <= a.width + a.left) && (point.y >= a.top) && (point.y <= a.height + a.top);
}

bool TextButton::IsSelected()
{
	return selected;
}


