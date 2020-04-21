#pragma once
#include "Entity.h"
#include "ContextConstants.h"
#include "DialogueConstants.h"
#include "ResponseConstants.h"
#include "NonPlayer.h"
#include <string>
#include <unordered_map>
#include <vector>

class NonPlayer :
	public Entity
{
public:
	NonPlayer(std::string name, char entityCharacter, std::vector<int> contexts) : Entity(name, entityCharacter)
	{
		this->contexts = contexts;
	}

	std::pair<std::string, std::vector<std::string>> getDialogueChoice(int context);
	
private:
	std::vector<int> contexts;
};

