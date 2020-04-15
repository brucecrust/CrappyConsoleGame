#pragma once

#include <string>

class Entity
{
public:
	Entity(std::string name, char eCharacter);

	std::string getName() { return _name; }
	char getCharacter() { return _eCharacter; }
	int getHealth() { return _health; }

	void setHealth(int modifier) { _health += modifier; }

private:
	std::string _name;
	char _eCharacter;

	int _health;

	bool _isAlive;
};

