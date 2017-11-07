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

const CheckerEnum FreshBoard[8][8] = { 
													  { UnusedSpace, RedChecker, UnusedSpace, RedChecker, UnusedSpace, RedChecker, UnusedSpace, RedChecker },
													  { RedChecker, UnusedSpace, RedChecker, UnusedSpace, RedChecker, UnusedSpace, RedChecker, UnusedSpace },
													  { UnusedSpace, RedChecker, UnusedSpace, RedChecker, UnusedSpace, RedChecker, UnusedSpace, RedChecker },
													  { FreeSpace, UnusedSpace, FreeSpace, UnusedSpace, FreeSpace, UnusedSpace, FreeSpace, UnusedSpace },
													  { UnusedSpace, FreeSpace, UnusedSpace, FreeSpace, UnusedSpace, FreeSpace, UnusedSpace, FreeSpace },
													  { WteChecker, UnusedSpace, WteChecker, UnusedSpace, WteChecker, UnusedSpace, WteChecker, UnusedSpace },
													  { UnusedSpace, WteChecker, UnusedSpace, WteChecker, UnusedSpace, WteChecker, UnusedSpace, WteChecker },
													  { WteChecker, UnusedSpace, WteChecker, UnusedSpace, WteChecker, UnusedSpace, WteChecker, UnusedSpace }
													};
														/*FreeSpace,//0
															WteChecker,//1
															WteKing,//2
															RedChecker,//3
															RedKing,//4
															UnusedSpace//5*/

CheckerEnum CurrentGameBoard[8][8];
Coord movement[2] = { Coord(-1, 1), Coord(1, 1) };//Take y times negative for red movement

void CheckersBoard::printBoard()
{
	std::cout << "*   1 2 3 4 5 6 7 8" << std::endl;
	std::cout << "   __________________" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		std::cout << i << "  |";
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
CheckerEnum CheckersBoard::inspectSpace(Coord square)
{
	return this->CurrentGameBoard[square.x][square.y];
}

std::vector<Move> CheckersBoard::getValidMoves() //Thinking about passing back somethign else with the coords of pieces that can move
{
	std::vector<Move> CurrentAvailMoves;
	if (this->playerTurn ==false)//If white turn check for white pieces that can move
	{
		for (int i = 0; i < 8; ++i)
		{
			for (int j = 0; j < 8; ++j)
			{
				Move temp(this->CurrentGameBoard[i][j]);//Create move object for current piece being evaluated
				if (this->CurrentGameBoard[i][j] == WteChecker)//if current piece is white piece test it's movemnet to see if movement is possible
				{
					for (int m = 0; m < 2; ++m)//Loop to check both movements m reporesents number of possible moves that a piece can try, 2 for a normal piece and 4 for a king
					{
						if (this->CurrentGameBoard[i + this->movement[m].x][j + this->movement[m].y] == FreeSpace)//if move is valid to freespace add to list
						{
							temp.PosibleMoves.push_back(std::make_pair(Coord(i, j), Coord(this->movement[m].x, this->movement[m].y)));
							CurrentAvailMoves.push_back(temp);
						}
						else if (this->CurrentGameBoard[i + this->movement[m].x][j + this->movement[m].y] == RedChecker)
						{
							temp.score += temp.TakePiece;
							temp.PosibleMoves.push_back(std::make_pair(Coord(i, j), Coord(this->movement[m].x, this->movement[m].y)));
						}
						else if (this->CurrentGameBoard[i + this->movement[m].x][j + this->movement[m].y] == RedKing)
						{
							temp.score += temp.TakePiece;
							temp.PosibleMoves.push_back(std::make_pair(Coord(i, j), Coord(this->movement[m].x, this->movement[m].y)));
						}
					}
				}

			}
		}
	} //End of White logic and start of red
	if (this->playerTurn == true)//If red turn check for white pieces that can move
	{
		for (int i = 0; i < 8; ++i)
		{
			for (int j = 0; j < 8; ++j)
			{
				Move temp(this->CurrentGameBoard[i][j]);//Create move object for current piece being evaluated
				if (this->CurrentGameBoard[i][j] == RedChecker)//if current piece is white piece test it's movemnet to see if movement is possible
				{
					for (int m = 0; m < 2; ++m)//Loop to check both movements mreporesents number of possible moves that a piece can try, 2 for
					{
						if (this->CurrentGameBoard[i + this->movement[m].x][j + this->movement[m].y*-1] == FreeSpace)//if move is valid to freespace add to list
						{
							temp.PosibleMoves.push_back(std::make_pair(Coord(i, j), Coord(this->movement[m].x, this->movement[m].y*-1)));
							CurrentAvailMoves.push_back(temp);
						}
						else if (this->CurrentGameBoard[i + this->movement[m].x][j + this->movement[m].y*-1] == WteChecker)
						{
							temp.score += temp.TakePiece;
							temp.PosibleMoves.push_back(std::make_pair(Coord(i, j), Coord(this->movement[m].x, this->movement[m].y*-1)));
						}
						else if (this->CurrentGameBoard[i + this->movement[m].x][j + this->movement[m].y*-1] == WteKing)
						{
							temp.score += temp.TakePiece;
							temp.PosibleMoves.push_back(std::make_pair(Coord(i, j), Coord(this->movement[m].x, this->movement[m].y*-1)));
						}
					}
					
				}
			}
		}
	}

	return CurrentAvailMoves;
}



/*std::vector<Moves> CheckersBoard::generateCurrentPlayerMoves()
{
	//For Coords were pieces can move - calls function that returns vector of coords
	if (this->playerTurn)//If White turn
	{
		{
			for(auto& Eachiece : VECTORHERE)
		}
		//Call function that returns all white pieces that can move
		std::vector<Coord> moveablePieces = CheckersBoard::getPiecesWithValidMoves();
		/*if()//IF any of the pieces can jump Continue to work with them. Player must make a jump and take a piece
		{

		}
		
	}
	
}
*/