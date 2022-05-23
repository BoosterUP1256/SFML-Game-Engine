#pragma once

#include "Scene.hpp"

class Scene_Menu : public Scene {
private:
    sf::Font font;

    sf::Text m_title;
    sf::Text m_play;
    sf::Text m_options;
    sf::Text m_quit;

    int m_currentSelected = 0;

public:
    Scene_Menu(Core& game);

    void update() override;
    void render() override;
    void sDoAction(const Action& action) override;
};

// TODO: I should make a class or component to easiar manipulate text on screen.
