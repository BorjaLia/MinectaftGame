#include "MainScript.h"

#include "debug/Debug.h"

MainScript::MainScript()
{
}

MainScript::~MainScript()
{
}

void MainScript::OnStart()
{
	ENGINE_LOG("Started main script");
}

void MainScript::OnUpdate(float deltaTime)
{
	(void)deltaTime;
}

void MainScript::OnFixedUpdate(float fixedDeltaTime)
{
	(void)fixedDeltaTime;
}

void MainScript::OnDestroy()
{
}