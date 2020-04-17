#include "Level.h"

Level::Level(std::vector<std::vector<char>> levelVector)
{
	Level::levelVector = levelVector;
}

void Level::editLevel(std::string entityName, char character, std::pair<int, int> coordinates)
{
	levelVector[entityPositions[entityName].first][entityPositions[entityName].second] = '-';

	std::pair<int, int> updatedCoordinates = {
	entityPositions[entityName].first + coordinates.first,
	entityPositions[entityName].second + coordinates.second
	};

	levelVector[entityPositions[entityName].first+coordinates.first]
		[entityPositions[entityName].second+coordinates.second] = character;

	setEntityPosition(entityName, updatedCoordinates);
}

std::pair<int, int> Level::getEntityPosition(std::string entityName)
{
	return entityPositions[entityName];
}

void Level::setEntityPosition(std::string entityName, std::pair<int, int> coordinates)
{
	entityPositions[entityName] = coordinates;
}