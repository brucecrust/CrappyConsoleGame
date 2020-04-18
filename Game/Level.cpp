#include "Level.h"

Level::Level(std::vector<std::vector<char>> levelVector)
{
	this->levelVector = levelVector;
}

void Level::editLevel(std::string entityName, char character, std::pair<int, int> coordinates)
{
	std::pair<int, int> updatedCoordinates = {
		entityPositions[entityName].first + coordinates.first,
		entityPositions[entityName].second + coordinates.second
	};

	if (!isOutOfBounds(updatedCoordinates) && !isCollidingWithCharacter(updatedCoordinates, '#'))
	{
		levelVector[entityPositions[entityName].first][entityPositions[entityName].second] = '-';

		levelVector[entityPositions[entityName].first + coordinates.first]
			[entityPositions[entityName].second + coordinates.second] = character;

		setEntityPosition(entityName, updatedCoordinates);
	}
}

std::pair<int, int> Level::getEntityPosition(std::string entityName)
{
	return entityPositions[entityName];
}

void Level::setEntityPosition(std::string entityName, std::pair<int, int> coordinates)
{
	entityPositions[entityName] = coordinates;
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

bool Level::isCollidingWithCharacter(std::pair<int, int> coordinates, char entityCharacter)
{
	if (levelVector[coordinates.first][coordinates.second] == entityCharacter)
	{
		return true;
	}
	else
	{
		return false;
	}
}