#pragma once

#include <list>
#include <chrono>
#include "GameEngine.h"


class Game{

};

class Component {
// public:
    void Init();
    void Update();
    void Render();
};

class GameObject {
// public:
    // int pos_x;
    // int pos_y;

    // std::list<Component> components;
    // std::list<GameObject> GameObjects;

    public: 
        void Init();
        void Update();
        void Render();
    void LongComputation();
};

class Player{
    std::chrono::time_point<std::chrono::steady_clock> player_clock_checkpoint;
    std::chrono::duration<double> player_clock_switch; 
    char PlayerCharacterState;  
    int cursorPositionX;
    int cursorPositionY;
    int prevCursorPositionX;
    int prevCursorPositionY;
    public: 
        void Init();
        void processEvents();
        void Update();
        void Render();
    void ChangePosition(char input);
    void Switch();
};