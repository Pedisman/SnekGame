#include "textFuncs.h"
#include <GL/freeglut.h>
#include <stdio.h>
#include "Square.h"

void displayText(const char* inputText, int x, int y)
{
	glColor3d(1, 1, 1);
	glRasterPos2i(x, y); // location to start printing text

	for (int i = 0; inputText[i] != '\0'; ++i)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, inputText[i]);
	}
}

void updateScoreText(char* scoreText, int score)
{
	sprintf(scoreText, "Score: %d", score);
}