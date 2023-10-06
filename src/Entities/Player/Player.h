#pragma once

#include <raylib.h>

#include "../Entity.h"

#include "../../Components/TransformComponent/TransformComponent.h"
#include "../../Components/AnimationComponent/AnimationComponent.h"

#include "../../Log/Log.h"

#include "../../TextureManager/TextureManager.h"

class Player : public Entity
{
public:
    Player();
    Player(const Player &other);
    Player &operator=(const Player &other);
    ~Player();
    void init() override;
    void destroy() override;
    void handleInput() override;

private:
    int speed = 5;
    int rotationSpeed = 5;

    float health = 100;
    float maxHealth = 100;
};