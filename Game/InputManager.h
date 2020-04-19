#pragma once
#include <string>
#include <vector>
#include <iostream>

class InputManager
{
public:
	static std::string dialogue(std::vector<std::string> acceptableInput, std::string message);
};

