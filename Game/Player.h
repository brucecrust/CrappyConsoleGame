#pragma once
#include "Entity.h"
#include <iostream>
#include <Windows.h>

class Player :
	public Entity
{
public:
	using Entity::Entity;

	std::pair<int, int> move();

	int getHealth() { return health; }

	void modifyHealth(int modifier) { health += modifier; }

private:
	int health;

	bool isAlive;
};

