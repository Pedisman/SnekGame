#include "Square.h"
#include "defines.h"
#include <GL/freeglut.h>
#include "UserInput.h"
#include "textFuncs.h"

Fruit myFruit((xDim/2)*(windowWidth/xDim), (yDim/2)*(windowHeight/yDim), xDim, yDim);
SnakeBody mySnakeBody(xDim, yDim);

// Square

Square::Square(double topLeftX, double topLeftY, double xDim, double yDim)
{
	this->topLeftX = topLeftX;
	this->topLeftY = topLeftY;
	this->xDim = xDim;
	this->yDim = yDim;
}

bool Square::collide(const Square* inputSquare) const
{
	if (topLeftX >= inputSquare->topLeftX + windowWidth / inputSquare->xDim ||
		topLeftX + windowWidth / xDim <= inputSquare->topLeftX ||
		topLeftY >= inputSquare->topLeftY + windowHeight / inputSquare->yDim ||
		topLeftY + windowHeight/yDim <= inputSquare->topLeftY)
	{
		return false;
	}
	return true;
}

////// Snake Square

void SnakeSquare::updateSquare(const pressedKeys &myKeys)
{
	if (myKeys.left)
	{
		topLeftX -= windowWidth / xDim;
	}
	else if (myKeys.up)
	{
		topLeftY -= windowHeight / yDim;
	}
	else if (myKeys.right)
	{
		topLeftX += windowWidth / xDim;
	}
	else if (myKeys.down)
	{
		topLeftY += windowHeight / yDim;
	}
	directionLock = false;
}

void SnakeSquare::drawSquare() const
{
	glBegin(GL_QUADS);

	glColor3d(1, 0, 0);

	glVertex2d(topLeftX, topLeftY);
	glVertex2d(topLeftX + windowWidth/xDim, topLeftY);
	glVertex2d(topLeftX + windowWidth/xDim, topLeftY + windowHeight/yDim);
	glVertex2d(topLeftX, topLeftY + windowHeight/yDim);

	glEnd();
}

void SnakeSquare::copySnakeSquare(const SnakeSquare &inputSnakeSquare)
{
	this->topLeftX = inputSnakeSquare.topLeftX;
	this->topLeftY = inputSnakeSquare.topLeftY;
}

bool SnakeSquare::operator==(const SnakeSquare &inputSnakeSquare) const
{
	if (topLeftX == inputSnakeSquare.topLeftX && topLeftY == inputSnakeSquare.topLeftY)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/////// Fruit

void Fruit::drawSquare() const
{
	glBegin(GL_QUADS);

	glColor3d(0, 1, 0);

	glVertex2d(topLeftX, topLeftY);
	glVertex2d(topLeftX + windowWidth / xDim, topLeftY);
	glVertex2d(topLeftX + windowWidth / xDim, topLeftY + windowHeight / yDim);
	glVertex2d(topLeftX, topLeftY + windowHeight / yDim);

	glEnd();
}

void Fruit::randomlyGenerateNewLocation(SnakeBody& inputSnakeBody)
{
	while (inputSnakeBody.collide(this))
	{
		topLeftX = (rand() % int(xDim))*(windowWidth / xDim);
		topLeftY = (rand() % int(yDim))*(windowHeight / yDim);
	}
}


////// Snake Body
void SnakeBody::addSnakePart(SnakeSquare inputSnakeSquare)
{
	snakeBody.push_back(inputSnakeSquare);
}

void SnakeBody::moveSnake()
{
	static SnakeSquare prevSnakeSquare;
	static SnakeSquare currentSnakeSquare;
	if (snakeBody.size() > 1)
	{
		for (int i = 0; i < snakeBody.size(); ++i)
		{
			currentSnakeSquare.copySnakeSquare(snakeBody[i]);
			if (i == 0)
			{
				snakeBody[i].updateSquare(myKeys);
			}
			else
			{
				snakeBody[i].copySnakeSquare(prevSnakeSquare);
			}
			prevSnakeSquare.copySnakeSquare(currentSnakeSquare);
		}
	}
	else
	{
		snakeBody[0].updateSquare(myKeys);
	}
}

void SnakeBody::drawSnakeBody() const
{
	for (int i = 0; i < snakeBody.size(); ++i)
	{
		snakeBody[i].drawSquare();
	}
}

bool SnakeBody::collide(const Square* inputSquare) const
{
	for (int i = 0; i < snakeBody.size(); ++i)
	{
		if (snakeBody[i].collide(inputSquare))
		{
			return true;
		}
	}
	return false;
}

bool SnakeBody::collideWithSelf()
{
	static std::vector<SnakeSquare> snakeSet;
	snakeSet.clear();
	for (int i = 0; i < snakeBody.size(); ++i)
	{
		bool exist = false;
		for (int j = 0; j < snakeSet.size(); ++j)
		{
			if (snakeBody[i] == snakeSet[j])
			{
				exist = true;
			}
		}
		if (!exist)
		{
			snakeSet.push_back(snakeBody[i]);
		}
	}

	return snakeSet.size() < snakeBody.size();
}


void SnakeBody::collectedFruit()
{
	if (this->collide(&myFruit))
	{
		this->addSnakePart(SnakeSquare(snakeBody[0].topLeftX,
						snakeBody[0].topLeftY,
						snakeBody[0].xDim,
						snakeBody[0].yDim));
		myFruit.randomlyGenerateNewLocation(*this);
		score += 10;
		updateScoreText(scoreText, score);
	}
}

void SnakeBody::resetSnake(int xDim, int yDim)
{
	int topLeftX = (rand() % int(xDim))*(windowWidth / xDim);
	int topLeftY = (rand() % int(yDim))*(windowHeight / yDim);
	snakeBody.clear();
	addSnakePart(SnakeSquare(topLeftX, topLeftY, xDim, yDim));
}

bool SnakeBody::outsideArena()
{
	if (snakeBody[0].topLeftX >= windowWidth ||
		snakeBody[0].topLeftX + windowWidth / xDim <= 0 ||
		snakeBody[0].topLeftY >= windowHeight ||
		snakeBody[0].topLeftY + windowHeight / yDim <= 0)
	{
		return true;
	}
	return false;
}

// global functions
void resetGame()
{
	mySnakeBody.resetSnake(xDim, yDim);
	myFruit.randomlyGenerateNewLocation(mySnakeBody);
	score = 0;
	updateScoreText(scoreText, score);
}