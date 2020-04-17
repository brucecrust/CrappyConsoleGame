#include "Player.h"

std::pair<int, int> Player::move()
{
	std::string inp;
	std::cout << "Which way would you like to move?" << "\n";
	std::cin >> inp;

	std::pair<int, int> movementCoordinates; 

	if (inp == "w")
	{
		movementCoordinates = { -1, 0 };
	}
	else if (inp == "s")
	{
		movementCoordinates = { 1, 0 };
	}
	else if (inp == "a")
	{
		movementCoordinates = { 0, -1 };
	}
	else if (inp == "d")
	{
		movementCoordinates = { 0, 1 };
	}
	else
	{
		movementCoordinates = { 0, 0 };
	}

	return movementCoordinates;
}