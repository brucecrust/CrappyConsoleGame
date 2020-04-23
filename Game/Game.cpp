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

    virtual bool OnUserCreate()
    {
        Fill(0, 0, ScreenWidth(), ScreenHeight(), PIXEL_SOLID, FG_WHITE);

        return true;
    }

    virtual bool OnUserUpdate(float fElapsedTime)
    {
        int width = 0;
        int height = 0;

        if (width < ScreenWidth() || height < ScreenHeight())
        {
            for (int x = 0; x < ScreenWidth(); x++)
            {
                for (int y = 0; y < ScreenHeight(); y++)
                {
                    Draw(x, y, PIXEL_SOLID, FG_BLACK);
                }
            }

            width++;
            height++;
        }

        return true;
    }
};

int main()
{
    Engine engine;
    engine.ConstructConsole(100, 80, 12, 12);
    engine.Start();

    return 0;
}
