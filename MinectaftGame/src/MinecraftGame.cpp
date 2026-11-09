#include "MinecraftGame.h"

#include "core/Application.h"
#include "utils/StringHash.h"

#include "scenes/MainMenuScene.h"

void MinecraftGame::SetupInputs()
{
    Engine::InputManager& input = Engine::Application::Get().GetInputManager();

    //UI & SYSTEM
    input.BindAction(Engine::Hash::GetHash("UI_Interact"), Engine::MouseButton::Left, Engine::ActionCategory::System);
    input.BindAction(Engine::Hash::GetHash("UI_Pause"), Engine::Key::Escape, Engine::ActionCategory::Gameplay);
    input.BindAction(Engine::Hash::GetHash("UI_Pause"), Engine::Key::Tab, Engine::ActionCategory::System);

    input.BindAction(Engine::Hash::GetHash("Fullscreen"), Engine::Key::F11, Engine::ActionCategory::System);

    // GAMEPLAY
    input.BindAction(Engine::Hash::GetHash("Game_SpawnRight"), Engine::MouseButton::Right, Engine::ActionCategory::Gameplay);

    // Horizontal Movement
    input.BindAxis(Engine::Hash::GetHash("Game_MoveZ"), Engine::Key::W, 1.0f);
    input.BindAxis(Engine::Hash::GetHash("Game_MoveZ"), Engine::Key::S, -1.0f);
    input.BindAxis(Engine::Hash::GetHash("Game_MoveX"), Engine::Key::D, 1.0f);
    input.BindAxis(Engine::Hash::GetHash("Game_MoveX"), Engine::Key::A, -1.0f);

    // Jump
    input.BindAction(Engine::Hash::GetHash("Game_Jump"), Engine::Key::Space);

    // Crouch
    input.BindAction(Engine::Hash::GetHash("Game_Crouch"), Engine::Key::LeftShift);

    // Run
    input.BindAction(Engine::Hash::GetHash("Game_Run"), Engine::Key::LeftControl);
}

void MinecraftGame::RegisterScenes()
{
    Engine::Application::Get().GetSceneManager().LoadScene(std::make_unique<MainMenuScene>());
}