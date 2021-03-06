#include <SFML/Graphics.hpp>
#include "Animation.hpp"
#include "AssetManager.hpp"
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

    AssetManager assets;

    // from spritesheet
    sf::Image spriteSheet;
    spriteSheet.loadFromFile("../fum.png");
    Animation anim2("../fum.png", 24, 32, 100, true);

    sf::Sprite sprite2(anim2.currentFrame());
    sprite2.setPosition(400, 400);
    sprite2.setScale(5, 5);

    assets.addAnimation("run", anim2);
    assets.getAnimation("run").start();

    // audio asset test
    assets.addSoundBuffer("test", "../testSound.wav");
    assets.addSoundBuffer("scream", "../testSound2.wav");

    assets.addFont("font", "../assets/fonts/arial.ttf");

    sf::Sound sound(assets.getSoundBuffer("test"));
    sf::Sound sound2(assets.getSoundBuffer("scream"));

    sf::Text hello("hello there", assets.getFont("font"));
    hello.setPosition(50, 50);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.key.code == sf::Keyboard::Space && event.type == sf::Event::KeyPressed) {
                sound.play();
                if (assets.getAnimation("run").isRunning())
                    assets.getAnimation("run").stop();
                else
                    assets.getAnimation("run").start();
            }

            else if (event.key.code == sf::Keyboard::Enter && event.type == sf::Event::KeyPressed) {
                sound2.play();
                assets.getAnimation("run").setCurrentFrame(3);
            }
        }

        window.clear();

        // multiple pictures

        assets.getAnimation("run").update();

        sprite.setTexture(assets.getAnimation("run").currentFrame());

        if (!assets.getAnimation("run").isFinished())
            window.draw(sprite);

        // spritesheet

        assets.getAnimation("run").update();
        sprite2.setTexture(assets.getAnimation("run").currentFrame());
        window.draw(sprite2);
        window.draw(hello);

        window.display();
    }

    return 0;
}