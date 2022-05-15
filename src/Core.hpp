#pragma once

#include <memory>
#include <SFML/Graphics.hpp>
#include "Scene.hpp"

using SceneMap = std::map<std::string, std::unique_ptr<Scene>>;

class Core {
private:
    sf::RenderWindow m_window;
    sf::Clock        m_clock;
    SceneMap         m_scenes;
    std::string      m_currentScene;
    float            m_deltaTime;
    bool             m_running = true;

    Scene& currentScene();

public:
    Core();
    
    void run();
    void update();
    void render();
    void quit();
    void changeScene(const std::string& newScene);
    sf::RenderWindow& window();
    void sUserInput();
    float deltaTime() const;
};
