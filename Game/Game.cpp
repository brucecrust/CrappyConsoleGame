#include "WindowManager.h"
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
    for (;;)
    {
        WindowManager().printLevel(level1);

        std::pair <int, int> movementCoordinates = player->move();

        level1->editLevel(player->getName(), player->getCharacter(), movementCoordinates);

        WindowManager().clearWindow();
    }

    return 0;
}
