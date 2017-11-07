#include "CheckersBoard.h"


CheckersBoard::CheckersBoard()
{
	bool playerTurn = 0;
	int redGrave = 0;
	int wteGrave = 0;
	this->resetBoard();
}


CheckersBoard::~CheckersBoard()
{
}

const CheckerEnum CheckersBoard::FreshBoard[8][8] = { { UnusedSpace, WteChecker, UnusedSpace, WteChecker, UnusedSpace, WteChecker, UnusedSpace, WteChecker },//WteChecker =1
													{ WteChecker, UnusedSpace, WteChecker, UnusedSpace, WteChecker, UnusedSpace, WteChecker, UnusedSpace },//WteKing =1
													{ UnusedSpace, WteChecker, UnusedSpace, WteChecker, UnusedSpace, WteChecker, UnusedSpace, WteChecker },
													{ FreeSpace, UnusedSpace, FreeSpace, UnusedSpace, FreeSpace, UnusedSpace, FreeSpace, UnusedSpace },
													{ UnusedSpace, FreeSpace, UnusedSpace, FreeSpace, UnusedSpace, FreeSpace, UnusedSpace, FreeSpace },
													{ RedChecker, UnusedSpace, RedChecker, UnusedSpace, RedChecker, UnusedSpace, RedChecker, UnusedSpace },
													{ UnusedSpace, RedChecker, UnusedSpace, RedChecker, UnusedSpace, RedChecker, UnusedSpace, RedChecker },
													{ RedChecker, UnusedSpace, RedChecker, UnusedSpace, RedChecker, UnusedSpace, RedChecker, UnusedSpace }
													};
														/*FreeSpace,//0
															WteChecker,//1
															WteKing,//2
															RedChecker,//3
															RedKing,//4
															UnusedSpace//5*/
CheckerEnum CurrentGameBoard[8][8];
Coord movement[2] = { Coord(-1, 1), Coord(1, 1) };//Take these numbers at minus for red movement

void CheckersBoard::printBoard()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (this->CurrentGameBoard[i][j] != UnusedSpace)
			{
				std::cout << this->CurrentGameBoard[i][j] << " ";
			}
			else
			{
				std::cout << "0 ";
			}
		}
		std::cout << std::endl;
	}
}
void CheckersBoard::resetBoard()
{
	std::copy(&this->FreshBoard[0][0], &this->FreshBoard[0][0] + (8 * 8), &this->CurrentGameBoard[0][0]);
}

std::vector<Coord> CheckersBoard::getPiecesWithValidMoves() //Thinking about passing back somethign else with the coords of pieces that can move
{
	if (this->playerTurn)//If white turn check for white pieces that can move
	{
		std::vector<Coord> MoveablePieces;
		
	} 
}

std::vector<Moves> CheckersBoard::generateCurrentPlayerMoves()
{
	//For Coords were pieces can move - calls function that returns vector of coords
	if (this->playerTurn)//If White turn
	{
		//Call function that returns all white pieces that can move

		/*if()//IF any of the pieces can jump Continue to work with them. Player must make a jump and take a piece
		{

		}
		*/
	}
	
}
