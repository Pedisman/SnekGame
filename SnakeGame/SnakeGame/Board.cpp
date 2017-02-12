#include "Board.h"
#include <GL/freeglut.h>
#include "defines.h"

void drawBox(double topLeftX, double topLeftY, int xSize, int ySize)
{
	glBegin(GL_QUADS);
	
	// red color for now
	glColor3d(1, 0, 0);

	glVertex2d(topLeftX, topLeftY);
	glVertex2d(topLeftX + xSize, topLeftY);
	glVertex2d(topLeftX + xSize, topLeftY + ySize);
	glVertex2d(topLeftX, topLeftY + ySize);
	
	glEnd();
}

// Only declare default parameters in declaration not definition
Board::Board(int xSize, int ySize, int* array)
{
	this->xSize = xSize;
	this->ySize = ySize;
	boardArray = new int[xSize*ySize];

	if (array)
	{
		for (int i = 0; i < xSize*ySize; ++i)
		{
			boardArray[i] = array[i];
		}
	}
	else
	{
		memset(boardArray, 0, xSize*ySize);
	}
}

void Board::setBitMap(int* array)
{
	if (array)
	{
		for (int i = 0; i < xSize*ySize; ++i)
		{
			boardArray[i] = array[i];
		}
	}
}

void Board::drawBoard() const
{
	for (int i = 0; i < xSize*ySize; ++i)
	{
		if (boardArray[i] > 0)
		{
			drawBox((i % xSize)*(windowWidth / xSize), (i / ySize)*(windowHeight / ySize), (windowWidth / xSize), (windowHeight / ySize));
		}
	}
}


Board::~Board()
{
	// only freeing the memory if we allocated it
	if (boardArray)
	{
		delete[] boardArray;
	}
}
