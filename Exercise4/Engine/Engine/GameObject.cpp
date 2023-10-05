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
#include <algorithm>
//#include <tkDecls.h>

namespace MyEngine {
	// public API

	GameObject::GameObject() {
        createdTimestamp = std::chrono::steady_clock::now();
        secondsChildrenWillLive = 0;
	}

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
//		tried to implement my smart method of self-destruction -> turns out ot was not so smart lol
//		if (isCountdownActive) {
//			auto currentTime = std::chrono::steady_clock::now();
//			if (currentTime >= createdTimestamp) {
//				isCountdownActive = false;  // Reset the countdown
//				DestroyObject();
//			}
//		}

		if (shouldRemoveChildrenAfterSeconds)
		{
			auto now = std::chrono::steady_clock::now();
			auto seconds = std::chrono::seconds(static_cast<int>(secondsChildrenWillLive));
			// Use remove_if along with erase to remove elements based on a condition
			// trying to remove without fucking up the list
			_children.erase(
					std::remove_if(_children.begin(), _children.end(), [&](const auto& child) {
						bool res = (child->getTimestamp() + seconds) < now;
						return res;
					}),
					_children.end()
			);
		}

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
		return comp;
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

	void GameObject::DestroyObject() {
		//can't make this stuff work
		//_parent.lock()->RemoveChild(_self.lock());
	}

	void GameObject::DestroyInSeconds(float seconds) {
		createdTimestamp = std::chrono::steady_clock::now() + std::chrono::seconds(static_cast<int>(seconds));
		isCountdownActive = true;
	}

	std::chrono::steady_clock::time_point GameObject::getTimestamp() {
		return createdTimestamp;
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