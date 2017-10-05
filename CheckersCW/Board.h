#ifndef BOARD_H_GUARD
#define BOARD_H_GUARD
#include <iostream>
#include <Enum.h>


class CheckersBoard
{
public:
	void copyArrayInto(CheckerEnum input[8][8], CheckerEnum output[8][8]);
	

	CheckerEnum CurrentBoardState[8][8];
	void makeMove();
	void resetBoard(); //Returns board to starting state

	void PrintBoard();

	void initStartingBoardState();
	bool isValidMove(CheckerEnum CurrentTurnColour, Coord StartingCoord, Coord RequestedCoord);

	Coord* AvailableMoves(Coord CurrentCoord);

	CheckerEnum WinnerFound();

	CheckersBoard();

};
#endif