#ifndef DEFINES_h
#define DEFINES_h
#include <atomic>

// Display settings
extern const std::atomic<int> windowHeight;
extern const std::atomic<int> windowWidth;

extern const std::atomic<int> xDim;
extern const std::atomic<int> yDim;

extern const char loadingScreenText[100];

// Speed mapping settings
extern const std::atomic<int> scoreThreshold;
extern const std::atomic<int> lowerLimit;
extern const std::atomic<int> upperLimit;

// enums
enum {NO_MOVE = 0, LEFT, UP, RIGHT, DOWN};
enum { MENU_SCREEN = 0, GAME};

// global variables

extern int gameState;
extern int score;
extern char scoreText[100];
extern int snakeSpeed;
extern bool directionLock;
extern int bufferedMove;

#endif // DEFINES_h