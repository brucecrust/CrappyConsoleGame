#pragma once
#include "Entity.h"
#include <iostream>

class Player :
	public Entity
{
public:
	using Entity::Entity;

	std::pair<int, int> move();
};

