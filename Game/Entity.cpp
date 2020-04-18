#include "Entity.h"

Entity::Entity()
{
	this->name = "Default";
	this->entityCharacter = 'D';
}

Entity::Entity(std::string name, char entityCharacter)
{
	this->name = name;
	this->entityCharacter = entityCharacter;
}