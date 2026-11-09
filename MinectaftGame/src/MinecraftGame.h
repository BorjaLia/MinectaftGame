#pragma once

#include "core/interfaces/IGame.h"

class MinecraftGame : public Engine::IGame
{
public:
    MinecraftGame() = default;
    ~MinecraftGame() override = default;

    void SetupInputs() override;
    void RegisterScenes() override;
};