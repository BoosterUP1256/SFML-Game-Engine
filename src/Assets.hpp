#pragma once

#include <map>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Animation.hpp"

class Assets {
private:
    std::map<std::string, sf::Texture>     m_textureMap;
    std::map<std::string, Animation>       m_animationMap;
    std::map<std::string, sf::SoundBuffer> m_soundBufferMap;
    std::map<std::string, sf::Font>        m_fontMap;

public:
    void addTexture(const std::string& name, const std::string& path);
    void addSoundBuffer(const std::string& name, const std::string& path);
    void addFont(const std::string& name, const std::string& path);
    void addAnimation(const std::string& name, Animation& animation);

    sf::Texture& getTexture(const std::string& name);
    sf::SoundBuffer& getSoundBuffer(const std::string& name);
    sf::Font& getFont(const std::string& name);
    Animation& getAnimation(const std::string& name);

    //TODO: include method to read in from config file

};
