#pragma once

#include <list>
#include <memory>
#include <string>
#include <chrono>

#include "sre/SpriteBatch.hpp"

namespace MyEngine {
	class Component;
	//class Observer;

	//class GameObject : public std::enable_shared_from_this<GameObject> {
    class GameObject{
		friend class Engine;

		// public API
	public:
        GameObject();
        ~GameObject();
		glm::vec2 position;
		bool shouldRemoveChildrenAfterSeconds = false;
		float secondsChildrenWillLive;
		float rotation;
		float Size = 1;
		void setSize(float newSize);
		void Init();
		void Update(float);
		void Render(sre::SpriteBatch::SpriteBatchBuilder&);
		void KeyEvent(SDL_Event&);

		void AddChild(std::shared_ptr<GameObject>);
        void RemoveChild(std::shared_ptr<GameObject> p_object);
        void RemoveChildren();
		void AddComponent(std::shared_ptr<Component>);
        std::shared_ptr<Component> GetFirstComponent();
		void RandomizePosition();
        std::list<std::weak_ptr<Component>> getComponents();

		std::string GetName();
		void SetName(std::string);
        void DestroyObject();
        void DestroyInSeconds(float seconds);
        std::chrono::steady_clock::time_point getTimestamp();

        //void addObserver(std::shared_ptr<Observer> observer);
        //void notifyObservers();

		// private fields
	private:
        //std::vector<std::weak_ptr<Observer>> observers;
		std::weak_ptr<GameObject> _parent;
		std::weak_ptr<GameObject> _self;
		std::list<std::shared_ptr<GameObject>> _children = {};
		std::list< std::shared_ptr<Component>> _components = {};
		std::string _name;

        // Timestamp for destruction countdown
        std::chrono::steady_clock::time_point createdTimestamp;

        // Flag to indicate whether destruction countdown is active
        bool isCountdownActive;
	};
}