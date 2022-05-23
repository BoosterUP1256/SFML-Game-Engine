#pragma once

#include <map>
#include <string>
#include <memory>
#include "Action.hpp"
#include "EntityManager.hpp"
#include "AssetManager.hpp"

class Core;

using ActionMap = std::map<int, std::string>;

class Scene {
protected:
    Core&         m_game;
    ActionMap     m_actionMap;
    EntityManager m_entities;
    AssetManager  m_assets;

    Scene(Core& game);

    void registerAction(int input, const std::string& name);

public:
    const ActionMap& getActionMap() const;
    virtual void update() = 0;
    virtual void render() = 0;
    virtual void sDoAction(const Action& action) = 0;
};