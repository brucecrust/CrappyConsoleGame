#pragma once
#include "Entity.h"
#include <string>
#include <vector>

class NonPlayer :
	public Entity
{
public:
	using Entity::Entity;

	std::string getDefaultMessage() { return defaultMessage; }
	std::vector<std::string> getAcceptableInput() { return acceptableInput; }

private:
	std::string defaultMessage = "Hey how's it going?";
	std::vector<std::string> acceptableInput = {
		"Oh, just fine.",
		"Not too bad.",
		"Who wants to know?"
	};
};

