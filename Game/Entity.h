#pragma once

#include <string>

class Entity
{
public:
	Entity();
	Entity(std::string name, short character);

	std::string getName() { return name; }
	short getCharacter() { return character; }

private:
	std::string name;
	short character;
};

