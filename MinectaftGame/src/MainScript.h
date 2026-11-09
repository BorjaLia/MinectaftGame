#pragma once

#include "scripts/Script.h"

class MainScript : public Engine::Script
{
public:
    MainScript();
    ~MainScript() override;

    void OnStart() override;
    void OnUpdate(float deltaTime) override;
    void OnFixedUpdate(float fixedDeltaTime) override;
    void OnDestroy() override;

private:
};