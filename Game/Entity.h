#pragma once

#include <string>

class Entity
{
public:
	Entity();
	Entity(std::string name, char character);

	std::string getName() { return name; }
	char getCharacter() { return character; }

private:
	std::string name;
	char character;
};

