#include "TextureManager.h"

TextureManager::TextureManager()
{
    this->init();
}

TextureManager::~TextureManager()
{
    this->destroy();
}

TextureManager &TextureManager::getInstance()
{
    static TextureManager instance;
    return instance;
}

void TextureManager::init()
{
    try
    {
        for (const auto &entry : std::filesystem::directory_iterator("assets/textures"))
        {
            std::string texture_name = entry.path().filename().string();
            texture_name = texture_name.substr(0, texture_name.find_last_of('.'));
            this->addTexture(texture_name, new Texture2D(LoadTexture(entry.path().string().c_str())));
        }
    }
    catch (const std::filesystem::filesystem_error &e)
    {
        std::cout << e.what() << std::endl;
    }
}

void TextureManager::destroy()
{
    for (auto &texture : this->textures)
    {
        UnloadTexture(*texture.second);
        delete texture.second;
    }
}

Texture2D *TextureManager::getTexture(std::string texture_name)
{
    return this->textures[texture_name];
}

void TextureManager::addTexture(std::string texture_name, Texture2D *texture)
{
    this->textures[texture_name] = texture;
}
