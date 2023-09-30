#include <iostream>
#include <chrono>
#include <random>
#include <list> 
#include <string>
#include "ITUGames.h"
#include "MyGame.h"

using std::string;

// --> C++ is forward declarative, from top to bottom, so main needs to know about these methods to use them

int main() {
	GameEngine ge = GameEngine();
    Player player = Player();

	ge.Init();
	player.Init();

	while(!GameEngine::GetQuit()){
		ge.time_start = std::chrono::steady_clock::now();

		// processEvents(); 	// inputReader -> change Position
		ge.ProcessEvents(); player.processEvents();
		ge.Update();		player.Update();	//should do switch
		ge.Render();		player.Render();	// should spawn player

		// check how long stuff took
		ge.time_end = std::chrono::steady_clock::now();
		ge.time_elapsed = ge.time_end - ge.time_start;

		// do the sleep
		double sleep_time = ge.target_frame_time - (ge.time_elapsed).count();	// slep for correct amount of time
		ITUGames::Utils::PreciseSleep(std::chrono::duration<double>(sleep_time));

		ge.time_end_after_sleep = std::chrono::steady_clock::now();
		ge.time_elapsed_after_sleep = ge.time_end_after_sleep - ge.time_start;
		ge.DisplayStatistics(ge.time_elapsed_after_sleep.count(), ge.time_elapsed.count());

		// time_end = time_start;
	}

	return 0;
}


