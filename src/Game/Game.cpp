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
    for (auto &entity : this->entities)
    {
        entity->update();
    }
}

void Game::draw()
{
    BeginDrawing();

    ClearBackground(RAYWHITE);

    for (auto &entity : this->entities)
    {
        entity->draw();
    }

    EndDrawing();
}

void Game::destroy()
{
    for (auto &entity : this->entities)    {        entity->destroy();        delete entity;    }    this->entities.clear();    CloseWindow();}void Game::handleInput(){}