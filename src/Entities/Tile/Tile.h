#pragma once

#include <raylib.h>

#include "../Entity.h"
#include "../../TextureManager/TextureManager.h"

#include "../../Components/TransformComponent/TransformComponent.h"
#include "../../Components/AnimationComponent/AnimationComponent.h"

class Tile : public Entity
{
public:
    Tile();
    ~Tile();

    void init() override;
    void update() override;
    void draw() override;
    void destroy() override;

    void handleInput() override;
    void setTexture(const std::string &texture_name);

    void setPosition(float x, float y);

private:
    std::string texture_name;
};