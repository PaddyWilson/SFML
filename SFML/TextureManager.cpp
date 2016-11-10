#include "TextureManager.h"

void TextureManager::load(const std::string & name, const std::string & file)
{
	sf::Texture tex;
	if (!tex.loadFromFile(file))
	{
		std::cout << "Can't load texture '" << file << "'" << std::endl;
	}
	else
		std::cout << "Loaded texture '" << file << "'" << std::endl;
	this->textures[name] = tex;
}

sf::Texture & TextureManager::getRef(const std::string & texture)
{
	return this->textures.at(texture);
}
