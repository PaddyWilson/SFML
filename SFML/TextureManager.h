#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <map>

#include <iostream>

class TextureManager
{
public:
	void load(const std::string& name, const std::string &file);
	sf::Texture& getRef(const std::string& texture);

private:
	std::map<std::string, sf::Texture> textures;
	const std::string dir = "./resources/texture/";
};