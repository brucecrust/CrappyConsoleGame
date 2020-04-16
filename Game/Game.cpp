#include "WindowManager.h"
#include "Entity.h"
#include "Level.h"
#include <iostream>
#include <vector>

int main()
{
    auto player = new Entity("Bryce", 'B');

    std::vector<std::vector<char>> level1Vector = {
        {'-', '-', '-', '-', '-'},
        {'-', '-', '-', '-', '-'},
        {'-', '-', '-', '-', '-'},
        {'-', '-', '-', '-', '-'},
        {'-', '-', '-', '-', '-'},
    };

    auto level1 = new Level(level1Vector);

    std::pair<int, int> firstPlayerCoordinates{ 1, 1 };
    std::pair<int, int> secondPlayerCoordinates{ 2, 2 };

    level1->editLevel(player->getName(), player->getCharacter(), firstPlayerCoordinates);

    WindowManager().printLevel(level1);

    std::cout << "\n";

    level1->editLevel(player->getName(), player->getCharacter(), secondPlayerCoordinates);

    WindowManager().printLevel(level1);

    return 0;
}

