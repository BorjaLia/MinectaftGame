#pragma once

#include "scenes/Scene.h"

class GameplayScene : public Engine::IScene
{
public:
    void Build(Engine::SceneBuilder& builder) override;
};