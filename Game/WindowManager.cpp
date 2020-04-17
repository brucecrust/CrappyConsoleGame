#include "WindowManager.h"

void WindowManager::printLevel(Level* level)
{
	for (int x = 0; x < level->getLevel().size(); x++)
	{
		for (int y = 0; y < level->getLevel()[0].size(); y++)
		{
			std::cout << " " << level->getLevel()[x][y];
		}
		std::cout << "\n";
	}
}

void WindowManager::clearWindow()
{
	std::cout << std::string(25, '\n');
}