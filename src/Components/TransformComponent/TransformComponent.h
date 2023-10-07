#pragma once

#include <raylib.h>

#include "../Component.h"

class TransformComponent : public Component
{

public:
    TransformComponent();
    ~TransformComponent();

    void init() override;
    void update() override;
    void draw() override;
    void destroy() override;

    void setPosition(Vector2 position);
    void setRotation(float rotation);
    void setScale(Vector2 scale);
    void defaultTransform();

    Vector2 getPosition() const;
    float getRotation() const;
    Vector2 getScale() const;

private:
    Vector2 position = {0, 0};
    float rotation = 0;
    Vector2 scale = {1, 1};

    Vector2 old_position = {0, 0};
    float old_rotation = 0;
    Vector2 old_scale = {1, 1};
};