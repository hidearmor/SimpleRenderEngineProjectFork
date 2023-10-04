#include "MyGame.h"
#include "Engine/MyEngine.h"

#include "ComponentController.h"
#include "ComponentRendererSprite.h"

namespace ExampleGame {

    MyGame* MyGame::_instance = nullptr;

    MyGame::MyGame() {
        assert(_instance == nullptr && " Only one instance of MyEngine::Engine allowed!");
        _instance = this;
        InitGame();
    };



    void MyGame::InitGame() {
        std::cout << "init" << std::endl; std::cout << std::endl;
        renderer.frameRender = [this] { Render(); };
        renderer.frameUpdate = [this](float deltaTime) { Update(deltaTime); };
        renderer.keyEvent = [this](SDL_Event& event) { ProcessEvents(event); };

        renderer.setWindowSize(window_size);
        renderer.init();
        camera.setWindowCoordinates();

        atlas = sre::SpriteAtlas::create("data/Asteroids.json", "data/Asteroids.png");

        player = CreatePlayer();


        asteroidsParent = engine.CreateGameObject("asteroidsParent");
        lazerParent = engine.CreateGameObject("lazersParent");

        engine.Init();

        for (int i = 1; i <= 5; ++i) InstantiateAsteroid();
        renderer.startEventLoop();
    }

    std::shared_ptr<MyEngine::GameObject> MyGame::CreatePlayer() {
        // create player
        std::shared_ptr<MyEngine::GameObject> playerObject = engine.CreateGameObject("Player");
        auto componentController = std::shared_ptr<ExampleGame::ComponentController>(
                new ExampleGame::ComponentController(false)
        );
        auto componentRenderer = std::make_shared<ExampleGame::ComponentRendererSprite>();
        playerObject->AddComponent(componentController);
        playerObject->AddComponent(componentRenderer);

        componentRenderer->sprite = atlas->get("playerShip3_orange.png");
        glm::vec2 scale = glm::vec2(0.6, 0.6);
        componentRenderer->sprite.setScale(scale);
        componentController->SetRotationSpeed(0);
        componentController->SetMovementSpeed(0);
        componentController->isPlayer = true;
        return playerObject;
    }

    void MyGame::InstantiateAsteroid() {
        std::shared_ptr<MyEngine::GameObject> gameObject =
                instantiateGO("Asteroid", asteroidsParent, "meteorBrown_big1.png", -100);
        gameObject->RandomizePosition();
    }

    void MyGame::InstantiateLazer() {
        std::shared_ptr<MyEngine::GameObject> gameObject =
                instantiateGO("Lazer", asteroidsParent, "laserBlue05.png", 0);

        std::weak_ptr<ExampleGame::ComponentController> playerController = GetCC(player);
        if (playerController.expired()) {
            std::cout << "ComponentController not found!" << std::endl;
        } else {
            auto dir = playerController.lock()->getMovDirection();
            GetCC(gameObject).lock().get()->SetMovementDirection(dir);
        }
    }

    std::weak_ptr<ExampleGame::ComponentController> MyGame::GetCC(std::shared_ptr<MyEngine::GameObject> gameObject) {
        auto list = gameObject->getComponents();
        std::weak_ptr<ExampleGame::ComponentController> cc;

        for (auto& comp : list) {
            if (auto sharedComp = comp.lock()) {
                if (auto controller = std::dynamic_pointer_cast<ExampleGame::ComponentController>(sharedComp)) {
                    cc = controller;
                    break;
                }
            }
        }

        return cc;
    }

    std::shared_ptr<MyEngine::GameObject> MyGame::instantiateGO(
            std::string name, std::shared_ptr<MyEngine::GameObject> parent, std::string _sprite, int rotSpeed){
        std::cout << "created " << name << std::endl;
        std::shared_ptr<MyEngine::GameObject> gameObject = engine.CreateGameObject(name, parent);
        auto componentController = std::shared_ptr<ExampleGame::ComponentController>(
                new ExampleGame::ComponentController(true));
        auto componentRenderer = std::make_shared<ExampleGame::ComponentRendererSprite>();
        gameObject->AddComponent(componentController);
        gameObject->AddComponent(componentRenderer);
        componentRenderer->sprite = atlas->get(_sprite);
        componentController->SetRotationSpeed(rotSpeed);
        componentController->Init();
        //componentController->RandomPosition();
        return gameObject;
    }

    bool MyGame::onKey(SDL_Event &event) {
            switch (event.key.keysym.sym) {
                case SDLK_SPACE: {
                    InstantiateLazer();
                }
                    break;
                case SDLK_LEFT: {
                    //left = event.type == SDL_KEYDOWN;
                    //player->rotation = 0.0;
                }
                    break;
                case SDLK_RIGHT: {
                    //right = event.type == SDL_KEYDOWN;
                    //player->rotation = 0.5;
                }
                    break;
                case SDLK_x : {
                    //DeleteObjectsBasedOnConditions();
                    MyGame::RemoveAsteroids();
                }
                    break;
                case SDLK_ESCAPE : {
                    engine._root = std::make_shared<MyEngine::GameObject>();
                }
                    break;
                default: break;
            }
        return false;
    }

    void MyGame::ProcessEvents(SDL_Event &event) {
        if(event.type == SDL_KEYDOWN) {
            //std::cout << "Process events" << std::endl;
            onKey(event);
        }
        engine.ProcessEvents(event);
    }

    void MyGame::Update(float deltaTime) {
        engine.Update(deltaTime);
        //DeleteObjectsBasedOnConditions();
    }

    void MyGame::Render() {
        engine.Render();
    }

    void MyGame::RemoveAsteroids(){
        asteroidsParent->RemoveChildren();
    }
/*
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
        std::cout << "reached delete method" << std::endl;
        // Example: Delete objects after 5 seconds
        for (auto& pair : gameObjects) {
            auto& myList = pair.second;
            std::cout << "list " << pair.first << " ";
            std::cout << myList.size() << std::endl;
            for (auto it = myList.begin(); it != myList.end(); ) {
                auto myGO = *it;
                //DestroyObject(myGO);
                bool mb = true;
                if (mb) {
                    it = myList.erase(it);
                    std::cout << "deleted item" << std::endl;

                } else {
                    ++it;
                }
            }
        }
    }

    void MyGame::onGameObjectDestroyed(std::shared_ptr<MyEngine::GameObject> gameObject) {
        MyGame::DestroyObject("Asteroids", gameObject);
    }
*/
}