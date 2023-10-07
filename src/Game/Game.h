#pragma once

#include <raylib.h>
#include <vector>

#include "../Entities/Entity.h"
#include "../Entities/Player/Player.h"
#include "../Entities/Tile/Tile.h"

class Game
{
private:
    Game();
    ~Game();

public:
    static Game &getInstance();
    void init();
    void run();
    void update();
    void draw();
    void destroy();
    void handleInput();

private:
    std::vector<Entity *> entities;
    int width = 800;
    int height = 450;
};