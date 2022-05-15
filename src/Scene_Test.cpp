#include "Scene_Test.hpp"
#include "Core.hpp"
#include "Animation.hpp"
#include <vector>

void Scene_Test::sDoAction(const Action& action) {
    if (action.type() == "START") {
        if (action.name() == "SAY POO") std::cout << "Poo Start" << std::endl;
        if (action.name() == "SWITCH SCENE") {
            std::cout << "Switching Scene" << std::endl;
            m_game.changeScene("scene 2");
        }
        if (action.name() == "SPACE") {
            for (auto& entities : m_entities.getEntities("test")) {
                std::cout << "bruh" << std::endl;
            }
        }
    } else if (action.type() == "END") {
        // std::cout << "Poo End" << std::endl;
    }
}

void Scene_Test::update() {
    m_entities.update();
    auto circle = m_entities.getEntities("circle")[0];
    //std::cout << m_game.deltaTime() << std::endl;
    x += xVelocity * m_game.deltaTime();
    y += yVelocity * m_game.deltaTime();
    circle->getComponent<CShape>().circle.setPosition(x, y);
    m_game.window().draw(circle->getComponent<CShape>().circle);
}

void Scene_Test::render() {
    m_game.window().draw(m_entities.getEntities("circle")[0]->getComponent<CShape>().circle);

    // sf::Image animImage;
    // animImage.loadFromFile("../spriteTest.png");
    // Vec2 spriteSize(4, 4);
    // Vec2 frameSize(2, 2);

    // Animation testAnim(animImage, spriteSize, frameSize, 4, 0);

    // testAnim.setFrame(1);
    // sf::Sprite sprite = testAnim.currentFrame();
    // sprite.setPosition(50, 50);
    // sprite.setScale(500, 500);
    // m_game.window().draw(sprite);
    sf::Texture t1;
    t1.loadFromFile("../PNG/Enemies/wingMan1.png");

    sf::Texture t2;
    t2.loadFromFile("../PNG/Enemies/wingMan2.png");

    sf::Texture t3;
    t3.loadFromFile("../PNG/Enemies/wingMan3.png");

    sf::Texture t4;
    t4.loadFromFile("../PNG/Enemies/wingMan4.png");

    sf::Texture t5;
    t5.loadFromFile("../PNG/Enemies/wingMan5.png");

    std::vector<sf::Texture> frames;
    frames.push_back(t1);
    frames.push_back(t2);
    frames.push_back(t3);
    frames.push_back(t4);
    frames.push_back(t5);

    Animation anim(frames, 5);

    sf::Texture currentFrame = anim.currentFrame();
    
    sf::Sprite sprite(currentFrame);

    sprite.setPosition(100, 100);
    m_game.window().draw(sprite);
}