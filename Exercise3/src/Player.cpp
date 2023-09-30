#include "MyGame.h"
#include "ITUGames.h"

void Player::processEvents(){
	Player::ChangePosition(GameEngine::UserInputReader());
}

void Player::Update(){
	Player::Switch();
}

void Player::ChangePosition(char input){
	//++frame;	//look into this
	prevCursorPositionX = cursorPositionX;
	prevCursorPositionY = cursorPositionY;
	switch (input)
	{
	case ITUGames::Console::KEY_A:
		cursorPositionX -= 1;
		break;
	case ITUGames::Console::KEY_D:
		cursorPositionX += 1;
		break;
	case ITUGames::Console::KEY_W:
		cursorPositionY -= 1;
		break;
	case ITUGames::Console::KEY_S:
		cursorPositionY += 1;
		break;
	default:
		break;
	}
	//playerAnimationFrame = (frame/60) % 2; //look into this
}

void Player::Switch(){
	player_clock_switch = std::chrono::steady_clock::now() - player_clock_checkpoint;
	if(player_clock_switch.count() > 0.5){
		if(PlayerCharacterState == '0'){
			PlayerCharacterState = 'O';
		}
		else {
			PlayerCharacterState = '0';
		}	
		player_clock_switch.zero();
		player_clock_checkpoint = std::chrono::steady_clock::now();
	}
}

void Player::Init(){
	cursorPositionX = 20; cursorPositionY = 10;
	player_clock_checkpoint = std::chrono::steady_clock::now();
	PlayerCharacterState = '0';
}

void Player::Render(){
	ITUGames::Console::GotoCoords(prevCursorPositionX, prevCursorPositionY);
	ITUGames::Console::ClearLine();
	ITUGames::Console::GotoCoords(cursorPositionX, cursorPositionY);
	ITUGames::Console::RenderCharacter(PlayerCharacterState);
}
