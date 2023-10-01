#pragma once

#include "Engine/Component.h"

namespace ExampleGame {
	class ComponentController : public MyEngine::Component {
		float MovSpeed;
		float MovAmount;
		glm::vec2 MovDirection;

	public:
		float RotSpeed;
		ComponentController();
		glm::vec2 position;
		float rotaiton;

		void Init() override;
		void Update(float) override;
		void setSize(float size);
		void TakeInput();
	};
}