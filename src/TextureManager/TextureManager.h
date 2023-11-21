#pragma once

#include <iostream>
#include <raylib.h>

#include <map>
#include <filesystem>

#include "Log/Log.h"

class TextureManager
{
private:
    TextureManager();
    ~TextureManager();

public:
    static TextureManager &getInstance();

    void init();
    void destroy();

    Texture2D *getTexture(std::string texture_name);
    void addTexture(std::string texture_name, Texture2D *texture);
    bool hasTexture(std::string texture_name);

private:
    std::map<std::string, Texture2D *> textures;
};

#define TEXTURE_MANAGER TextureManager::getInstance()
