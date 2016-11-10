#include "Map.h"

Map::Map(int width, int height)// :vertices(sf::Quads)
{
	vertices.setPrimitiveType(sf::Quads);
	vertices.resize(width * height * 4);

	int size = 21 -1;
	// resize the vertex array to fit the level size
	vertices.setPrimitiveType(sf::Quads);
	vertices.resize(width * height * 4);
	int a = -1;
	int b = -1;
	// populate the vertex array, with one quad per tile
	for (int i = 0; i < width; ++i)
	{
		a++;
		b = 0;
		for (int j = 0; j < height; ++j)
		{
			// get the current tile number
			int tileNumber = i + j * width;

			// find its position in the tileset texture
			int tu = tileNumber % (size / size);
			int tv = tileNumber / (size / size);

			// get a pointer to the current tile's quad
			sf::Vertex* quad = &vertices[(i + j * width) * 4];

			// define its 4 corners
			quad[0].position = sf::Vector2f(i * size + a, j * size +b);
			quad[1].position = sf::Vector2f((i + 1) * size + a, j * size + b);
			quad[2].position = sf::Vector2f((i + 1) * size + a, (j + 1) * size + b);
			quad[3].position = sf::Vector2f(i * size + a, (j + 1) * size + b);

			// define its 4 texture coordinates
			quad[0].color = sf::Color::Color(232, 44, 12, 0);
			quad[1].color = sf::Color::Color(232, 44, 12, 0);
			quad[2].color = sf::Color::Color(232, 44, 12, 100);
			quad[3].color = sf::Color::Color(232, 44, 12, 100);//br
			b++;
		}
	}
}

Map::~Map()
{
}

void Map::load()
{
}

void Map::update(float dt)
{
}

void Map::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	states.transform *= getTransform();

	// our particles don't use a texture
	states.texture = NULL;

	// draw the vertex array
	target.draw(vertices, states);
}

