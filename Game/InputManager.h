#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

class InputManager
{
public:
	static std::string dialogue(std::vector<std::string> acceptableInput, std::string message);
};

