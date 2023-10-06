#pragma once

#include <raylib.h>
#include <vector>
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
};