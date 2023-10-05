#pragma once
#include "Component.h"

namespace MyEngine {
    class ColliderCircleComponent : public Component {
    public:
        ColliderCircleComponent(float radius);

    private:
        float _radius;
    };
}
