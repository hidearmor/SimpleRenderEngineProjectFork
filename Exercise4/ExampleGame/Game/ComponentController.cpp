#include "ComponentController.h"
#include <glm/glm.hpp>
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

		/*
		 * I can't seem to find a perfect way of controlling my ship witout it slowly getting
		 * the rotation off if you rotate in the same direction for a long time
		 */
		float smoothRotSpeed = 0.016666667f;
		// float smoothRotSpeed = 1.0f/60.0f; // this is not detailed enough for some reason

		parent->rotation += (RotSpeed * deltaTime);
		//parent->rotation += std::atan2(MovDirection.y, MovDirection.x); //atempt to use rotation to control mov direction
		// Convert rotation to direction vector
		if(isPlayer) {
			// we have done the -sin here to offset by 90 degrees "left"
			MovDirection = glm::vec2(-sin(smoothRotSpeed * (parent->rotation)), cos(smoothRotSpeed * (parent->rotation)));
		}
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

    void ComponentController::RandomizeDirection() {
        static std::random_device rd;
        std::mt19937 gen(rd());

        // Assuming you want a random direction within a unit circle
        std::uniform_real_distribution<float> distTheta(0.0f, 2.0f * static_cast<float>(M_PI));
        float theta = distTheta(gen);

        MovDirection = glm::vec2(std::cos(theta), std::sin(theta));
    }

	void ComponentController::SetRotationSpeed(float speed){
		RotSpeed = speed;
	}

	void ComponentController::SetMovementDirection(glm::vec2 direction)
	{
		MovDirection = direction;
	}

	void ComponentController::SetMovementSpeed(float speed) {
		MovSpeed = speed;
	}

	glm::vec2 ComponentController::getMovDirection() {
		return MovDirection;
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