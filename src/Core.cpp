#include "Core.hpp"
#include "Action.hpp"
#include "Scene_Test.hpp"
#include "Scene_Test2.hpp"
#include "Scene_Menu.hpp"

Core::Core()
    :
    m_window(sf::VideoMode(800, 600), "Window"),
    m_currentScene("menu") {
        m_scenes.emplace(m_currentScene, std::make_unique<Scene_Menu>(*this));
        m_scenes.emplace("main", std::make_unique<Scene_Test>(*this));
        m_scenes.emplace("scene 2", std::make_unique<Scene_Test2>(*this));
}

Scene& Core::currentScene() {
    return *(m_scenes[m_currentScene]);
}

void Core::run() {
    while (m_running) {
        m_deltaTime = m_clock.restart().asSeconds();
        update();
        render();
    }
}

void Core::update() {
    sUserInput();
    currentScene().update();
}

void Core::render() {
    m_window.clear();
    currentScene().render();
    m_window.display();
}

void Core::quit() {
    m_running = false;
}

void Core::changeScene(const std::string& newScene) {
    m_currentScene = newScene;
}

sf::RenderWindow& Core::window() {
    return m_window;
}

void Core::sUserInput() {
    sf::Event event;
    while (m_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            quit();
        }

        if (event.type == sf::Event::KeyPressed || event.type == sf::Event::KeyReleased) {
            if (currentScene().getActionMap().find(event.key.code) == currentScene().getActionMap().end()) { continue; }

            const std::string actionType = (event.type == sf::Event::KeyPressed) ? "START" : "END";

            currentScene().sDoAction(Action(currentScene().getActionMap().at(event.key.code), actionType));
        }
    }
}

float Core::deltaTime() const {
    return m_deltaTime;
}
