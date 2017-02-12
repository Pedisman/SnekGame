#include <GL/freeglut.h>
#include "defines.h"
#include "Board.h"
#include "UserInput.h"
#include "Square.h"
#include "TimerFunctions.h"
#include "textFuncs.h"
#include "state.h"
#include "mmsystem.h"

void render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluOrtho2D(0, windowWidth, windowHeight, 0);

	// Drawing functions go here
	myContext.displayAction();
	glutSwapBuffers();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(windowWidth, windowHeight);
	glutCreateWindow("Game window");

	// only register up and down events not hold
	glutIgnoreKeyRepeat(1);

	// Register callback functions
	glutDisplayFunc(render);
	glutIdleFunc(render);

	// Register keyboard functions
	glutKeyboardFunc(quitGame);
	//glutKeyboardFunc(startGame);
	glutSpecialFunc(arrowKeyPress);

	// Register timer functions
	glutTimerFunc(snakeSpeed, updateSquareMotion, 1);

	PlaySound(".//gameSound.wav", nullptr, SND_ASYNC | SND_FILENAME | SND_LOOP);

	glutMainLoop();
	return 0;
}