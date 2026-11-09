#include "MouseScript.h"

#include "scenes/Node.h"
#include "debug/Debug.h"
#include "core/Application.h"

#include "components/SpriteComponent.h"
#include "events/EventBus.h"
#include "events/InputEvents.h"

namespace
{
    int mouseBlockId = 0;
}

MouseScript::MouseScript(Engine::CameraComponent* camera)
    : camera(camera)
{
}

MouseScript::~MouseScript()
{
    Engine::Application::Get().GetEventBus().Unsubscribe(
        Engine::ActionChangedEvent::GetStaticType(),
        actionSubId
    );
}

void MouseScript::OnStart()
{
    if (!owner) return;
    ENGINE_LOG("Started mouse script");

    auto& bus = Engine::Application::Get().GetEventBus();
    actionSubId = bus.Subscribe<Engine::ActionChangedEvent>(
        [this](Engine::ActionChangedEvent& e) { this->OnActionChanged(e); }
    );
}

void MouseScript::OnUpdate(float deltaTime)
{
    (void)deltaTime;
    if (!camera) return;

    auto& input = Engine::Application::Get().GetInputManager();

    Engine::Vector2f screenMousePos = {
        input.GetAxis(Engine::Hash::GetHash("Pointer_X")),
        input.GetAxis(Engine::Hash::GetHash("Pointer_Y"))
    };

    Engine::Vector2f worldMousePos = camera->ScreenToWorld(screenMousePos);
    owner->transform.SetPosition(worldMousePos);
}

void MouseScript::OnActionChanged(Engine::ActionChangedEvent& e)
{
    if (e.handled) return;

    if (e.GetValue() == 0.0f) return;

    auto& input = Engine::Application::Get().GetInputManager();
    Engine::Vector2f screenMousePos = {
        input.GetAxis(Engine::Hash::GetHash("Pointer_X")),
        input.GetAxis(Engine::Hash::GetHash("Pointer_Y"))
    };

    Engine::Vector2f worldMousePos = camera->ScreenToWorld(screenMousePos);
}