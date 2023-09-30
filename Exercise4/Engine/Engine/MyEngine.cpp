#include "MyEngine.h"

#include <random>

#include "sre/RenderPass.hpp"

namespace MyEngine {
	Engine* Engine::_instance = nullptr;

	Engine::Engine() {
		assert(_instance == nullptr && " Only one instance of MyEngine::Engine allowed!");
		_instance = this;

		_root = std::make_shared<GameObject>();
		_root->SetName("root");
	}

	glm::vec2 Engine::GetScreenSize() const
	{
		return WIN_SIZE;
	}

	void Engine::Init() {
		// initializes random generator
		std::srand(std::time(nullptr));

		_camera.setWindowCoordinates();

		_root->Init();
	}

	void Engine::ProcessEvents(SDL_Event& event) {
		//_root.KeyEvent(event);
	}

	void Engine::Update(float deltaTime) {
		++frame;
		time += deltaTime;
		_root->Update(deltaTime);
		// equivalent to writing: (*_root).Update(deltaTime);
		// In this case, _root is dereferenced using * to access the
		// // object it points to, and then the Update method of that object is called.
	}

	void Engine::Render()
	{
		sre::RenderPass renderPass = sre::RenderPass::create()
			.withCamera(_camera)
			.withClearColor(true, { .3f, .3f, 1, 1 })
			.build();

		sre::SpriteBatch::SpriteBatchBuilder spriteBatchBuilder = sre::SpriteBatch::create();

		_root->Render(spriteBatchBuilder);
			// -> is a way of accessing the method of the object the pointer _root is pointing to

		auto spriteBatch = spriteBatchBuilder.build();
		renderPass.draw(spriteBatch);
	}

	std::shared_ptr<GameObject> Engine::CreateGameObject(std::string name) {
		auto ret = std::make_shared<GameObject>();
		ret->_self = ret;
		ret->_parent = _root;
		ret->SetName(name);
		_root->AddChild(ret);

		return ret;
	}
}
