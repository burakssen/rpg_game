#pragma once

#include <raylib.h>
#include "../Component.h"
#include "../TransformComponent/TransformComponent.h"

class VelocityComponent : public Component
{
public:
    VelocityComponent();
    ~VelocityComponent();

    void init() override;
    void update() override;
    void destroy() override;

    void setVelocity(Vector2 velocity);
    Vector2 getVelocity() const;

    void setVelocityDecay(Vector2 velocity_decay);
    Vector2 getVelocityDecay() const;

private:
    Vector2 velocity = {0, 0};
    Vector2 velocity_decay = {0.1, 0.1};
};