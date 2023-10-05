#include <Engine/ColliderCircleComponent.h>
#include <cmath>
#include "MyGame.h"
#include "Engine/MyEngine.h"

#include "ComponentController.h"
#include "ComponentRendererSprite.h"

/*
 * hey Chris & TA's
 * I have not documented the code very well. This is simply because I have
 * spent up towards 40 hours on the assignment. So I've learned a lot, but
 * have simply prioritized doing more code instead of documenting.
 * Really hope it's readable for you guys :)
 * Much of it should be readable from method names etc.
 *
 * I tried to do as less as possible in MyGame.cpp and spread it out into other classes
 * but I REALLY find working with subclasses and pointers a b**** in C++. It's really smart,
 * it just doesn't stick with my way of thinking so it takes so LOOONG!
 * But I have tried to extend more components and also extend the ComponentController
 * with a PlayerController class but extending a class that implements an interface
 * was something I couldn't do. Also I tried to make an observer pattern to do callbacks
 * from game objects to an observer, but also this failed. These experiments were interesting
 * - and I would say they should be viable ideas for structuring, so I'm really kind of sad that
 * it didn't work out. I would like to take this up in the exercise classes maybe.
 * For instance my way of deleting lazers after x seconds is just clunky, but I ended up doing
 * it that way because I couldn't make the observer pattern work in C++.
 *
 * if you look at the update function of the ComponentController I use a smoother for the rotation
 * to update it together with the movement direction. This was a hacky way of doing it and I would love some
 * feedback on how I should have done it better.
 *
 * I have just now discovered that I have, for 40 hours lol, completely overlooked the
 * "Trogonometry for Game Programming" link in one of the slides. I have 2 hours til deadline
 * right now, so won't be able to implement any of that, but will start looking at it, look very promising.
 *
 *
 */

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
        lazerParent->shouldRemoveChildrenAfterSeconds = true;
        lazerParent->secondsChildrenWillLive = 1;

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

        auto playerCollider = std::make_shared<MyEngine::ColliderCircleComponent>(10);
        playerObject->AddComponent(playerCollider);
        _colliderPlayer = playerCollider;                    // add to MyGame's collider-list
        return playerObject;
    }

    void MyGame::InstantiateAsteroid() {
        std::shared_ptr<MyEngine::GameObject> asteroidObject =
                instantiateGO("Asteroid", asteroidsParent, "meteorBrown_big1.png", -100);
        asteroidObject->RandomizePosition();
        std::weak_ptr<ExampleGame::ComponentController> asteroidController = GetCC(asteroidObject);
        asteroidController.lock().get()->RandomizeDirection();

        auto asteroidCollider = std::make_shared<MyEngine::ColliderCircleComponent>(50);
        asteroidObject->AddComponent(asteroidCollider);
        _collidersAsteroids.push_back(asteroidCollider);                     // add to MyGame's collider-list
    }

    void MyGame::InstantiateLazer() {
        std::shared_ptr<MyEngine::GameObject> lazerObject =
                instantiateGO("Lazer", lazerParent, "laserBlue05.png", 0);

        std::weak_ptr<ExampleGame::ComponentController> lazerController = GetCC(player);
        auto cc = GetCC(lazerObject).lock();
        if (lazerController.expired()) {
            std::cout << "ComponentController not found!" << std::endl;
        } else {
            auto dir = lazerController.lock()->getMovDirection();
            cc.get()->SetMovementDirection(dir);
            lazerObject.get()->position = player.get()->position;
            lazerObject.get()->rotation = player.get()->rotation;
        }
        cc.get()->SetMovementSpeed(400);

        auto Collider = std::make_shared<MyEngine::ColliderCircleComponent>(3);
        lazerObject->AddComponent(Collider);
        _collidersLazers.push_back(Collider);                     // add to MyGame's collider-list
        //lazerObject.get()->DestroyInSeconds(1.0); //is not working
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
        //std::cout << "created " << name << std::endl;
        std::shared_ptr<MyEngine::GameObject> gameObject = engine.CreateGameObject(name, parent);
        auto componentController = std::shared_ptr<ExampleGame::ComponentController>(
                new ExampleGame::ComponentController(true));
        auto componentRenderer = std::make_shared<ExampleGame::ComponentRendererSprite>();
        gameObject->AddComponent(componentController);
        gameObject->AddComponent(componentRenderer);
        componentRenderer->sprite = atlas->get(_sprite);
        componentController->SetRotationSpeed(rotSpeed);
        componentController->Init();
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
        engine.ProcessEvents(event); //make sure that the game object side of things also get's processed
    }

    void MyGame::Update(float deltaTime) {
        engine.Update(deltaTime);
        CheckCollisions();
    }

    void MyGame::CheckCollisions(){
        for (auto& asteroid : _collidersAsteroids) {
            //std::cout << "checking collission" << std::endl;

            //player check
            //get positions -> find distance
            // check if distance < radius1 + radius2
            auto go = asteroid.lock()->GetGameObject();
            //float distanceToPlayer = std::sqrt(std::pow(player->position.x,go->position.x) + std::pow(player->position.y,go->position.y));
            auto distanceToPlayer = std::sqrt(std::pow(player->position.x - go->position.x, 2) + std::pow(player->position.y - go->position.y, 2));
            bool checkPlayerCollision = distanceToPlayer < (asteroid.lock()->GetRadius() + _colliderPlayer.lock()->GetRadius());

            if(checkPlayerCollision) {
                engine._root->RemoveChildren();
                std::cout << "collision detected" << std::endl;
            }
        }
    }

    void MyGame::Render() {
        engine.Render();
    }

    void MyGame::RemoveAsteroids(){
        asteroidsParent->RemoveChildren();
    }

    //tried my hand at an observer pattern implementation for destruction after xx seconds. Couldn't make it work
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