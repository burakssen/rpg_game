#include "Player.h"

Player::Player()
{
    this->init();
}

Player::Player(const Player &other)
{
    this->health = other.health;
    this->maxHealth = other.maxHealth;
    this->rotationSpeed = other.rotationSpeed;
    this->speed = other.speed;

    this->init();
}

Player &Player::operator=(const Player &other)
{
    this->health = other.health;
    this->maxHealth = other.maxHealth;
    this->rotationSpeed = other.rotationSpeed;
    this->speed = other.speed;

    this->init();
    return *this;
}

Player::~Player()
{
    this->destroy();
}

void Player::init()
{
    TransformComponent *transform = this->addComponent<TransformComponent>();
    AnimationComponent *animation = this->addComponent<AnimationComponent>();

    transform->setPosition({(float)GetScreenWidth() / 2, (float)GetScreenHeight() / 2});
    transform->setRotation(0);
    transform->setScale({1, 1});

    Animation run_animation{
        .name = "run",
        .number_of_frames = 10,
        .animation_speed = 2,
        .frame_width = 120,
        .frame_height = 80,
        .texture = TEXTURE_MANAGER.getTexture("player_run")};

    Animation roll_animation{
        .name = "roll",
        .number_of_frames = 12,
        .animation_speed = 0.5f,
        .frame_width = 120,
        .frame_height = 80,
        .texture = TEXTURE_MANAGER.getTexture("player_roll"),
        .animation_type = AnimationType::ONCE
    };

    AnimationType animation_type = AnimationType::INFINITE;

    Animation idle_animation{
        .name = "idle",
        .number_of_frames = 10,
        .animation_speed = 2,
        .frame_width = 120,
        .frame_height = 80,
        .texture = TEXTURE_MANAGER.getTexture("player_idle")};

    animation->addAnimation("run", run_animation);
    animation->addAnimation("roll", roll_animation);
    animation->addAnimation("idle", idle_animation);
    animation->playAnimation("idle");
    animation->setPlaying(true);
}

void Player::destroy()
{
    this->removeComponent<TransformComponent>();
    this->removeComponent<SpriteComponent>();
}

void Player::handleInput()
{
    AnimationComponent *animation = this->getComponent<AnimationComponent>();
    TransformComponent *transform = this->getComponent<TransformComponent>();

    if (animation)
    {
        if (IsKeyPressed(KEY_SPACE))
        {
            animation->playAnimation("roll");
        }

        if (animation->isOnceRunning())
        {
            return;
        }

        if (IsKeyDown(KEY_RIGHT))
        {
            transform->setScale({1, 1});
            animation->playAnimation("run");
        }

        if (IsKeyDown(KEY_LEFT))
        {
            transform->setScale({-1, 1});
            animation->playAnimation("run");
        }

        if (IsKeyUp(KEY_LEFT) && IsKeyUp(KEY_RIGHT) && IsKeyUp(KEY_SPACE))
        {
            animation->playAnimation("idle");
        }
    }
}
