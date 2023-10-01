#pragma once

#include "sre/SDLRenderer.hpp"
#include "sre/SpriteAtlas.hpp"

#include "Engine/MyEngine.h"
#include "Engine/Observer.h"
#include <string>

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

        void CreatePlayer();

        bool onKey(SDL_Event &event);

        void InstantiateAsteroid(int time);

        MyEngine::Engine engine;

        glm::vec2 window_size = glm::vec2(800, 600);
        sre::SDLRenderer renderer;
        sre::Camera camera;
        std::shared_ptr <sre::SpriteAtlas> atlas;

        std::map<std::string, std::list<std::shared_ptr<MyEngine::GameObject>>> gameObjects;

        //void DestroyObject(std::string category, std::shared_ptr<MyEngine::GameObject> obj);
        //void DestroyObject(std::shared_ptr<MyEngine::GameObject> obj);

        //void DeleteObjectsBasedOnConditions();
    private:
        static MyGame* _instance;
    };
}
