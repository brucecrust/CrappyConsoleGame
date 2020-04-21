#include "NonPlayer.h"

std::pair<std::string, std::vector<std::string>> NonPlayer::getDialogueChoice(int context)
{
	std::string message;
	std::vector<std::string> acceptableInput;

	std::pair<std::string, std::vector<std::string>> dialogueChoices;

	if (!std::count(contexts.begin(), contexts.end(), ON_COLLISION_CONTEXT))
	{
		dialogueChoices;
	} 

	switch (context)
	{
	case ON_COLLISION_CONTEXT:
		acceptableInput.push_back(A_ON_COLLISION);
		acceptableInput.push_back(B_ON_COLLISION);
		dialogueChoices = { ON_COLLISION_WITH_PLAYER, acceptableInput };
		break;

	default:
		return dialogueChoices;
	}

	return dialogueChoices;
}