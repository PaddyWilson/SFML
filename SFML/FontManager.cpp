#include "FontManager.h"

void FontManager::load(const std::string& name, const  std::string& file)
{
	sf::Font font;
	if (!font.loadFromFile(dir + file))
	{
		std::cout << "Can't load font '" << file << "'" << std::endl;
		//EXIT_FAILURE;
	}
	else
		std::cout << "Loaded font '" << file << "'" << std::endl;
	this->fonts[name] = font;
}

void FontManager::unload(std::string& name)
{
	std::cout << "Dose not delete yet" << std::endl;
	//delete this->fonts.;
}

sf::Font & FontManager::getRef(const std::string & name)
{
	return this->fonts.at(name);
}
