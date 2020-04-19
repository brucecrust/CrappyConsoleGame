#include "InputManager.h"

std::string InputManager::dialogue(std::vector<std::string> acceptableInput, std::string message)
{
	std::cout << message << "\n";
	for (int i = 0; i < acceptableInput.size(); i++)
	{
		std::cout << acceptableInput[i] << "\n";
	}

	for (;;)
	{
		std::string userInput;
		std::cin >> userInput;

		std::vector<std::string> userInputVector;

		for (int i = 0; i < acceptableInput.size(); i++)
		{
			if (acceptableInput[i].find(userInput) == 0)
			{
				userInputVector.push_back(acceptableInput[i]);
			}
		}

		if (userInputVector.size() == 0)
		{
			std::cout << "Invalid choice" << "\n";
		}
		else if (userInputVector.size() == 1)
		{
			return userInputVector[0];
		}
		else
		{
			std::cout << "Which of the following did you mean?" << "\n";

			for (int i = 0; i < userInputVector.size(); i++)
			{
				std::cout << userInputVector[i] << "\n";
			}
		}
	}
}