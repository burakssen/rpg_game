#pragma once

#include <raylib.h>

#include "../Component.h"
#include "../TransformComponent/TransformComponent.h"

class SpriteComponent : public Component
{
public:
    SpriteComponent() = default;
    SpriteComponent(const SpriteComponent &other) = default;

    SpriteComponent &operator=(const SpriteComponent &other) = default;
    ~SpriteComponent() = default;

    void init() override;
    void update() override;
    void draw() override;
    void destroy() override;

    void setTexture(Texture2D texture);
    Texture2D getTexture() const;

    void setSourceRec(Rectangle source_rec);
    void setDestRec(Rectangle dest_rec);

private:
    Texture2D texture;
    Rectangle source_rec = {0, 0, 0, 0};
    Rectangle dest_rec = {0, 0, 0, 0};
};