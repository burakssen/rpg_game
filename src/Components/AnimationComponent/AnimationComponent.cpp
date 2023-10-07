#include "AnimationComponent.h"

AnimationComponent::AnimationComponent()
{
    this->init();
}

void AnimationComponent::init()
{
    SpriteComponent::init();
    this->is_playing = false;
}

void AnimationComponent::update()
{
    // Update the base sprite component
    SpriteComponent::update();

    // Update the animation logic here
    if (is_playing)
    {
        this->frame_timer += GetFrameTime() * this->animation_speed;
        if (this->frame_timer >= this->frame_duration)
        {
            this->frame_timer = 0.0f;
            this->current_frame++;

            if (this->current_frame > this->number_of_frames - 1)
            {
                if (this->isOnceRunning())
                {
                    this->onceRunning = false;
                }
                else
                {
                    this->current_frame = 0;
                }
            }

            if (this->getParent())
            {
                TransformComponent *transform = this->getParent()->getComponent<TransformComponent>();
                if (transform)
                {
                    // FIXME: This is a hacky way to fix the animation bug
                    this->setSourceRec({static_cast<float>(this->current_frame * this->frame_width), static_cast<float>(this->frame_height), static_cast<float>(this->getTexture().width) / (this->number_of_frames * transform->getScale().x), static_cast<float>(this->getTexture().height) / transform->getScale().y});
                    this->setDestRec({static_cast<float>(transform->getPosition().x),
                                      static_cast<float>(transform->getPosition().y),
                                      static_cast<float>(this->frame_width) / abs(transform->getScale().x), static_cast<float>(this->frame_height) / abs(transform->getScale().y)});
                }
            }
        }
    }
}

void AnimationComponent::draw()
{
    SpriteComponent::draw();
}

void AnimationComponent::destroy()
{
    SpriteComponent::destroy();
}

void AnimationComponent::setAnimationFrames(int number_of_frames, int frame_width, int frame_height)
{
    this->number_of_frames = number_of_frames;
    this->frame_width = frame_width;
    this->frame_height = frame_height;
}

void AnimationComponent::playAnimation(std::string animation_name)
{
    this->is_playing = true;
    this->current_animation = this->animations[animation_name];
    if (this->current_animation.animation_type == AnimationType::ONCE)
    {
        this->onceRunning = true;
    }
    else
    {
        this->onceRunning = false;
    }
    this->setAnimationFrames(this->current_animation.number_of_frames, this->current_animation.frame_width, this->current_animation.frame_height);
    this->setTexture(*this->current_animation.texture);
}

void AnimationComponent::addAnimation(std::string animation_name, Animation animation)
{
    this->animations[animation_name] = animation;
}

void AnimationComponent::stopAnimation()
{
    this->is_playing = false;
}

bool AnimationComponent::isAnimating() const
{
    return this->is_playing;
}

bool AnimationComponent::isAnimationFinished() const
{
    return this->current_frame == this->number_of_frames - 1;
}

void AnimationComponent::setPlaying(bool is_playing)
{
    this->is_playing = is_playing;
}

void AnimationComponent::setAnimationSpeed(float animation_speed)
{
    this->animation_speed = animation_speed;
}

std::string AnimationComponent::getCurrentAnimationName()
{
    return this->current_animation.name;
}

AnimationComponent::~AnimationComponent()
{
    this->destroy();
}

bool AnimationComponent::isOnceRunning() const
{
    return this->current_animation.animation_type == AnimationType::ONCE && this->onceRunning;
}