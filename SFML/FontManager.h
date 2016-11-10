#pragma once
#include <map>
#include <iostream>

#include <SFML/Graphics.hpp>

class FontManager
{
public:
	void load(const std::string& name, const  std::string& file);
	void unload(std::string& name);
	sf::Font& getRef(const std::string& name);

private:
	std::map<std::string, sf::Font> fonts;
	const std::string dir = "./resources/fonts/";
};
