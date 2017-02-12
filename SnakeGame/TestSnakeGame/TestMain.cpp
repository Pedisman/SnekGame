#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "Board.h"
#include "defines.h"
#include "Square.h"
#include "state.h"
#include "textFuncs.h"
#include "TimerFunctions.h"
#include "UserInput.h"

//int main()
//{
//	SnakeSquare m_snake_square(0, 0, 10, 10);
//	return 0;
//}

TEST_CASE("Test collision", "[Collision test]")
{
	const int xDim = 10;
	const int yDim = 10;
	SnakeSquare sq1(0, 0, xDim, yDim);
	SnakeSquare sq2(windowWidth/xDim, windowHeight/yDim, xDim, yDim);
	SnakeSquare sq3(0, 0, xDim, yDim);
	REQUIRE(sq1.collide(&sq2) == false);
	REQUIRE(sq1.collide(&sq3) == true);
}