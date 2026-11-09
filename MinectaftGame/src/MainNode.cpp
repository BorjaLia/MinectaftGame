#include "MainNode.h"

#include "components/ScriptComponent.h"

#include "MainScript.h"

Engine::Node* CreateMainNode(Engine::SceneBuilder& builder)
{
    Engine::Node* baseNode = builder.CreateNode("MainNode");
    baseNode->AddComponent<Engine::ScriptComponent>(new MainScript());
    
    Engine::Node* camNode = builder.CreateChildNode(baseNode,"Camera");
    camNode->AddComponent<Engine::CameraComponent>(0.5f);

    return baseNode;
}