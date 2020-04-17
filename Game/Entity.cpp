#include "Entity.h"

Entity::Entity()
{
	Entity::name = "Default";
	Entity::entityCharacter = 'D';
}

Entity::Entity(std::string name, char entityCharacter)
{
	Entity::name = name;
	Entity::entityCharacter = entityCharacter;
}