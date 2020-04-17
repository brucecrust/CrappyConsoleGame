#pragma once

#include <string>

class Entity
{
public:
	Entity();
	Entity(std::string name, char entityCharacter);

	std::string getName() { return name; }
	char getCharacter() { return entityCharacter; }
	int getHealth() { return health; }

	void modifyHealth(int modifier) { health += modifier; }

private:
	std::string name;
	char entityCharacter;

	int health;

	bool isAlive;
};

