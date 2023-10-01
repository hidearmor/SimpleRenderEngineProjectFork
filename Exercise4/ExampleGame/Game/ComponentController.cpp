#include "ComponentController.h"

#include "Engine/MyEngine.h"

namespace ExampleGame {
	ComponentController::ComponentController(){
		RotSpeed = 10;
		MovSpeed = 100;
		MovAmount = 2;
		MovDirection = glm::vec2(0, 1);
	}
	void ComponentController::Init() {
		MyEngine::GameObject* parent = GetGameObject();
		MyEngine::Engine* engine = MyEngine::Engine::GetInstance();
		glm::vec2 basePos = engine->GetScreenSize() / 2.f;
		parent->position = basePos;
	}

	void ComponentController::Update(float deltaTime) {
		MyEngine::Engine* engine = MyEngine::Engine::GetInstance();
		MyEngine::GameObject* parent = GetGameObject();

		parent->rotation += RotSpeed * deltaTime;
		parent->position += MovDirection * MovAmount * MovSpeed * deltaTime;

		// Optional: You can reset the position when it goes off-screen

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

	void TakeInput(){

	}

}