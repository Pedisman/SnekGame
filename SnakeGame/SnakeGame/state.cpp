#include "state.h"
#include "Square.h"
#include "textFuncs.h"

GameState myGameState;
MenuState myMenuState;
Context myContext(&myMenuState);

///// State class

int State::getStateValue() const
{
	return stateValue;
}

///// Context class definitions

Context::Context(State* state)
{
	currentState = state;
}

int Context::getStateValue() const
{
	return currentState->getStateValue();
}


void Context::setCurrentState(State* state)
{
	currentState = state;
}

void Context::displayAction() const
{
	currentState->displayAction();
}

/////// State action definitions

MenuState::MenuState()
{
	stateValue = MENU_SCREEN;
}

GameState::GameState()
{
	stateValue = GAME;
}

void MenuState::displayAction()
{
	displayText(loadingScreenText, 220, 320);
}

void GameState::displayAction()
{
	myFruit.drawSquare();
	mySnakeBody.drawSnakeBody();
	displayText(scoreText, 10, 40);
}