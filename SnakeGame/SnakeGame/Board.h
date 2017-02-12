#ifndef BOARD_h
#define BOARD_h

void drawBox(double topLeftX, double topLeftY, int xSize, int ySize);

class Board
{
	// initializing as null
	int* boardArray = nullptr;
	int xSize, ySize;
public:
	Board(int xSize, int ySize, int* array = nullptr);

	void setBitMap(int* array);

	void drawBoard() const;

	~Board();
};

#endif // BOARD_h