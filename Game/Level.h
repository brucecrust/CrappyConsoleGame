#pragma once
#include <vector>
#include <iostream>
#include <unordered_map>

class Level
{
public:
	Level(std::vector<std::vector<char>> levelVector);

	void printLevel();

	void editLevel(std::string entityName, char character, std::pair<int, int> coordinates);

	std::unordered_map <std::string, std::pair<int, int>> getEntityPositions() { return _entityPositions; }

	std::pair<int, int> getEntityPosition(std::string entityName);

	void setEntityPosition(std::string entityName, std::pair<int, int> coordinates);

private:
	std::vector<std::vector<char>> _levelVector;

	std::vector<std::vector<char>> _getLevel() { return _levelVector; }

	std::unordered_map<std::string, std::pair<int, int>> _entityPositions;
};