#pragma once

#include "Engine/Component.h"

namespace ExampleGame {
	class ComponentController : public MyEngine::Component {
		float MovSpeed;
		float MovAmount;
		glm::vec2 MovDirection;
		float RotSpeed;
		glm::vec2 basePos;

	public:
		void SetRotationSpeed(float speed);
		void SetMovementSpeed(float speed);
		void SetMovementDirection(glm::vec2 direction);
		glm::vec2 getMovDirection();
        void RandomizeDirection();
		ComponentController(bool rotate);
        void KeyEvent(SDL_Event &event) override;
		//glm::vec2 position;
		//float rotaiton;
		bool ShouldRotate;
		bool isPlayer = false;

		void Init() override;
		void Update(float) override;
		void setSize(float size);
	private:
		//float smoothRotSpeed;
	};
}