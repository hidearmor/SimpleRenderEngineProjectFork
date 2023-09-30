#pragma once

#include <memory>

namespace MyEngine {
    class GameObject;

    class Observer {
    public:
        virtual void onGameObjectDestroyed(std::shared_ptr<GameObject> gameObject) = 0;
    };
}
