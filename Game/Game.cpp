#include "WindowManager.h"
#include "InputManager.h"
#include "EntityManager.h"

#include "Player.h"
#include "Level.h"

#include <iostream>
#include <vector>

int main()
{
    auto player = new Player("Bryce", 'B');

    std::vector<std::vector<Entity*>> level1Vector = {
        {floorTile, floorTile, wallTile, floorTile, floorTile},
        {floorTile, floorTile, wallTile, floorTile, floorTile},
        {floorTile, floorTile, wallTile, floorTile, floorTile},
        {floorTile, floorTile, wallTile, floorTile, floorTile},
        {floorTile, floorTile, floorTile, floorTile, floorTile},
        {floorTile, floorTile, floorTile, floorTile, floorTile},
        {floorTile, floorTile, wallTile, floorTile, floorTile},
        {floorTile, floorTile, wallTile, floorTile, floorTile},
        {floorTile, floorTile, wallTile, floorTile, floorTile},
        {floorTile, floorTile, wallTile, floorTile, floorTile}
    };

    auto level1 = new Level(level1Vector);

    std::pair<int, int> firstPlayerPosition = { 1, 1 };
    level1->editLevel(player, firstPlayerPosition);

    std::pair<int, int> jeffsPosition = { 4, 1 };
    level1->placeEntityAtPosition(jeff, jeffsPosition);

    bool playerMoved = false;
    int c = 0;

    WindowManager().clearWindow();
    WindowManager().printLevel(level1);
    for (;;)
    {
        std::pair <int, int> movementCoordinates = player->move();

        if (movementCoordinates != std::pair<int, int> { 0, 0 })
        {
            c++;
            std::cout << c << "\n";

            level1->editLevel(player, movementCoordinates);
            WindowManager().clearWindow();
            WindowManager().printLevel(level1);
        }
    }

    return 0;
}
