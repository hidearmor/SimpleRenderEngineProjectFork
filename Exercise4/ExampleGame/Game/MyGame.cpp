#include "MyGame.h"
#include "Engine/MyEngine.h"

#include "ComponentController.h"
#include "ComponentRendererSprite.h"

namespace ExampleGame {

    MyGame* MyGame::_instance = nullptr;

    MyGame::MyGame() {
        assert(_instance == nullptr && " Only one instance of MyEngine::Engine allowed!");
        _instance = this;

        gameObjects["Asteroids"].push_back({});
        gameObjects["Lazers"].push_back({});

        InitGame();
    };



    void MyGame::InitGame() {
        renderer.frameRender = [this] { Render(); };
        renderer.frameUpdate = [this](float deltaTime) { Update(deltaTime); };
        renderer.keyEvent = [this](SDL_Event& event) { ProcessEvents(event); };

        renderer.setWindowSize(window_size);
        renderer.init();
        camera.setWindowCoordinates();

        atlas = sre::SpriteAtlas::create("data/Asteroids.json", "data/Asteroids.png");

        CreatePlayer();

        engine.Init();
        renderer.startEventLoop();
    }

    void MyGame::CreatePlayer() {
        // create player
        std::shared_ptr<MyEngine::GameObject> playerObject = engine.CreateGameObject("Player");
        auto componentController = std::shared_ptr<ExampleGame::ComponentController>(
                new ExampleGame::ComponentController()
        );
        auto componentRenderer = std::make_shared<ExampleGame::ComponentRendererSprite>();
        playerObject->AddComponent(componentController);
        playerObject->AddComponent(componentRenderer);

        componentRenderer->sprite = atlas->get("playerShip3_orange.png");
        glm::vec2 scale = glm::vec2(0.6, 0.6);
        componentRenderer->sprite.setScale(scale);
    }

    void MyGame::InstantiateAsteroid(int time) {
        std::shared_ptr<MyEngine::GameObject> gameObject = engine.CreateGameObject("Asteroid");
        auto& myList = gameObjects["Asteroids"];
        myList.push_back(gameObject);
        auto componentController = std::shared_ptr<ExampleGame::ComponentController>(
                new ExampleGame::ComponentController());
        auto componentRenderer = std::make_shared<ExampleGame::ComponentRendererSprite>();
        gameObject->AddComponent(componentController);
        gameObject->AddComponent(componentRenderer);

        componentRenderer->sprite = atlas->get("meteorBrown_big1.png");
        glm::vec2 scale = glm::vec2(1, 1);
        componentRenderer->sprite.setScale(scale);
    }

    bool MyGame::onKey(SDL_Event &event) {
        switch (event.key.keysym.sym) {
            case SDLK_SPACE: {
                InstantiateAsteroid(1);
            }
                break;
            case SDLK_LEFT: {
                //left = event.type == SDL_KEYDOWN;
                InstantiateAsteroid(1);
            }
                break;
            case SDLK_RIGHT: {
                //right = event.type == SDL_KEYDOWN;
            }
                break;
        }

        return false;
    }

    void MyGame::ProcessEvents(SDL_Event &event) {
        onKey(event);
        if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_x){
            DeleteObjectsBasedOnConditions();
        }
    }

    void MyGame::Update(float deltaTime) {
        engine.Update(deltaTime);
        DeleteObjectsBasedOnConditions();
    }

    void MyGame::Render() {
        engine.Render();
    }

    void MyGame::DestroyObject(std::string category, std::shared_ptr<MyEngine::GameObject> obj) {
        if(category == "Asteroids")
        {
            auto& myList = gameObjects[category];
            auto it = std::find(myList.begin(), myList.end(), obj);
            if (it != myList.end()) {
                myList.erase(it);
            }
        }
	}

    void MyGame::DestroyObject(std::shared_ptr<MyEngine::GameObject> obj) {
        for (auto &pair : gameObjects) {
            auto &myList = pair.second;
            auto it = std::find(myList.begin(), myList.end(), obj);
            if (it != myList.end()) {
                myList.erase(it);
            }
        }
    }

    void MyGame::DeleteObjectsBasedOnConditions() {
        // Example: Delete objects after 5 seconds
        for (auto it = gameObjects.begin(); it != gameObjects.end(); ) {
            auto gameObject = *it;
            bool mb = false;
            if (mb) {
                it = gameObjects.erase(it);
            } else {
                ++it;
            }
        }
    }

    void MyGame::onGameObjectDestroyed(std::shared_ptr<MyEngine::GameObject> gameObject) {
        MyGame::DestroyObject("Asteroids", gameObject);
    }


}