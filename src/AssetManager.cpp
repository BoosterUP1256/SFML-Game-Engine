#include "AssetManager.hpp"
#include <iostream>

void AssetManager::addTexture(const std::string& name, const std::string& path) {
    m_textureMap[name] = sf::Texture();

    if (!m_textureMap[name].loadFromFile(path)) {
        std::cerr << "Failed to load texture file: " << path << std::endl;
        m_textureMap.erase(name);
    } else {
        std::cout << "Loaded Texture " << name << std::endl;
    }
}

void AssetManager::addSoundBuffer(const std::string& name, const std::string& path) {
    m_soundBufferMap[name] = sf::SoundBuffer();

    if (!m_soundBufferMap[name].loadFromFile(path)) {
        std::cerr << "Failed to load sound file: " << path << std::endl;
        m_soundBufferMap.erase(name);
    } else {
        std::cout << "Loaded SoundBuffer " << name << std::endl;
    }
}

void AssetManager::addAnimation(const std::string& name, Animation& animation) {
    m_animationMap[name] = animation;
    std::cout << "Loaded Animation " << name << std::endl;
}

void AssetManager::addFont(const std::string& name, const std::string& path) {
    m_fontMap[name] = sf::Font();

    if (!m_fontMap[name].loadFromFile(path)) {
        std::cerr << "Failed to load font file: " << path << std::endl;
        m_fontMap.erase(name);
    } else {
        std::cout << "Loaded Font " << name << std::endl;
    }
}

sf::Texture& AssetManager::getTexture(const std::string& name) {
    return m_textureMap[name];
}

sf::SoundBuffer& AssetManager::getSoundBuffer(const std::string& name) {
    return m_soundBufferMap[name];
}

sf::Font& AssetManager::getFont(const std::string& name) {
    return m_fontMap[name];
}

Animation& AssetManager::getAnimation(const std::string& name) {
    return m_animationMap[name];
}
