#include "Scene_Menu.hpp"
#include "Core.hpp"

Scene_Menu::Scene_Menu(Core& game)
    : 
    Scene(game) {
        registerAction(sf::Keyboard::Down, "MENU DOWN");
        registerAction(sf::Keyboard::Up, "MENU UP");
        registerAction(sf::Keyboard::Enter, "SELECT");

        m_assets.addFont("font", "../assets/fonts/arial.ttf");
        
        m_title = sf::Text("Game Title!", m_assets.getFont("font"));
        m_title.setCharacterSize(50);
        float titleCenterX = m_title.getLocalBounds().left + m_title.getLocalBounds().width / 2;
        float titleCenterY = m_title.getLocalBounds().top + m_title.getLocalBounds().height / 2;
        m_title.setOrigin(titleCenterX, titleCenterY);
        m_title.setPosition(m_game.window().getSize().x / 2, 50);

        m_play = sf::Text("Play", m_assets.getFont("font"));
        m_play.setCharacterSize(30);
        m_play.setPosition(100, 100);

        m_options = sf::Text("Options", m_assets.getFont("font"));
        m_options.setCharacterSize(30);
        m_options.setPosition(100, 150);

        m_quit = sf::Text("Quit", m_assets.getFont("font"));
        m_quit.setCharacterSize(30);
        m_quit.setPosition(100, 200);

    }

void Scene_Menu::update() {
    m_play.setFillColor(sf::Color::White);
    m_options.setFillColor(sf::Color::White);
    m_quit.setFillColor(sf::Color::White);

    if (m_currentSelected == 0) {
        m_play.setFillColor(sf::Color::Red);
    } else if (m_currentSelected == 1) {
        m_options.setFillColor(sf::Color::Red);
    } else if (m_currentSelected == 2) {
        m_quit.setFillColor(sf::Color::Red);
    }
}

void Scene_Menu::render() {
    m_game.window().draw(m_title);
    m_game.window().draw(m_play);
    m_game.window().draw(m_options);
    m_game.window().draw(m_quit);
}

void Scene_Menu::sDoAction(const Action& action) {
    if (action.type() == "START") {
        if (action.name() == "MENU DOWN") {
            if (m_currentSelected == 2) {
                m_currentSelected = 0;
            } else {
                m_currentSelected++;
            }
        } else if (action.name() == "MENU UP") {
            if (m_currentSelected == 0) {
                m_currentSelected = 2;
            } else {
                m_currentSelected--;
            }
        }

        if (action.name() == "SELECT") {
            if (m_currentSelected == 2) {
                m_game.quit();
            }
        }
    }
}