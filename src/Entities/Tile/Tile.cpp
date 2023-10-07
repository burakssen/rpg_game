#include "Tile.h"

Tile::Tile()
{
    this->init();
}

Tile::~Tile()
{
}

void Tile::init()
{

    TransformComponent *transform = this->addComponent<TransformComponent>();
    transform->setPosition(Vector2{0, 0});
    transform->setRotation(0);
    transform->setScale(Vector2{3, 3});

    AnimationComponent *animation = this->addComponent<AnimationComponent>();

    if (!TEXTURE_MANAGER.hasTexture("G00"))
    {
        Texture2D *texture = new Texture2D(LoadTexture("assets/tiles/Grass/G00.png"));
        TEXTURE_MANAGER.addTexture("G00", texture);
    }

    Texture2D *water_t = new Texture2D(LoadTexture("assets/tiles/Water.png"));
    Image water_i = LoadImageFromTexture(*water_t);
    ImageResize(&water_i, 128, 32);
    Texture2D *water_1 = new Texture2D(LoadTextureFromImage(water_i));
    TEXTURE_MANAGER.addTexture("Water", water_1);

    Animation *grass = new Animation{
        .name = "grass",
        .number_of_frames = 1,
        .animation_speed = 1,
        .frame_width = 16,
        .frame_height = 16,
        .texture = TEXTURE_MANAGER.getTexture("G00")};

    Animation *water = new Animation{
        .animation_type = AnimationType::INFINITE,
        .name = "water",
        .number_of_frames = 4,
        .animation_speed = 1,
        .frame_width = 32,
        .frame_height = 32,
        .texture = TEXTURE_MANAGER.getTexture("Water")};

    animation->addAnimation("grass", *grass);
    animation->addAnimation("water", *water);
    animation->playAnimation("water");
    animation->setPlaying(true);
}

void Tile::update()
{
    this->getComponent<AnimationComponent>()->update();
}

void Tile::draw()
{
    this->getComponent<AnimationComponent>()->draw();
}

void Tile::destroy()
{
    this->removeComponent<TransformComponent>();
    this->removeComponent<AnimationComponent>();
}

void Tile::handleInput()
{
    this->getComponent<AnimationComponent>()->playAnimation("water");
}

void Tile::setTexture(const std::string &texture_name)
{
    this->texture_name = texture_name;
}

void Tile::setPosition(float x, float y)
{
    TransformComponent *transform = this->getComponent<TransformComponent>();
    transform->setPosition(Vector2{x, y});
}

// Path: src/Entities/Tile/Tile.cpp