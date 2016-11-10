#pragma once
#include <SFML\Graphics.hpp>
#include <string>
#include <map>
#include <iostream>

template <typename T>
class Manager
{
private:
	std::map<std::string, T> map;

public:
	Manager() {	}
	void load(const std::string& name, const std::string &file);
	T& getRef(const std::string& texture) const;
};
