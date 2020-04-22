#include "Level.h"

Level::Level(std::vector<std::vector<Entity*>> levelVector)
{
	this->levelVector = levelVector;
}

void Level::editLevel(Entity* entity, std::pair<int, int> coordinates)
{
	std::pair<int, int> updatedCoordinates = {
		entityPositions[entity].first + coordinates.first,
		entityPositions[entity].second + coordinates.second
	};

	if (!isOutOfBounds(updatedCoordinates) && !isCollidingWithEntity(wallTile, updatedCoordinates))
	{

		levelVector[entityPositions[entity].first][entityPositions[entity].second] = floorTile;

		levelVector[entityPositions[entity].first + coordinates.first]
			[entityPositions[entity].second + coordinates.second] = entity;

		setEntityPosition(entity, updatedCoordinates);
	}
}

void Level::setEntityPosition(Entity* entity, std::pair<int, int> coordinates)
{
	entityPositions[entity] = coordinates;
}

bool Level::isOutOfBounds(std::pair<int, int> coordinates)
{
	if (coordinates.first >= levelVector.size() || coordinates.first < 0)
	{
		return true;
	}
	else if (coordinates.second >= levelVector[0].size() || coordinates.second < 0)
	{
		return true;
	}
	else 
	{
		return false;
	}
}

bool Level::isCollidingWithEntity(Entity* entity, std::pair<int, int> coordinates)
{

	if (levelVector[coordinates.first][coordinates.second]->getName() == entity->getName())
	{
		return true;
	}
	else
	{
		return false;
	}
}

