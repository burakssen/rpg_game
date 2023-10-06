#include "Entity.h"

Entity::Entity()
{
    this->init();
}

Entity::Entity(std::string name)
{
    this->name = name;
    this->init();
}

Entity::Entity(const Entity &other)
{
    this->name = other.name;
    this->init();
}

Entity &Entity::operator=(const Entity &other)
{
    this->name = other.name;
    this->init();
    return *this;
}

Entity::~Entity()
{
    this->destroy();
}

void Entity::init()
{
}

void Entity::update()
{
    this->handleInput();
    for (auto component : this->components)
    {
        component->update();
    }
}

void Entity::draw()
{
    for (auto component : this->components)
    {
        component->draw();
    }
}

void Entity::destroy()
{
}

void Entity::handleInput()
{
}

void Entity::setName(std::string name)
{
    this->name = name;
}

std::string Entity::getName() const
{
    return this->name;
}