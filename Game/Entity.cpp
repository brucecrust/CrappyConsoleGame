#include "Entity.h"

Entity::Entity()
{
	this->name = "Default";
	this->character = 'D';
}

Entity::Entity(std::string name, char entityCharacter)
{
	this->name = name;
	this->character = entityCharacter;
}