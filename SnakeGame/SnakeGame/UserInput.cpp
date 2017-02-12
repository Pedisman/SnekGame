#include "UserInput.h"
#include <iostream>
#include "defines.h"
#include "Square.h"
#include "state.h"

pressedKeys myKeys = { false, false, true, false };

void pressedKeys::resetKeys()
{
	left = up = right = down = false;
}

void quitGame(unsigned char key, int x, int y)
{
	if (key == 27)
	{
		exit(0);
	}
	if (key == 13 && myContext.getStateValue() == MENU_SCREEN)
	{
		myContext.setCurrentState(&myGameState);
		resetGame();
	}
}

void arrowKeyPress(int key, int x, int y)
{
	if (!directionLock)
	{
		switch (key)
		{
		case 100:
			if (!myKeys.right)
			{
				myKeys.resetKeys();
				myKeys.left = true;
			}
			break;
		case 101:
			if (!myKeys.down)
			{
				myKeys.resetKeys();
				myKeys.up = true;
			}
			break;
		case 102:
			if (!myKeys.left)
			{
				myKeys.resetKeys();
				myKeys.right = true;
			}
			break;
		case 103:
			if (!myKeys.up)
			{
				myKeys.resetKeys();
				myKeys.down = true;
			}
			break;
		}
		directionLock = true;
	}
	else
	{
		if (key == 100)
		{
			bufferedMove = LEFT;
		}
		else if (key == 101)
		{
			bufferedMove = UP;
		}
		else if (key == 102)
		{
			bufferedMove = RIGHT;
		}
		else if (key == 103)
		{
			bufferedMove = DOWN;
		}
	}
}

//void startGame(unsigned char key, int x, int y)
//{
//	std::cout << int(key) << std::endl;
//}