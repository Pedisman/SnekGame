#include "TimerFunctions.h"
#include "Square.h"
#include <GL/freeglut.h>
#include "state.h"

void updateSquareMotion(int te)
{
	if (myContext.getStateValue() == GAME)
	{
		// Order matters here
		updateBufferedMove(bufferedMove);
		mySnakeBody.collectedFruit();
		mySnakeBody.moveSnake();
		if (mySnakeBody.collideWithSelf() || mySnakeBody.outsideArena())
		{
			myContext.setCurrentState(&myMenuState);
		}
	}
	snakeSpeed = speedMappingFunc(score);
	glutTimerFunc(snakeSpeed, updateSquareMotion, 1);
}

int speedMappingFunc(int inputScore)
{
	return (inputScore < scoreThreshold) ? lowerLimit - ((lowerLimit - upperLimit) * inputScore / scoreThreshold) : upperLimit;
}

void updateBufferedMove(int &bufferedMove)
{
	if (!directionLock)
	{
		switch (bufferedMove)
		{
		case LEFT:
			if (!myKeys.right)
			{
				myKeys.resetKeys();
				myKeys.left = true;
			}
			break;
		case UP:
			if (!myKeys.down)
			{
				myKeys.resetKeys();
				myKeys.up = true;
			}
			break;
		case RIGHT:
			if (!myKeys.left)
			{
				myKeys.resetKeys();
				myKeys.right = true;
			}
			break;
		case DOWN:
			if (!myKeys.up)
			{
				myKeys.resetKeys();
				myKeys.down = true;
			}
			break;
		}
		bufferedMove = NO_MOVE;
	}
}
