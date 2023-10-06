#pragma once

#include "../Entities/Entity.h"

class Entity;

class Component
{
public:
    Component() = default;
    Component(const Component &other) = default;

    virtual Component &operator=(const Component &other) = default;
    virtual ~Component() = default;

    virtual void init(){};
    virtual void update(){};
    virtual void draw(){};
    virtual void destroy(){};

    void setParent(Entity *parent);
    Entity *getParent() const;

private:
    Entity *parent = nullptr;
};