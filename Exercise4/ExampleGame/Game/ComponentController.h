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
		void SetMovementDirection(glm::vec2 direction);
		ComponentController(bool rotate);
		//glm::vec2 position;
		//float rotaiton;
		bool ShouldRotate;
		void RandomPosition();

		void Init() override;
		void Update(float) override;
		void setSize(float size);
	};
}