#pragma once
// #include "ITUGames.h" //is included in cpp

#include <iostream>
#include <chrono>
#include <cstdlib>
#include <random>

static bool quit_flag;
class GameEngine{
    public:
        std::chrono::time_point<std::chrono::steady_clock>	time_start;
        std::chrono::time_point<std::chrono::steady_clock>	time_end;
        std::chrono::time_point<std::chrono::steady_clock>	time_end_after_sleep;
        std::chrono::duration<double>						time_elapsed;
        std::chrono::duration<double>						time_elapsed_after_sleep;
        double target_FPS = 60.0;
        double target_frame_time = 1.0 / target_FPS;;
        int frame = 0;

        unsigned char input = -1;
        bool show_debug_window;

    public:
        void Init();
        void Update();
        void Render();
        bool ProcessEvents();
        static char UserInputReader();
        static void Quit();
        static bool GetQuit();
        void DisplayStatistics(double frame_time, double comp_time);
};
