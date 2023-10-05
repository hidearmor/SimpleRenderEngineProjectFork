#pragma once
#include "Component.h"
#include "MyEngine.h"

namespace MyEngine {
    class ColliderCircleComponent : public Component {
    public:
        ColliderCircleComponent(float radius);
        float GetRadius();

    private:
        float _radius;
    };
}
