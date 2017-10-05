#include "Board.h"
#include <iostream>
#include <iterator>
/*
CheckerEnum StartingBoard[8][8] = { { UnusedSpace, WteChecker, UnusedSpace, WteChecker, UnusedSpace, WteChecker, UnusedSpace, WteChecker },
{ WteChecker, UnusedSpace, WteChecker, UnusedSpace, WteChecker, UnusedSpace, WteChecker, UnusedSpace },
{ UnusedSpace, WteChecker, UnusedSpace, WteChecker, UnusedSpace, WteChecker, UnusedSpace, WteChecker },
{ FreeSpace, UnusedSpace, FreeSpace, UnusedSpace, FreeSpace, UnusedSpace, FreeSpace, UnusedSpace },
{ UnusedSpace, FreeSpace, UnusedSpace, FreeSpace, UnusedSpace, FreeSpace, UnusedSpace, FreeSpace },
{ RedChecker, UnusedSpace, RedChecker, UnusedSpace, RedChecker, UnusedSpace, RedChecker, UnusedSpace },
{ UnusedSpace, RedChecker, UnusedSpace, RedChecker, UnusedSpace, RedChecker, UnusedSpace, RedChecker },
{ RedChecker, UnusedSpace, RedChecker, UnusedSpace, RedChecker, UnusedSpace, RedChecker, UnusedSpace }
};

CheckerEnum CurrentBoardState[8][8] = { { UnusedSpace, WteChecker, UnusedSpace, WteChecker, UnusedSpace, WteChecker, UnusedSpace, WteChecker },
{ WteChecker, UnusedSpace, WteChecker, UnusedSpace, WteChecker, UnusedSpace, WteChecker, UnusedSpace },
{ UnusedSpace, WteChecker, UnusedSpace, WteChecker, UnusedSpace, WteChecker, UnusedSpace, WteChecker },
{ FreeSpace, UnusedSpace, FreeSpace, UnusedSpace, FreeSpace, UnusedSpace, FreeSpace, UnusedSpace },
{ UnusedSpace, FreeSpace, UnusedSpace, FreeSpace, UnusedSpace, FreeSpace, UnusedSpace, FreeSpace },
{ RedChecker, UnusedSpace, RedChecker, UnusedSpace, RedChecker, UnusedSpace, RedChecker, UnusedSpace },
{ UnusedSpace, RedChecker, UnusedSpace, RedChecker, UnusedSpace, RedChecker, UnusedSpace, RedChecker },
{ RedChecker, UnusedSpace, RedChecker, UnusedSpace, RedChecker, UnusedSpace, RedChecker, UnusedSpace }
};
enum CheckerEnum
{
FreeSpace,//0
WteChecker,//1
WteKing,//2
RedChecker,//3
RedKing,//4
UnusedSpace//5
};
*/
/*
CheckersBoard CheckersBoard::CurrentBoardState[8][8] = {
{ UnusedSpace, WteChecker, UnusedSpace, WteChecker, UnusedSpace, WteChecker, UnusedSpace, WteChecker },
{ WteChecker, UnusedSpace, WteChecker, UnusedSpace, WteChecker, UnusedSpace, WteChecker, UnusedSpace },
{ UnusedSpace, WteChecker, UnusedSpace, WteChecker, UnusedSpace, WteChecker, UnusedSpace, WteChecker },
{ FreeSpace, UnusedSpace, FreeSpace, UnusedSpace, FreeSpace, UnusedSpace, FreeSpace, UnusedSpace },
{ UnusedSpace, FreeSpace, UnusedSpace, FreeSpace, UnusedSpace, FreeSpace, UnusedSpace, FreeSpace },
{ RedChecker, UnusedSpace, RedChecker, UnusedSpace, RedChecker, UnusedSpace, RedChecker, UnusedSpace },
{ UnusedSpace, RedChecker, UnusedSpace, RedChecker, UnusedSpace, RedChecker, UnusedSpace, RedChecker },
{ RedChecker, UnusedSpace, RedChecker, UnusedSpace, RedChecker, UnusedSpace, RedChecker, UnusedSpace }
};

class CheckersBoard
{
enum CheckerEnum
{
FreeSpace,//0
WteChecker,//1
WteKing,//2
RedChecker,//3
RedKing,//4
UnusedSpace//5
};
public:
CheckerEnum StartingBoard[8][8] = {
{ UnusedSpace, WteChecker, UnusedSpace, WteChecker, UnusedSpace, WteChecker, UnusedSpace, WteChecker },
{ WteChecker, UnusedSpace, WteChecker, UnusedSpace, WteChecker, UnusedSpace, WteChecker, UnusedSpace },
{ UnusedSpace, WteChecker, UnusedSpace, WteChecker, UnusedSpace, WteChecker, UnusedSpace, WteChecker },
{ FreeSpace, UnusedSpace, FreeSpace, UnusedSpace, FreeSpace, UnusedSpace, FreeSpace, UnusedSpace },
{ UnusedSpace, FreeSpace, UnusedSpace, FreeSpace, UnusedSpace, FreeSpace, UnusedSpace, FreeSpace },
{ RedChecker, UnusedSpace, RedChecker, UnusedSpace, RedChecker, UnusedSpace, RedChecker, UnusedSpace },
{ UnusedSpace, RedChecker, UnusedSpace, RedChecker, UnusedSpace, RedChecker, UnusedSpace, RedChecker },
{ RedChecker, UnusedSpace, RedChecker, UnusedSpace, RedChecker, UnusedSpace, RedChecker, UnusedSpace }
};
CheckersBoard CheckersBoard::CurrentBoardState[8][8] = {
{ UnusedSpace, WteChecker, UnusedSpace, WteChecker, UnusedSpace, WteChecker, UnusedSpace, WteChecker },
{ WteChecker, UnusedSpace, WteChecker, UnusedSpace, WteChecker, UnusedSpace, WteChecker, UnusedSpace },
{ UnusedSpace, WteChecker, UnusedSpace, WteChecker, UnusedSpace, WteChecker, UnusedSpace, WteChecker },
{ FreeSpace, UnusedSpace, FreeSpace, UnusedSpace, FreeSpace, UnusedSpace, FreeSpace, UnusedSpace },
{ UnusedSpace, FreeSpace, UnusedSpace, FreeSpace, UnusedSpace, FreeSpace, UnusedSpace, FreeSpace },
{ RedChecker, UnusedSpace, RedChecker, UnusedSpace, RedChecker, UnusedSpace, RedChecker, UnusedSpace },
{ UnusedSpace, RedChecker, UnusedSpace, RedChecker, UnusedSpace, RedChecker, UnusedSpace, RedChecker },
{ RedChecker, UnusedSpace, RedChecker, UnusedSpace, RedChecker, UnusedSpace, RedChecker, UnusedSpace }
};
CheckersBoard::CheckersBoard()
{
}

void CheckersBoard::clearBoard()
{
for (int i = 0; i < 8; i++)
{
for (int j = 0; j < 8; j++)
this->CurrentBoardState[i][j] = this->StartingBoard[i][j];
}
}

void CheckersBoard::PrintBoard()
{
for (int i = 0; i < 8; i++)
{
for (int j = 0; j < 8; j++)
{
std::cout << this->CurrentBoardState;
std::cout << std::endl;
}
}
}



};
*/

