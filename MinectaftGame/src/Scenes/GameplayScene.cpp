#include "GameplayScene.h"

#include "core/Application.h"
#include "../MainNode.h"

void GameplayScene::Build(Engine::SceneBuilder& builder)
{
    CreateMainNode(builder);
}