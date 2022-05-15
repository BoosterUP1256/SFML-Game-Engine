#include <SFML/Graphics.hpp>
#include "Animation.hpp"
#include <iostream>

int main() 
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Animation Testing");

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

    Animation anim(frames, 100, true);

    sf::Texture currentFrame = anim.currentFrame();
    
    sf::Sprite sprite(currentFrame);

    sprite.setPosition(100, 100);;
    anim.start();

    // from spritesheet
    sf::Image spriteSheet;
    spriteSheet.loadFromFile("../fum.png");
    Animation anim2(spriteSheet, 24, 32, 100, true);
    anim2.start();

    sf::Sprite sprite2(anim2.currentFrame());
    sprite2.setPosition(400, 400);
    sprite2.setScale(5, 5);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.key.code == sf::Keyboard::Space && event.type == sf::Event::KeyPressed) {
                if (anim.isRunning())
                    anim.stop();
                else
                    anim.start();
            }

            if (event.key.code == sf::Keyboard::Enter && event.type == sf::Event::KeyPressed)
                anim.setCurrentFrame(3);
        }

        window.clear();

        // multiple pictures

        anim.update();

        sprite.setTexture(anim.currentFrame());

        if (!anim.isFinished())
            window.draw(sprite);

        // spritesheet

        anim2.update();
        sprite2.setTexture(anim2.currentFrame());
        window.draw(sprite2);

        window.display();
    }

    return 0;
}