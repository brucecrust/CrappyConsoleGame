#pragma once
#include "EntityManager.h"
#include "InputManager.h"

#include "Entity.h"

#include <vector>
#include <iostream>
#include <unordered_map>

class Level
{
public:
	Level(std::vector<std::vector<Entity*>> modLevelVector);

	void editLevel(Entity* entity, std::pair<int, int> coordinates);

	std::pair<int, int> getEntityPosition(std::string entityName);

	void setEntityPosition(Entity* entity, std::pair<int, int> coordinates);

	void placeEntityAtPosition(Entity* entity, std::pair<int, int> coordinates);

	std::vector<std::vector<Entity*>> getLevel() { return levelVector; }

	bool isOutOfBounds(std::pair<int, int> coordinates);
	bool isCollidingWithEntity(Entity* entity, std::pair<int, int> coordinates);

private:
	std::vector<std::vector<Entity*>> levelVector;

	std::unordered_map<Entity*, std::pair<int, int>> entityPositions;
};
