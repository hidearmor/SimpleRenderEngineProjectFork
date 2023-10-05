#pragma once

#include "sre/SDLRenderer.hpp"
#include "sre/SpriteAtlas.hpp"

#include "Engine/MyEngine.h"
#include "Engine/Observer.h"
#include "Engine/ColliderCircleComponent.h"
#include <string>
#include "ComponentController.h"

namespace ExampleGame{
//class MyGame : public MyEngine::Observer {
class MyGame {
    public:
        //MyGame instance;
        MyGame();

        //void onGameObjectDestroyed(std::shared_ptr<MyEngine::GameObject> gameObject) override;

        void InitGame();

        void ProcessEvents(SDL_Event &event);

        void Update(float deltaTime);

        void Render();

        std::shared_ptr<MyEngine::GameObject> CreatePlayer();

        bool onKey(SDL_Event &event);

        void InstantiateAsteroid();
        void InstantiateLazer();

        std::weak_ptr<ExampleGame::ComponentController> GetCC(std::shared_ptr<MyEngine::GameObject> gameObject);

        MyEngine::Engine engine;

        glm::vec2 window_size = glm::vec2(800, 600);
        sre::SDLRenderer renderer;
        sre::Camera camera;
        std::shared_ptr <sre::SpriteAtlas> atlas;

//        std::map<std::string, std::list<std::shared_ptr<MyEngine::GameObject>>> gameObjects;
        //void DestroyObject(std::string category, std::shared_ptr<MyEngine::GameObject> obj);
        //void DestroyObject(std::shared_ptr<MyEngine::GameObject> obj);

        //void DeleteObjectsBasedOnConditions();
    private:
        std::shared_ptr<MyEngine::GameObject> asteroidsParent;
        std::shared_ptr<MyEngine::GameObject> lazerParent;
        std::shared_ptr<MyEngine::GameObject> player;
        std::shared_ptr<MyEngine::GameObject> instantiateGO(std::string name, std::shared_ptr<MyEngine::GameObject> parent, std::string _sprite, int rotSpeed);
        void RemoveAsteroids();
        static MyGame* _instance;
        std::list<std::weak_ptr<MyEngine::ColliderCircleComponent>> _collidersAsteroids = {};
        std::list<std::weak_ptr<MyEngine::ColliderCircleComponent>> _collidersLazers = {};
        std::weak_ptr<MyEngine::ColliderCircleComponent> _colliderPlayer;
        void CheckCollisions();
        bool gameOver = false;
        void ReInitGame();
        void MakeSteroids();

    };
}
