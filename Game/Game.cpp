#include "olcConsoleGameEngine.h"
#include "WindowManager.h"
#include "InputManager.h"
#include "EntityManager.h"

#include "Player.h"
#include "Level.h"

#include <iostream>
#include <vector>

void oldGame()
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
}

class Engine : public olcConsoleGameEngine
{
public:
    Engine() {}

    Player* player = new Player("Bryce", 0x0042);

    std::vector<std::vector<Entity*>> level1Vector;
    Level* level1;

    virtual bool OnUserCreate()
    {
        for (int x = 0; x < 50; x++)
        {
            level1Vector.push_back(std::vector<Entity*>(50, floorTile));
        }
        
        level1 = new Level(level1Vector);

        std::pair<int, int> firstPlayerPosition = { 1, 1 };
        level1->editLevel(player, firstPlayerPosition);

        std::pair<int, int> jeffsPosition = { 4, 1 };
        level1->placeEntityAtPosition(jeff, jeffsPosition);

        Fill(0, 0, ScreenWidth(), ScreenHeight(), PIXEL_SOLID, FG_WHITE);

        return true;
    }

    virtual bool OnUserUpdate(float fElapsedTime)
    {
        std::pair <int, int> movementCoordinates;
        if (GetKey('W').bHeld)
        {
            movementCoordinates = { -1, 0 };
        }
        else if (GetKey('S').bHeld)
        {
            movementCoordinates = { 1, 0 };
        }
        else if (GetKey('A').bHeld)
        {
            movementCoordinates = { 0, -1 };
        }
        else if (GetKey('D').bHeld)
        {
            movementCoordinates = { 0, 1 };
        }
        else
        {
            movementCoordinates = { 0, 0 };
        }

        if (movementCoordinates != std::pair<int, int> { 0, 0 })
        {
            if (movementCoordinates.first > 0)
            {
                movementCoordinates.first = 2.0f * fElapsedTime;
            }
            
            if (movementCoordinates.second > 0)
            {
                movementCoordinates.second = 2.0f * fElapsedTime;
            }
            level1->editLevel(player, movementCoordinates);
        }

        for (int x = 0; x < level1->getLevel()[0].size(); x++)
        {
            for (int y = 0; y < level1->getLevel().size(); y++)
            {
                Draw(x, y, level1->getLevel()[y][x]->getCharacter());
            }
        }

        return true;
    }
};

int main()
{
    Engine engine;
    engine.ConstructConsole(50, 50, 12, 14);
    engine.Start();

    return 0;
}
