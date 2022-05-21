#pragma once

#include "Scene.hpp"

class Scene_Menu : public Scene {
private:
public:
    Scene_Menu(Core& game);

    void update() override;
    void render() override;
    void sDoAction(const Action& action) override;
};
