#include <iostream>

#include "Log/Log.h"
#include "Game/Game.h"

int main()
{
    Log::info("Starting game...");
    Log::stopRaylibLogging();
    Game::getInstance().run();
    return EXIT_SUCCESS;
}