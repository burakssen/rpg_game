#pragma once

#include <iostream>
#include <string>

#include "../Components/Component.h"

class Component;

class Entity
{
public:
    Entity();
    Entity(std::string name);
    Entity(const Entity &other);

    virtual Entity &operator=(const Entity &other);
    virtual ~Entity();
    virtual void init();
    virtual void update();
    virtual void draw();
    virtual void destroy();
    virtual void handleInput();

    void setName(std::string name);
    std::string getName() const;

    template <typename T>
    T *getComponent()
    {
        for (auto component : this->components)
        {
            T *t = dynamic_cast<T *>(component);
            if (t)
            {
                return t;
            }
        }
        return nullptr;
    }

    template <typename T>
    T *addComponent()
    {
        T *component = new T();
        component->setParent(this);
        this->components.push_back(component);
        return component;
    }

    template <typename T>
    void removeComponent()
    {
        for (auto it = this->components.begin(); it != this->components.end(); ++it)
        {
            T *t = dynamic_cast<T *>(*it);
            if (t)
            {
                this->components.erase(it);
                return;
            }
        }
    }

    template <typename T>
    bool hasComponent()
    {
        for (auto component : this->components)
        {
            T *t = dynamic_cast<T *>(component);
            if (t)
            {
                return true;
            }
        }
        return false;
    }

protected:
    std::vector<Component *> components;

private:
    std::string name = "Entity";
};