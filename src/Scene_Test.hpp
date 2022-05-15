#pragma once

#include "Scene.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

class Scene_Test : public Scene {
public:
    double x = 20.0;
    double y = 20.0;
    double xVelocity = 75.0;
    double yVelocity = 75.0;
    bool firstUpdate = true;
    Scene_Test(Core& game) : Scene(game) {
        registerAction(sf::Keyboard::P, "SAY POO");
        registerAction(sf::Keyboard::S, "SWITCH SCENE");
        registerAction(sf::Keyboard::Space, "SPACE");
        registerAction(sf::Keyboard::A, "LEFT");
        registerAction(sf::Keyboard::D, "RIGHT");
        auto circle = m_entities.addEntity("circle");
        circle->addComponent<CTest>();
        circle->addComponent<CShape>(50, 4, sf::Color::Blue, sf::Color::Green, 2);
    }

    void update() override;
    void render() override;

    void sDoAction(const Action& action) override;
};