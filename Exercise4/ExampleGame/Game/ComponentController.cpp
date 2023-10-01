#include "ComponentController.h"

#include "Engine/MyEngine.h"
#include <random>

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

	void ComponentController::RandomPosition(){
		std::random_device rd;
		std::mt19937 gen(rd());
		MyEngine::GameObject* parent = GetGameObject();
		MyEngine::Engine* engine = MyEngine::Engine::GetInstance();
		auto bounds = engine->GetScreenSize();
		std::uniform_real_distribution<float> distx(0,bounds.x);
		std::uniform_real_distribution<float> disty(0,bounds.y);
		float x = distx(gen);
		float y = disty(gen);
		auto pos = glm::vec2(x,y);
		parent->position = pos;
	}

	void ComponentController::SetRotationSpeed(float speed){
		RotSpeed = speed;
	}

	void ComponentController::SetMovementDirection(glm::vec2 direction)
	{

	}

}