#include "TransformComponent.h"

TransformComponent::TransformComponent()
{
    this->init();
}

TransformComponent::~TransformComponent()
{
    this->destroy();
}

void TransformComponent::init()
{
}

void TransformComponent::update()
{
}

void TransformComponent::draw()
{
}

void TransformComponent::destroy()
{
}

void TransformComponent::setPosition(Vector2 position)
{
    this->position = position;
}

void TransformComponent::setRotation(float rotation)
{
    this->rotation = rotation;
}

void TransformComponent::setScale(Vector2 scale)
{
    this->scale = scale;
}

Vector2 TransformComponent::getPosition() const
{
    return this->position;
}

float TransformComponent::getRotation() const
{
    return this->rotation;
}

Vector2 TransformComponent::getScale() const
{
    return this->scale;
}

// Path: src/Components/TransformComponent/TransformComponent.cpp