#pragma once
#include <SFML\Graphics.hpp>
#include <vector>

class Map : public sf::Drawable, public sf::Transformable
{
public:
	Map(int x, int y);
	~Map();

	void load();

	void update(float dt);
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	std::vector<sf::RectangleShape> recs;
	sf::VertexArray vertices;
};
