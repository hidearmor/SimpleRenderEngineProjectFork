#include "Component.h"

#include "Logger.h"

namespace MyEngine {
	GameObject* Component::GetGameObject() {
		if (_gameObject.expired())
		{
			Logger::Log("Invalid game object");
			return nullptr;
		}

		return _gameObject.lock().get();
	}

	std::weak_ptr<GameObject> Component::GetGameObjectPtr() {
		if (_gameObject.expired())
		{
			Logger::Log("Invalid game object");
			return std::weak_ptr<GameObject> {};
		}

		return _gameObject;
	}

	void Component::SetGameObject(std::weak_ptr<GameObject> p_gameObject) {
		_gameObject = p_gameObject;
	}
}