void CheckersBoard::copyArrayInto(CheckerEnum input[8][8], CheckerEnum output[8][8])
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
			this->CurrentBoardState[i][j] = input[i][j];
	}
}
/*void CheckersBoard::resetBoard()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
			this->CurrentBoardState[i][j] = this->StartingBoardState[i][j];
	}
}*/

void CheckersBoard::PrintBoard()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			std::cout << this->CurrentBoardState[i][j];
		}
		std::cout << std::endl;
	}
}
CheckerEnum CheckersBoard::WinnerFound()//Assess board for winner. If found return pieces that have won
{
	int WteCount, RedCount;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (CurrentBoardState[i][j] == WteChecker)
				WteCount++;
			else if (CurrentBoardState[i][j] == RedChecker)
				RedCount++;
		}
		//If one player has no pieces left then they have lost, return opposite colour as winner
		if (WteChecker == 0)
			return RedChecker;
		if (RedChecker == 0)
			return WteChecker;
		else
			return UnusedSpace;//If no winner return unused space
		/*Will be expanded further to assess board for other winning state,i.e enemy cannot make a move*/
	}
}

bool CheckersBoard::isValidMove(CheckerEnum CurrentTurnColour, Coord StartingCoord, Coord RequestedCoord)
{
	if (CurrentTurnColour == RedChecker)//If RedCHecker Check the sqaures Above and to its left, right
	{
		if (this->CurrentBoardState[StartingCoord.x - 1][StartingCoord.y - 1] == FreeSpace ||
			this->CurrentBoardState[StartingCoord.x - 1][StartingCoord.y + 1] == FreeSpace)
				return true;
	}
}
void CheckersBoard::makeMove()//if move has been marked as valid, execute it
/*Only to be called after move is validated, call isValideMove. After move is made check for 
other checkers that must be taken during the move.*/
{

}
CheckersBoard::CheckersBoard()
{

	
}