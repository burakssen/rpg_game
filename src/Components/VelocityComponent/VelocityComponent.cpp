#include "VelocityComponent.h"

VelocityComponent::VelocityComponent()
{
    this->init();
}

VelocityComponent::~VelocityComponent()
{
    this->destroy();
}

void VelocityComponent::init()
{
}

void VelocityComponent::update()
{
    if (velocity.x > 0)
    {
        velocity.x -= velocity_decay.x;
    }
    else if (velocity.x < 0)
    {
        velocity.x += velocity_decay.x;
    }

    if (velocity.y > 0)
    {
        velocity.y -= velocity_decay.y;
    }
    else if (velocity.y < 0)
    {
        velocity.y += velocity_decay.y;
    }

    if (this->getParent())
    {
        TransformComponent *transform = this->getParent()->getComponent<TransformComponent>();
        if (transform)
        {
            transform->setPosition({transform->getPosition().x + this->velocity.x, transform->getPosition().y + this->velocity.y});
        }
    }
}

void VelocityComponent::destroy()
{
}

void VelocityComponent::setVelocity(Vector2 velocity)
{
    this->velocity = velocity;
}

Vector2 VelocityComponent::getVelocity() const
{
    return this->velocity;
}

void VelocityComponent::setVelocityDecay(Vector2 velocity_decay)
{
    this->velocity_decay = velocity_decay;
}

Vector2 VelocityComponent::getVelocityDecay() const
{
    return this->velocity_decay;
}