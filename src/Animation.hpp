#pragma once

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

class Animation {
private:
    std::vector<sf::Texture> m_frames;
    float                   m_speed = 0.0f;
    int                     m_currentFrame = 0;
    bool                    m_looping = true;
    bool                    m_running = false;
    bool                    m_finished = false;
    sf::Clock               m_animClock;

public:
    Animation(std::vector<sf::Texture>& frames, float speed, bool looping = true);
    Animation(const std::string& spriteSheet, int frameWidth, int frameHeight, float speed, bool looping = true);
    Animation() = default;

    void loadFromSpriteSheet(const sf::Image& spriteSheet, int frameWidth, int frameHeight);

    void addFrame(const sf::Texture& frame);
    void setCurrentFrame(int index);
    void setSpeed(float speed);
    void setLooping(bool looping);
    sf::Texture& currentFrame();
    void start();
    void stop();
    bool isFinished() const;
    bool isRunning() const;
    void update();
};