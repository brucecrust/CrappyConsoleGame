#include "Player.h"

std::pair<int, int> Player::move()
{
	std::pair<int, int> movementCoordinates; 

	if (GetKeyState(0x0057) & 0x8000)
	{
		movementCoordinates = { -1, 0 };
	}
	else if (GetKeyState(0x0053) & 0x8000)
	{
		movementCoordinates = { 1, 0 };
	}
	else if (GetKeyState('A') & 0x8000)
	{
		movementCoordinates = { 0, -1 };
	}
	else if (GetKeyState('D') & 0x8000)
	{
		movementCoordinates = { 0, 1 };
	}
	else
	{
		movementCoordinates = { 0, 0 };
	}

	return movementCoordinates;
}