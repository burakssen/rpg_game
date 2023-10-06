#pragma once

#include <raylib.h>

#include <map>
#include <queue>

#include "../Component.h"
#include "../SpriteComponent/SpriteComponent.h"

#include "../../Log/Log.h"

enum class AnimationType
{
    INFINITE,
    ONCE
};

typedef struct Animation
{
    std::string name;
    int number_of_frames;
    float animation_speed;
    int frame_width;
    int frame_height;
    Texture2D *texture;

    AnimationType animation_type = AnimationType::INFINITE;
} Animation;

class AnimationComponent : public SpriteComponent
{
public:
    AnimationComponent();
    ~AnimationComponent();

    void init() override;
    void update() override;
    void draw() override;
    void destroy() override;

    void setAnimationFrames(int number_of_frames, int frame_width, int frame_height);
    void playAnimation(std::string animation_name);
    void addAnimation(std::string animation_name, Animation animation);
    void stopAnimation();
    bool isAnimating() const;
    bool isAnimationFinished() const;
    bool isOnceRunning() const;

    void setPlaying(bool isPlaying);

    void setAnimationSpeed(float animationSpeed);
    std::string getCurrentAnimationName();

private:
    int number_of_frames = 1;
    int current_frame = 0;
    int frame_width = 0;
    int frame_height = 0;
    float frame_duration = 0.1f;
    float frame_timer = 0.0f;
    bool is_playing = false;
    float animation_speed = 2.0f;

    std::map<std::string, Animation> animations;
    std::queue<std::string> animation_queue;
    Animation current_animation;
    bool onceRunning = false;
};