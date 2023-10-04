#pragma once
#include "GameObject.h"

#include "sre/RenderPass.hpp"

#include "MyEngine.h"
#include "Component.h"
#include "Logger.h"

#include <iostream>
#include <memory>
#include <future>
#include <thread>
#include <chrono>
#include <random>

namespace MyEngine {
	// public API

	GameObject::~GameObject(){
		std::cout << "Destructor reached" << this->_name << std::endl;
	}
	void GameObject::Init() {
		for (auto& component : _components)
			component->Init();

		for (auto& child : _children)
			child->Init();
	}

	void GameObject::Update(float deltaTime) {
		for (auto& component : _components)
			component->Update(deltaTime);

		for (auto& child : _children)
			child->Update(deltaTime);
	}

	void GameObject::Render(sre::SpriteBatch::SpriteBatchBuilder& spriteBatchBuilder) {
		for (auto& component : _components)
			component->Render(spriteBatchBuilder);

		for (auto& child : _children)
			child->Render(spriteBatchBuilder);
	}

	void GameObject::KeyEvent(SDL_Event& e) {
		for (auto& component : _components)
			component->KeyEvent(e);

		for (auto& child : _children)
			child->KeyEvent(e);
	}

	void GameObject::AddChild(std::shared_ptr<GameObject> p_object) {
		_children.push_back(p_object);
	}

	void GameObject::RemoveChild(std::shared_ptr<GameObject> p_object) {
		_children.remove(p_object);
	}

	void GameObject::RemoveChildren() {
		_children.clear();
	}

	void GameObject::AddComponent(std::shared_ptr<Component> p_component) {
		p_component->SetGameObject(_self);
		_components.push_back(p_component);
	}

	std::string GameObject::GetName() {
		return _name;
	}

	void GameObject::SetName(std::string p_name) {
		_name = p_name;
	}

	void GameObject::setSize(float newSize){
		Size = newSize;
	}

	std::shared_ptr<Component> GameObject::GetFirstComponent(){
		std::shared_ptr<Component> comp = _components.front();
	}

    void GameObject::RandomizePosition(){
        static std::random_device rd;
        std::mt19937 gen(rd());
        MyEngine::Engine* engine = MyEngine::Engine::GetInstance();
        auto bounds = engine->GetScreenSize();
        std::uniform_real_distribution<float> distx(0,bounds.x);
        std::uniform_real_distribution<float> disty(0,bounds.y);
        float x = distx(gen);
        float y = disty(gen);
        auto pos = glm::vec2(x,y);
        position = pos;
    }

	std::list<std::weak_ptr<Component>> GameObject::getComponents() {
		std::list<std::weak_ptr<Component>> ret = {};
		for (auto& component : _components) {
			std::weak_ptr<Component> ptr = component;
			ret.push_back(ptr);
		}
		return ret;
	}

/*
    void GameObject::addObserver(std::shared_ptr<Observer> observer) {
        observers.push_back(observer);
    }

    void GameObject::notifyObservers() {
        for (auto& observer : observers) {
            if (auto sharedObserver = observer.lock()) {
                sharedObserver->onGameObjectDestroyed(shared_from_this());
            }
        }
    }
*/
}