#include "Scene.hpp"

Scene::Scene(Core& game)
    : m_game(game) {}

void Scene::registerAction(int input, const std::string& name) {
    m_actionMap[input] = name;
}

const ActionMap& Scene::getActionMap() const {
    return m_actionMap;
}
