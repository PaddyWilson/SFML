#pragma once
#include "Manager.h"

template <typename T>
void Manager<T>::load(const std::string & name, const std::string & file)
{
	T item;
	if (!item.loadFromFile(file))
	{
		std::cout << "Can't load '" << file << "'" << std::endl;
	}
	else
		std::cout << "Loaded '" << file << "'" << std::endl;
	this->map[name] = item;
}

template <typename T>
T& Manager<T>::getRef(const std::string & texture) const
{
	return map[texture];
}