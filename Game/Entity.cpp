#include "Entity.h"

Entity::Entity()
{
	this->name = "Default";
	this->character = 0x0044;
}

Entity::Entity(std::string name, short character)
{
	this->name = name;
	this->character = character;
}