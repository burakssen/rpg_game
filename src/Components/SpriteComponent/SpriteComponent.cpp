#include "SpriteComponent.h"

void SpriteComponent::init()
{
}

void SpriteComponent::update()
{
}

void SpriteComponent::draw()
{
    TransformComponent *transform = this->getParent()->getComponent<TransformComponent>();
    if (transform)
    {
        DrawTexturePro(this->texture, this->source_rec, this->dest_rec, {0, 0}, transform->getRotation(), WHITE);
    }
}

void SpriteComponent::destroy()
{
    UnloadTexture(this->texture);
}

void SpriteComponent::setTexture(Texture2D texture)
{
    this->texture = texture;
}

Texture2D SpriteComponent::getTexture() const
{
    return this->texture;
}

void SpriteComponent::setSourceRec(Rectangle source_rec)
{
    this->source_rec = source_rec;
}

void SpriteComponent::setDestRec(Rectangle dest_rec)
{
    this->dest_rec = dest_rec;
}

// Path: src/Components/TransformComponent/TransformComponent.cpp