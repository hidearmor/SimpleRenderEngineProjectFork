#include "ComponentController.h"

#include "Engine/MyEngine.h"
#include <random>

namespace ExampleGame {
	ComponentController::ComponentController(bool rotate){
		ShouldRotate = rotate;
		RotSpeed = 0;
		MovSpeed = 100;
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

		float smoothRotSpeed = 0.016666667f;
		//parent->rotation += smoothRotSpeed * RotSpeed * deltaTime;
		//if(ShouldRotate)
		parent->rotation += RotSpeed * deltaTime;
		//parent->rotation += std::atan2(MovDirection.y, MovDirection.x);
		// Convert rotation to direction vector
		if(isPlayer) MovDirection = glm::vec2(cos(smoothRotSpeed * parent->rotation), sin(smoothRotSpeed * parent->rotation));
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
		//parent->rotation += std::atan2(direction.y, direction.x);
	}

	void ComponentController::SetMovementSpeed(float speed) {
		MovSpeed = speed;
	}


	void ComponentController::KeyEvent(SDL_Event &event) {
		if(!isPlayer) return;

		switch (event.key.keysym.sym) {

			case SDLK_a: {
				if(event.type == SDL_KEYDOWN) 		SetRotationSpeed(180);
				else if (event.type == SDL_KEYUP) 	SetRotationSpeed(0);
			}
				break;
			case SDLK_d: {
				if(event.type == SDL_KEYDOWN) 		SetRotationSpeed(-180);
				else if (event.type == SDL_KEYUP) 	SetRotationSpeed(0);
			}
				break;
			case SDLK_w : {
				if(event.type == SDL_KEYDOWN) 		SetMovementSpeed(200);
				else if (event.type == SDL_KEYUP) 	SetMovementSpeed(0);
			}
				break;
			case SDLK_s : {
				if(event.type == SDL_KEYDOWN) 		SetMovementSpeed(-150);
				else if (event.type == SDL_KEYUP) 	SetMovementSpeed(0);
			}
			default: break;
		}

	}



}