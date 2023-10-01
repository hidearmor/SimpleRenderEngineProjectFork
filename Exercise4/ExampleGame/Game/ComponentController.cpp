#include "ComponentController.h"

#include "Engine/MyEngine.h"

namespace ExampleGame {
	ComponentController::ComponentController(bool rotate){
		ShouldRotate = rotate;
		RotSpeed = 10;
		MovSpeed = 200;
		MovAmount = 1;
		MovDirection = glm::vec2(0, 1);
	}
	void ComponentController::Init() {
		MyEngine::GameObject* parent = GetGameObject();
		MyEngine::Engine* engine = MyEngine::Engine::GetInstance();
		basePos = engine->GetScreenSize() / 2.f;
		parent->position = basePos;
	}

	void ComponentController::Update(float deltaTime) {
		MyEngine::Engine* engine = MyEngine::Engine::GetInstance();
		MyEngine::GameObject* parent = GetGameObject();

		if(ShouldRotate) parent->rotation += RotSpeed * deltaTime;
		parent->position += MovDirection * MovAmount * MovSpeed * deltaTime;

		// reset position

		if (parent->position.x > engine->GetScreenSize().x) {
			parent->position.x = 0;
		}
		if (parent->position.x < 0) {
			parent->position.x = engine->GetScreenSize().x;
		}
		if (parent->position.y > engine->GetScreenSize().y) {
			parent->position.y = 0;
		}
		if (parent->position.y < 0) {
			parent->position.y = engine->GetScreenSize().y;
		}

	}

	void ComponentController::SetRotationSpeed(float speed){
		RotSpeed = speed;
	}

	void ComponentController::SetMovementDirection(glm::vec2 direction)
	{

	}

}