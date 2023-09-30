#include "MyGame.h"
#include "ITUGames.h"

void GameObject::Init(){

}

void GameObject::Update(){
    GameObject::LongComputation();
}

void GameObject::Render(){
    
}

void GameObject::LongComputation()
{
	// get a random number between 0.01 and 0.016
	double sleep_time = (10 + std::rand() % 6) / 1000.0;
	ITUGames::Utils::PreciseSleep(std::chrono::duration<double>(sleep_time));
}