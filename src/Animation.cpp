#include "Animation.hpp"

Animation::Animation(std::vector<sf::Texture>& frames, float speed, bool looping)
    : m_frames(frames), m_speed(speed), m_looping(looping) {}

Animation::Animation(const std::string& path, int frameWidth, int frameHeight, float speed, bool looping)
    : m_speed(speed), m_looping(looping) {
        sf::Image spriteSheet;
        spriteSheet.loadFromFile(path);
        loadFromSpriteSheet(spriteSheet, frameWidth, frameHeight);
}

void Animation::loadFromSpriteSheet(const sf::Image& spriteSheet, int frameWidth, int frameHeight) {
    int numberOfFrames = spriteSheet.getSize().x / frameWidth;

    int left = 0;
    for (int i = 0; i < numberOfFrames; i++) {
        sf::Rect<int> bounds(left, 0, frameWidth, frameHeight);
        sf::Texture toAdd;
        toAdd.loadFromImage(spriteSheet, bounds);
        m_frames.push_back(toAdd);
        left += frameWidth;
    }
}

void Animation::addFrame(const sf::Texture& frame) {
    m_frames.push_back(frame);
}

void Animation::setCurrentFrame(int index) {
    m_currentFrame = index;
}

void Animation::setSpeed(float speed) {
    m_speed = speed;
}

void Animation::setLooping(bool looping) {
    m_looping = looping;
}

sf::Texture& Animation::currentFrame() {
    return m_frames.at(m_currentFrame);
}

void Animation::start() {
    m_running = true;
}

void Animation::stop() {
    m_running = false;
}

bool Animation::isFinished() const {
    return m_finished;
}

bool Animation::isRunning() const {
    return m_running;
}

void Animation::update() {
    if (m_running) {
        if (m_animClock.getElapsedTime().asMilliseconds() >= m_speed) {
            if (m_currentFrame < m_frames.size() - 1) {
                m_currentFrame++;
            } else {
                if (m_looping) {
                    m_currentFrame = 0;
                } else {
                    m_finished = true;
                }
            }

            m_animClock.restart();
        }
    }
}
