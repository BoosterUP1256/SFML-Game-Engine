#include "Assets.hpp"
#include <iostream>

void Assets::addTexture(const std::string& name, const std::string& path) {
    m_textureMap[name] = sf::Texture();

    if (!m_textureMap[name].loadFromFile(path)) {
        std::cerr << "Failed to load texture file: " << path << std::endl;
        m_textureMap.erase(name);
    } else {
        std::cout << "Loaded Texture " << name << std::endl;
    }
}

void Assets::addSoundBuffer(const std::string& name, const std::string& path) {
    m_soundBufferMap[name] = sf::SoundBuffer();

    if (!m_soundBufferMap[name].loadFromFile(path)) {
        std::cerr << "Failed to load sound file: " << path << std::endl;
        m_soundBufferMap.erase(name);
    } else {
        std::cout << "Loaded SoundBuffer" << name << std::endl;
    }
}

void Assets::addAnimation(const std::string& name, Animation& animation) {
    m_animationMap[name] = animation;
    std::cout << "Loaded Animation " << name << std::endl;
}

void Assets::addFont(const std::string& name, const std::string& path) {
    m_fontMap[name] = sf::Font();

    if (!m_fontMap[name].loadFromFile(path)) {
        std::cerr << "Failed to load font file: " << path << std::endl;
        m_fontMap.erase(name);
    } else {
        std::cout << "Loaded Font " << name << std::endl;
    }
}

sf::Texture& Assets::getTexture(const std::string& name) {
    return m_textureMap[name];
}

sf::SoundBuffer& Assets::getSoundBuffer(const std::string& name) {
    return m_soundBufferMap[name];
}

sf::Font& Assets::getFont(const std::string& name) {
    return m_fontMap[name];
}

Animation& Assets::getAnimation(const std::string& name) {
    return m_animationMap[name];
}
