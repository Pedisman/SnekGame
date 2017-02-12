#ifndef SQUARE_h
#define SQUARE_h
#include "defines.h"
#include "UserInput.h"
#include <vector>
#include <time.h>

class Square
{
public:
	double topLeftX, topLeftY;
	double xDim, yDim;

	Square(double topLeftX, double topLeftY, double xDim, double yDim);

	bool collide(const Square* inputSquare) const;

	virtual void drawSquare() const {}
	virtual ~Square(){}
};

class SnakeSquare : public Square
{
public:
	SnakeSquare(double topLeftX = -1, double topLeftY = -1, double xDim = -1, double yDim= -1) :
		Square(topLeftX, topLeftY, xDim, yDim){}

	void drawSquare() const override;

	void copySnakeSquare(const SnakeSquare &inputSnakeSquare);

	void updateSquare(const pressedKeys &myKeys);

	bool operator==(const SnakeSquare &inputSnakeSquare) const;
};

class SnakeBody;

class Fruit : public Square
{
public:
	Fruit(double topLeftX, double topLeftY, double xDim, double yDim) :
		Square(topLeftX, topLeftY, xDim, yDim)
	{
		srand(time(nullptr));
	}

	void randomlyGenerateNewLocation(SnakeBody &inputSnakeBody);
	void drawSquare() const override;
};

class SnakeBody
{
	std::vector<SnakeSquare> snakeBody;
public:
	SnakeBody(int xDim, int yDim)
	{
		resetSnake(xDim, yDim);
	}

	SnakeBody(const SnakeSquare &inputSnakeSquare)
	{
		//srand(time(nullptr));
		addSnakePart(inputSnakeSquare);
	}

	void addSnakePart(SnakeSquare inputSnakeSquare);
	void moveSnake();
	void drawSnakeBody() const;
	void collectedFruit();
	bool collide(const Square* inputSquare) const;
	bool collideWithSelf();
	void resetSnake(int xDim, int yDim);
	bool outsideArena();
};

extern void resetGame();

extern SnakeBody mySnakeBody;
extern SnakeSquare mySquare;
extern Fruit myFruit;

#endif // SQUARE_h