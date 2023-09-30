#include "GameEngine.h"
#include "ITUGames.h"

#include <chrono>
#include <random>

void GameEngine::Init(){
	quit_flag = false;
	// initialize random generator
	std::srand(std::time(nullptr)); 
	// cleans the terminal and prepares it for interactive input
	ITUGames::Console::InitScreenForRendering();
	ITUGames::Console::HideCursor();
}

void GameEngine::Update(){

} //this is an implementation

/*
; the semicolon ; ends a statement, we don't need it here- and different compilers
interpret it differently, so don't put it if it's not needed

void GameEngine::Update(); here I'm basically redefining
*/

void GameEngine::Render(){

}

bool GameEngine::ProcessEvents(){
	bool result = true;
	return result;
}

char GameEngine::UserInputReader(){
	char input = ITUGames::Console::GetCharacter(false);
	if(input == 'q')
	{
		GameEngine::Quit();
	}
	return input;
}

void GameEngine::DisplayStatistics(double frame_time, double comp_time){
	ITUGames::Console::GotoTop();
	std::cout << "Computation time : " << comp_time << std::endl;
	std::cout << "Target elapsed: " << target_frame_time << std::endl;
	std::cout << "Elapsed : " << frame_time << std::endl;
	std::cout << "Target FPS: " << target_FPS << std::endl;
	std::cout << "FPS     : " << 1.0/ frame_time << std::endl;
}

void GameEngine::Quit(){
	quit_flag = true;
}

bool GameEngine::GetQuit(){
	return quit_flag;
}
