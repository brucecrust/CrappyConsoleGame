#include "Level.h"

Level::Level(std::vector<std::vector<char>> levelVector)
{
	_levelVector = levelVector;
}

void Level::editLevel(std::string entityName, char character, std::pair<int, int> coordinates)
{
	_levelVector[_entityPositions[entityName].first][_entityPositions[entityName].second] = '-';

	std::pair<int, int> updatedCoordinates = {
	_entityPositions[entityName].first + coordinates.first,
	_entityPositions[entityName].second + coordinates.second
	};

	_levelVector[_entityPositions[entityName].first+coordinates.first]
		[_entityPositions[entityName].second+coordinates.second] = character;

	setEntityPosition(entityName, updatedCoordinates);
}

std::pair<int, int> Level::getEntityPosition(std::string entityName)
{
	return _entityPositions[entityName];
}

void Level::setEntityPosition(std::string entityName, std::pair<int, int> coordinates)
{
	_entityPositions[entityName] = coordinates;
}