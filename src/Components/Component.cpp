#include "Component.h"

void Component::setParent(Entity *parent)
{
    this->parent = parent;
}

Entity *Component::getParent() const
{
    return this->parent;
}