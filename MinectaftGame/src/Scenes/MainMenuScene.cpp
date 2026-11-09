#include "MainMenuScene.h"

#include "core/Application.h"
#include "utils/FileSystem.h"
#include "scenes/SceneManager.h"
#include "components/UIAnchorComponent.h"
#include "components/TextComponent.h"
#include "components/SpriteComponent.h"
#include "components/ButtonComponent.h"
#include "components/CameraComponent.h"
#include "components/ScriptComponent.h"
#include "utils/StringHash.h"
#include "debug/Debug.h"

#include "GameplayScene.h" 
#include "../scripts/MouseScript.h"

void MainMenuScene::Build(Engine::SceneBuilder& builder)
{
    auto& rm = *Engine::Application::Get().GetResourceManager();

    Engine::Texture2D texButton = rm.GetTexture("res/sprites/NoTexture.png");
    Engine::Font* font = rm.GetFont("res/fonts/ReemKufiFunRegular.ttf", 48);

    Engine::Node* camNode = builder.CreateNode("MenuCamera");
    auto* camComp = camNode->AddComponent<Engine::CameraComponent>(0.5f);

    //Game Title
    {
        Engine::Node* node = builder.CreateNode("TitleText");
        node->AddComponent<Engine::UIAnchorComponent>(Engine::AnchorPreset::TopCenter, Engine::Vector2f(0.0f, 150.0f));
        auto* txt = node->AddComponent<Engine::TextComponent>(
            font, "Minecraft Game", 72.0f,
            Engine::Color{ 255, 255, 255, 255 },
            Engine::RenderLayer::UI);
        txt->alignment = Engine::TextAlignment::Center;
        txt->pivot = Engine::Pivot::TopCenter;
    }

    //Play Button
    {
        Engine::Node* node = builder.CreateNode("PlayButton2D");

        node->AddComponent<Engine::UIAnchorComponent>(Engine::AnchorPreset::Center, Engine::Vector2f(0.0f, -60.0f));
        node->AddComponent<Engine::SpriteComponent>(texButton, Engine::Pivot::Center, Engine::Color{ 80, 80, 180, 200 });

        auto* txt = node->AddComponent<Engine::TextComponent>(
            font, " PLAY", 36.0f,
            Engine::Color{ 255, 255, 255, 255 },
            Engine::RenderLayer::UI);
        txt->pivot = Engine::Pivot::LeftCenter;

        auto* btn = node->AddComponent<Engine::ButtonComponent>();
        btn->SetOnClick([]()
            {
                ENGINE_LOG("Clicked playButton");
                Engine::Application::Get().LoadScene<GameplayScene>();
            });
    }

    //Mouse Cursor
    {
        Engine::Node* node = builder.CreateNode("Mouse");
        node->AddComponent<Engine::SpriteComponent>(texButton, Engine::Pivot::Center, Engine::Color{ 80, 80, 80, 200 });
        node->transform.SetScale(Engine::Vector2f(0.2f, 0.2f));

        node->AddComponent<Engine::ScriptComponent>(new MouseScript(camComp));
    }
}