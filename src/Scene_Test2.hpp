#pragma once

#include "Scene.hpp"
#include <iostream>

class Scene_Test2 : public Scene {
public:
    Scene_Test2(Core& game) : Scene(game) {
        registerAction(sf::Keyboard::R, "SAY POO2");
    }

    void update() override {
       // std::cout << "Testing" << std::endl;
    }

    void render() override {
        
    }

    void sDoAction(const Action& action) override {
        if (action.type() == "START") {
           if (action.name() == "SAY POO2") std::cout << "Poo222 Start" << std::endl;
        } else if (action.type() == "END") {
            std::cout << "Poo222 End" << std::endl;
        }
    }
};