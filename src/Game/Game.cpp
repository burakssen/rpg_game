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
    this->width = 800;
    this->height = 450;

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(width, height, "raylib [core] example - basic window");

    SetTargetFPS(60);

    Player *player = new Player();

    this->entities.emplace_back(player);
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
    int current_width = GetScreenWidth();
    int current_height = GetScreenHeight();

    this->handleInput();
    for (auto &entity : this->entities)
    {
        if (current_width != this->width || current_height != this->height)
        {
            TransformComponent *transform = entity->getComponent<TransformComponent>();

            if (current_width < this->width && current_height < this->height)
                transform->defaultTransform();
            else
            {
                transform->setScale(Vector2{transform->getScale().x * (float)current_width / this->width, transform->getScale().y * (float)current_height / this->height});
                transform->setPosition(Vector2{(float)current_width * transform->getPosition().x / this->width, (float)current_height * transform->getPosition().y / this->height});
            }
        }

        entity->update();
    }
    this->width = current_width;
    this->height = current_height;
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
    for (auto &entity : this->entities)
    {
        entity->destroy();
        delete entity;
    }

    this->entities.clear();
    CloseWindow();
}

void Game::handleInput()
{
}