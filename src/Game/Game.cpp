#include "Game.h"

Game::Game()
{
    this->init();
}

Game::~Game()
{
    this->destroy();
}

Game &Game::getInstance()
{
    static Game instance;
    return instance;
}

void Game::init()
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);
}

void Game::run()
{
    while (!WindowShouldClose())
    {
        this->update();
        this->draw();
    }
}

void Game::update()
{
    this->handleInput();
}

void Game::draw()
{
    BeginDrawing();

    ClearBackground(RAYWHITE);
    EndDrawing();
}

void Game::destroy()
{
    CloseWindow();}void Game::handleInput(){}