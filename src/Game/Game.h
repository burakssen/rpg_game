#pragma once

#include <raylib.h>
#include <vector>

#include "../Entities/Entity.h"
#include "../Entities/Player/Player.h"

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

    std::vector<Entity *> entities;
};