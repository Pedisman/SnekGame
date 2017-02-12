#ifndef USER_INPUT_h
#define USER_INPUT_h

//enum {LEFT = 0, UP, RIGHT, DOWN};

struct pressedKeys
{
	bool left, up, right, down;

	void resetKeys();
};

extern pressedKeys myKeys;

void quitGame(unsigned char key, int x, int y);
void arrowKeyPress(int key, int x, int y);
//void startGame(unsigned char key, int x, int y);

#endif // USER_INPUT_h
