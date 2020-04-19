#include "WindowManager.h"
#include "InputManager.h"
#include "Player.h"
#include "Level.h"
#include <iostream>
#include <vector>

int main()
{
    auto player = new Player("Bryce", 'B');

    std::vector<std::vector<char>> level1Vector = {
        {'-', '-', '#', '-', '-'},
        {'-', '-', '#', '-', '-'},
        {'-', '-', '#', '-', '-'},
        {'-', '-', '#', '-', '-'},
        {'-', '-', '-', '-', '-'},
        {'-', '-', '-', '-', '-'},
        {'-', '-', '#', '-', '-'},
        {'-', '-', '#', '-', '-'},
        {'-', '-', '#', '-', '-'},
        {'-', '-', '#', '-', '-'}
    };

    auto level1 = new Level(level1Vector);

    std::pair<int, int> firstPlayerPosition = { 1, 1 };
    level1->editLevel(player->getName(), player->getCharacter(), firstPlayerPosition);

    WindowManager().clearWindow();
    /*for (;;)
    {
        WindowManager().printLevel(level1);

        std::pair <int, int> movementCoordinates = player->move();

        level1->editLevel(player->getName(), player->getCharacter(), movementCoordinates);

        WindowManager().clearWindow();
    }*/

    std::vector<std::string> acceptableInput = {
        "FIREBOLT", "FIreball", "iCeball", "icEBolt"
    };
    std::string message = "Which of the following spells would you like to cast?";

    std::string answer = InputManager().dialogue(acceptableInput, message);

    std::cout << "The spell you wish to cast is: " << answer;

    return 0;
}
