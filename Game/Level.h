#pragma once
#include <vector>
#include <iostream>
#include <unordered_map>

class Level
{
public:
	Level(std::vector<std::vector<char>> levelVector);

	void editLevel(std::string entityName, char character, std::pair<int, int> coordinates);

	std::unordered_map <std::string, std::pair<int, int>> getEntityPositions() { return entityPositions; }

	std::pair<int, int> getEntityPosition(std::string entityName);

	void setEntityPosition(std::string entityName, std::pair<int, int> coordinates);

	std::vector<std::vector<char>> getLevel() { return levelVector; }

private:
	std::vector<std::vector<char>> levelVector;

	std::unordered_map<std::string, std::pair<int, int>> entityPositions;
};