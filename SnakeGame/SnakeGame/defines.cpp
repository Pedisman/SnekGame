#include "defines.h"

// Const initialised variables
const std::atomic<int> windowWidth = 640;
const std::atomic<int> windowHeight = 640;

const std::atomic<int> xDim = 20;
const std::atomic<int> yDim = 20;

const char loadingScreenText[100] = "Press Enter To Play";

// speed Mapping settings
const std::atomic<int> scoreThreshold = 100;
const std::atomic<int> lowerLimit = 200;
const std::atomic<int> upperLimit = 100;

// Runtime variables
int gameState = MENU_SCREEN;
char scoreText[100] = { '\0' };
int score = 0;
int snakeSpeed = 100;
bool directionLock = false;
int bufferedMove = NO_MOVE;