#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <map>

#include <iostream>

class TextureManager
{
private:
	

public:
	std::map<std::string, sf::Texture> textures;
	
	TextureManager() {	}
	void load(const std::string& name, const std::string &file);
	sf::Texture& getRef(const std::string& texture);
};