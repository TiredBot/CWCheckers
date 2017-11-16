#include "CheckersBoard.h"
#include <algorithm>

//If this can return a bool and Move that would be nice
std::pair<bool, Move> CheckersBoard::canJumpAgain(Coord LandingCoord, Move move)
{
	move.clearLists();
		if (move.PieceType == WteChecker)//PieceType is saved from initial Move obj Construction. No risk of changing movement
		{
			CheckersBoard::NormalMovement[0] = Coord(1, -1);
			CheckersBoard::NormalMovement[1] = Coord(-1, -1);
			int MovementsAssesed = 0;

			for (int m = 0; m < 2; ++m)//Loop to check both movements m reporesents number of possible moves that a piece can try, 2 for a normal piece and 4 for a king
			{
				MovementsAssesed++;
				if (LandingCoord.x + CheckersBoard::NormalMovement[m].x < 8 && LandingCoord.x + CheckersBoard::NormalMovement[m].x >= 0 && LandingCoord.y + CheckersBoard::NormalMovement[m].y < 8 && LandingCoord.y + CheckersBoard::NormalMovement[m].y >= 0)//edfafsfafsfasf
				{//BoundsCHecking
					if (this->CurrentGameBoard[(LandingCoord.y + CheckersBoard::NormalMovement[m].y)][(LandingCoord.x + CheckersBoard::NormalMovement[m].x)] == FreeSpace)//if move is valid to freespace add to list
					{//do nothing as we are checking for enemy pieces to jump
					}
					else if (this->CurrentGameBoard[(LandingCoord.y + CheckersBoard::NormalMovement[m].y)][(LandingCoord.x + CheckersBoard::NormalMovement[m].x)] == WteChecker || this->CurrentGameBoard[(LandingCoord.y + CheckersBoard::NormalMovement[m].y)][(LandingCoord.x + CheckersBoard::NormalMovement[m].x)] == WteKing)
					{
						//If friendly checker or King in the way do nothing
					}

					else if (this->CurrentGameBoard[(LandingCoord.y + CheckersBoard::NormalMovement[m].y)][(LandingCoord.x + CheckersBoard::NormalMovement[m].x)] == RedChecker)//else if JUMPING REDchecker
					{//if next space is enemy checker then check space after it.
						//BOUNDS CHECKING LANDING ISNT OUT OF RANGE OF BOARD goes here
						if (LandingCoord.y + (CheckersBoard::NormalMovement[m].x * 2) < 8 && LandingCoord.y + (CheckersBoard::NormalMovement[m].x * 2) >= 0 && LandingCoord.x + (CheckersBoard::NormalMovement[m].y * 2) < 8 && LandingCoord.x + (CheckersBoard::NormalMovement[m].y) >= 0)//edfafsfafsfasf
						{
							if (this->CurrentGameBoard[(LandingCoord.y + CheckersBoard::NormalMovement[m].y * 2)][(LandingCoord.x + CheckersBoard::NormalMovement[m].x * 2)] == FreeSpace)//IF picec behind red checker is clear add to possible JUMP
							{
								move.score += Move::TakeChecker;
								move.PossibleJumps.push_back(std::make_pair(Coord(LandingCoord.x, LandingCoord.y), Coord(LandingCoord.x + CheckersBoard::NormalMovement[m].x * 2, LandingCoord.y + CheckersBoard::NormalMovement[m].y * 2)));
								move.JumpedPieceCoord= Coord(LandingCoord.x + CheckersBoard::NormalMovement[m].x, LandingCoord.y + CheckersBoard::NormalMovement[m].y);
								move.MustJump = true;
							}
						}
					}
					else if (this->CurrentGameBoard[(LandingCoord.y + CheckersBoard::NormalMovement[m].y)][(LandingCoord.x + CheckersBoard::NormalMovement[m].x)] == RedKing)//IF picec behind red checker is clear add to possible JUMP
					{
						if (LandingCoord.y + (CheckersBoard::NormalMovement[m].x * 2) < 8 && LandingCoord.y + (CheckersBoard::NormalMovement[m].x * 2) >= 0 && LandingCoord.x + (CheckersBoard::NormalMovement[m].y * 2) < 8 && LandingCoord.x + (CheckersBoard::NormalMovement[m].y) >= 0)//edfafsfafsfasf
						{
							if (this->CurrentGameBoard[(LandingCoord.y + CheckersBoard::NormalMovement[m].y * 2)][(LandingCoord.x + CheckersBoard::NormalMovement[m].x * 2)] == FreeSpace)//IF picec behind red checker is clear add to possible JUMP
							{
								move.score += Move::TakeKing;
								move.PossibleJumps.push_back(std::make_pair(Coord(LandingCoord.x, LandingCoord.y), Coord(LandingCoord.x + CheckersBoard::NormalMovement[m].x * 2, LandingCoord.y + CheckersBoard::NormalMovement[m].y * 2)));
								move.MustJump = true;
							}
						}
					}

				}
				if (MovementsAssesed == 2)
				{
					if (move.PossibleJumps.size() >= 0)
					{
						return std::make_pair(true, move);
					}
					else
					{
						return std::make_pair(false, move);
					}
				}
			}
		}
}


/*void CheckersBoard::makeMove(Coord start, Coord end)
{
	if ()
}






														/*FreeSpace,//0
															WteChecker,//1
															WteKing,//2
															RedChecker,//3
															RedKing,//4
															UnusedSpace//5*/

const CheckerEnum CheckersBoard::FreshBoard[8][8] = {
	{ UnusedSpace, RedChecker, UnusedSpace, RedChecker, UnusedSpace, RedChecker, UnusedSpace, RedChecker },
	{ RedChecker, UnusedSpace, RedChecker, UnusedSpace, RedChecker, UnusedSpace, RedChecker, UnusedSpace },
	{ UnusedSpace, RedChecker, UnusedSpace, RedChecker, UnusedSpace, RedChecker, UnusedSpace, RedChecker },
	{ FreeSpace, UnusedSpace, FreeSpace, UnusedSpace, FreeSpace, UnusedSpace, FreeSpace, UnusedSpace },
	{ UnusedSpace, RedChecker, UnusedSpace, FreeSpace, UnusedSpace, FreeSpace, UnusedSpace, FreeSpace },
	{ WteChecker, UnusedSpace, FreeSpace, UnusedSpace, WteChecker, UnusedSpace, WteChecker, UnusedSpace },
	{ UnusedSpace, WteChecker, UnusedSpace, WteChecker, UnusedSpace, WteChecker, UnusedSpace, WteChecker },
	{ WteChecker, UnusedSpace, WteChecker, UnusedSpace, WteChecker, UnusedSpace, WteChecker, UnusedSpace }
}; 
/*
const CheckerEnum CheckersBoard::FreshBoard[8][8] = {
{ UnusedSpace, RedChecker, UnusedSpace, RedChecker, UnusedSpace, RedChecker, UnusedSpace, RedChecker },
	{ RedChecker, UnusedSpace, FreeSpace, UnusedSpace, FreeSpace, UnusedSpace, FreeSpace, UnusedSpace },
	{ UnusedSpace, RedChecker, UnusedSpace, RedChecker, UnusedSpace, RedChecker, UnusedSpace, RedChecker },
	{ FreeSpace, UnusedSpace, FreeSpace, UnusedSpace, FreeSpace, UnusedSpace, FreeSpace, UnusedSpace },
	{ UnusedSpace, FreeSpace, UnusedSpace, RedChecker, UnusedSpace, FreeSpace, UnusedSpace, FreeSpace },
	{ WteChecker, UnusedSpace, FreeSpace, UnusedSpace, WteChecker, UnusedSpace, WteChecker, UnusedSpace },
	{ UnusedSpace, RedChecker, UnusedSpace, WteChecker, UnusedSpace, WteChecker, UnusedSpace, WteChecker },
	{ WteChecker, UnusedSpace, WteChecker, UnusedSpace, WteChecker, UnusedSpace, WteChecker, UnusedSpace }
	};
	*/

Coord CheckersBoard::NormalMovement[2];
Coord CheckersBoard::KingMovement[4];
CheckerEnum CurrentGameBoard[8][8];

CheckersBoard::CheckersBoard()
{
	this->playerTurn = false;
	this->redGrave = 0;
	this->wteGrave = 0;

	this->resetBoard();
}
CheckersBoard::~CheckersBoard()
{
}
Move::Move()
{
	score = 0;
	MustJump = 0;
	//canKing = 0;
}
Move::~Move()
{
	score = 0;
	MustJump = 0;
//	canKing = 0;
}
Move::Move(CheckerEnum piece)
{
	PieceType = piece;
	score = 0;
	MustJump = 0;
	//canKing = 0;
}

void Move::clearNonJumpsIfJumpsExist()//If jump exists, clears moves and MustJump = true, else = false
{
	if (this->PossibleJumps.size() != 0)
	{
		this->PossibleMoves.clear();
		this->MustJump = true;
	}
	else
	{
		this->MustJump = false;
	}
}


bool Move::isEmptyMove()
{
	if (this->PossibleJumps.empty() && this->PossibleMoves.empty())
	{
		return true;
	}
	else 
		return false;
}

/*void CheckersBoard::dropEmptyMoves(std::vector<Move> x)
{
	for (size_t i = 0; i < x.size(); ++i)
	{
		auto iter(std::remove_if(x.begin(), x.end(), x[i].isEmptyMove()));
		x.erase(iter);
	}

	
}*/


	

void CheckersBoard::printBoard()
{
	std::cout << "*  _1 2 3 4 5 6 7 8_  Player 1 : O = White Checker  0 = White King\n";
	std::cout << "*  _________________  Player 2 : U = Red Checker    Y = Red King\n";
	for (int i = 0; i < 8; i++)
	{
		std::cout << i + 1 << "  |";
		for (int j = 0; j < 8; j++)
		{
			
			if (this->CurrentGameBoard[i][j] == UnusedSpace || this->CurrentGameBoard[i][j] == FreeSpace)
			{
				std::cout << "- "; 
			}
			else if (this->CurrentGameBoard[i][j] == WteChecker)
			{
				std::cout  << "O ";
			}
			else if (this->CurrentGameBoard[i][j] == WteKing)
			{
				std::cout << "0 ";
			}
			else if (this->CurrentGameBoard[i][j] == RedChecker)
			{
				std::cout << "U ";
			}
			else if (this->CurrentGameBoard[i][j] == RedKing)
			{
				std::cout  << "Y ";
			}
			
		}
		std::cout << "\n";
		
	}
	std::cout << "   __________________\n";
}
void CheckersBoard::resetBoard()
{
	std::copy(&this->FreshBoard[0][0], &this->FreshBoard[0][0] + (8 * 8), &this->CurrentGameBoard[0][0]);
}

void Move::clearLists()
{
	this->PossibleMoves.clear();
	this->PossibleJumps.clear();
}

std::vector<Move> CheckersBoard::getValidMoves()//Returns list of valid moves for each piece that has movement. The list can be assessed, if a move has possible jumps they must be taken and o more assesing possible moves
{
	std::vector<Move> CurrentAvailMoves;
	Move temp;

	if (this->playerTurn == false)//If white turn check for white pieces that can move
	{
		for (int column = 0; column < 8; ++column)
		{
			for (int row = 0; row < 8; ++row)
			{
				//Move temp(this->CurrentGameBoard[column][row]);//Create move object for current piece being evaluated
				if (this->CurrentGameBoard[column][row] == WteChecker)//if current piece is white piece test it's movement to see if movement is possible
				{
					this->NormalMovement[0] = Coord(1, -1);
					this->NormalMovement[1] = Coord(-1, -1);
					int MovementsAssesed = 0;

					for (int m = 0; m < 2; ++m)//Loop to check both movements m reporesents number of possible moves that a piece can try, 2 for a normal piece and 4 for a king
					{
						MovementsAssesed++;
						if (row + this->NormalMovement[m].x < 8 && row + this->NormalMovement[m].x >= 0 && column + this->NormalMovement[m].y < 8 && column + this->NormalMovement[m].y >= 0)//edfafsfafsfasf
						{//BoundsCHecking
							temp.PieceType = WteChecker;
							if (this->CurrentGameBoard[(column + this->NormalMovement[m].y)][(row + this->NormalMovement[m].x)] == FreeSpace)//if move is valid to freespace add to list
							{
								temp.PossibleMoves.push_back(std::make_pair(Coord(row, column), Coord(row + this->NormalMovement[m].x, column + this->NormalMovement[m].y)));
								temp.MustJump = false;
							}//swapped column and js above here
							else if (this->CurrentGameBoard[(column + this->NormalMovement[m].y)][(row + this->NormalMovement[m].x)] == WteChecker || this->CurrentGameBoard[(column + this->NormalMovement[m].y)][(row + this->NormalMovement[m].x)] == WteKing)
							{
								//If friendly checker or King in the way do nothing
							}

							else if (this->CurrentGameBoard[(column + this->NormalMovement[m].y)][(row + this->NormalMovement[m].x)] == RedChecker)//else if JUMPING RED
							{//if next space is enemy checker then check space after it.
								//BOUNDS CHECKING LANDING ISNT OUT OF RANGE OF BOARD goes here
								if (row + this->NormalMovement[m].x < 8 && row + this->NormalMovement[m].x >= 0 && column + this->NormalMovement[m].y < 8 && column + this->NormalMovement[m].y >= 0)//edfafsfafsfasf
								{
									if (this->CurrentGameBoard[(column + this->NormalMovement[m].y * 2)][(row + this->NormalMovement[m].x * 2)] == FreeSpace)//IF picec behind red checker is clear add to possible JUMP
									{
										temp.score += Move::TakeChecker;
										temp.PossibleJumps.push_back(std::make_pair(Coord(row, column), Coord(row + this->NormalMovement[m].x * 2, column + this->NormalMovement[m].y * 2)));
										temp.JumpedPieceCoord = Coord(row + this->NormalMovement[m].x, column + this->NormalMovement[m].y);
										temp.MustJump = true;
									}
								}
							}
							else if (this->CurrentGameBoard[(column + this->NormalMovement[m].y)][(row + this->NormalMovement[m].x)] == RedKing)//IF picec behind red checker is clear add to possible JUMP
							{
								if (row + this->NormalMovement[m].x < 8 && row + this->NormalMovement[m].x >= 0 && column + this->NormalMovement[m].y < 8 && column + this->NormalMovement[m].y >= 0)//edfafsfafsfasf
								{
									if (this->CurrentGameBoard[(column + this->NormalMovement[m].y * 2)][(row + this->NormalMovement[m].x * 2)] == FreeSpace)//IF picec behind red checker is clear add to possible JUMP
									{
										temp.score += Move::TakeKing;
										temp.PossibleJumps.push_back(std::make_pair(Coord(row, column), Coord(row + this->NormalMovement[m].x * 2, column + this->NormalMovement[m].y * 2)));
										temp.MustJump = true;
									}
								}
							}

						}
						if (MovementsAssesed == 2)
						{
							if (temp.isEmptyMove())
							{
							}
							else
							{
								CurrentAvailMoves.push_back(temp);
								temp.clearLists();
							}
						}
					}
				}
				//WHITEKING LOOP AND LOGIC SHOULD BE HERE
				if (this->CurrentGameBoard[column][row] == WteKing)//if current piece is white piece test it's movement to see if movement is possible
				{
					this->KingMovement[0] = Coord(-1, 1);
					this->KingMovement[1] = Coord(1, 1);
					this->KingMovement[2] = Coord(-1, -1);
					this->KingMovement[3] = Coord(1, -1);
					int MovementsAssesed = 0;

					for (int m = 0; m < 4; ++m)//Loop to check both movements m reporesents number of possible moves that a piece can try, 2 for a normal piece and 4 for a king
					{
						MovementsAssesed++;
						if (row + this->KingMovement[m].x < 8 && row + this->KingMovement[m].x >= 0 && column + this->KingMovement[m].y < 8 && column + this->KingMovement[m].y >= 0)//edfafsfafsfasf
						{//BoundsCHecking
							temp.PieceType = WteKing;
							if (this->CurrentGameBoard[(column + this->KingMovement[m].y)][(row + this->KingMovement[m].x)] == FreeSpace)//if move is valid to freespace add to list
							{//if next space = freespace fo nothjing
								temp.PossibleMoves.push_back(std::make_pair(Coord(row, column), Coord(row + this->KingMovement[m].x, column + this->KingMovement[m].y)));
								temp.MustJump = false;
							}//swapped column and js above here
							else if (this->CurrentGameBoard[column + this->KingMovement[m].x][row + this->KingMovement[m].y] == WteChecker || this->CurrentGameBoard[column + this->KingMovement[m].x][row + this->KingMovement[m].y] == WteKing)
							{
								//If friendly checker or King in the way do nothing
							}

							else if (this->CurrentGameBoard[column + this->KingMovement[m].x][row + this->KingMovement[m].y] == RedChecker)//else if JUMPING RED
							{//if next space is enemy checker then check space after it.
								if (column + (this->KingMovement[m].x * 2) < 8 && column + (this->KingMovement[m].x * 2) >= 0 && row + (this->KingMovement[m].y * 2) < 8 && row + (this->KingMovement[m].y) >= 0)//edfafsfafsfasf
								{
									if (this->CurrentGameBoard[(column + this->KingMovement[m].y * 2)][(row + this->KingMovement[m].x * 2)] == FreeSpace)//IF picec behind red checker is clear add to possible JUMP
									{
										temp.score += Move::TakeChecker;
										temp.PossibleJumps.push_back(std::make_pair(Coord(row, column), Coord(row + this->KingMovement[m].x * 2, column + this->KingMovement[m].y * 2)));
										temp.JumpedPieceCoord = Coord(row + this->KingMovement[m].x, column + this->KingMovement[m].y);
										temp.MustJump = true;
									}
								}
							}
							else if (this->CurrentGameBoard[column + this->KingMovement[m].x][row + this->KingMovement[m].y] == RedKing)//IF picec behind red checker is clear add to possible JUMP
							{
								if (column + (this->KingMovement[m].x * 2) < 8 && column + (this->KingMovement[m].x * 2) >= 0 && row + (this->KingMovement[m].y * 2) < 8 && row + (this->KingMovement[m].y) >= 0)//edfafsfafsfasf
								{
									if (this->CurrentGameBoard[(column + this->KingMovement[m].y * 2)][(row + this->KingMovement[m].x * 2)] == FreeSpace)//IF picec behind red checker is clear add to possible JUMP
									{
										temp.score += Move::TakeKing;
										temp.PossibleJumps.push_back(std::make_pair(Coord(row, column), Coord(row + this->KingMovement[m].x * 2, column + this->KingMovement[m].y * 2)));
										temp.JumpedPieceCoord = Coord(row + this->KingMovement[m].x, column + this->KingMovement[m].y);
										temp.MustJump = true;
									}
								}
							}

						}
						if (MovementsAssesed == 4)
						{
							if (temp.isEmptyMove())
							{
							}
							else
							{
								CurrentAvailMoves.push_back(temp);
								temp.clearLists();
							}
						}
					}
				}
			}
			temp.clearLists();
		}
	} //End of White logic and start of red--------------------------------------------------------------------------------------------------------
	else if (playerTurn == 1)//If red turn check for white pieces that can move
	{
		for (int column = 0; column < 8; ++column)
		{
			for (int row = 0; row < 8; ++row)
			{
				//Move temp(this->CurrentGameBoard[column][row]);//Create move object for current piece being evaluated
				if (this->CurrentGameBoard[column][row] == RedChecker)//if current piece is white piece test it's movement to see if movement is possible
				{
					this->NormalMovement[0] = Coord(1, 1);
					this->NormalMovement[1] = Coord(-1, 1);
					int MovementsAssesed = 0;

					for (int m = 0; m < 2; ++m)//Loop to check both movements m reporesents number of possible moves that a piece can try, 2 for a normal piece and 4 for a king
					{
						MovementsAssesed++;
						if (row + this->NormalMovement[m].x < 8 && row + this->NormalMovement[m].x >= 0 && column + this->NormalMovement[m].y < 8 && column + this->NormalMovement[m].y >= 0)//edfafsfafsfasf
						{//BoundsCHecking
							temp.PieceType = RedChecker;
							if (this->CurrentGameBoard[(column + this->NormalMovement[m].y)][(row + this->NormalMovement[m].x)] == FreeSpace)//if move is valid to freespace add to list
							{//if next space = freespace fo nothjing
								temp.PossibleMoves.push_back(std::make_pair(Coord(row, column), Coord(row + this->NormalMovement[m].x, column + this->NormalMovement[m].y)));
								temp.MustJump = false;
							}//swapped column and js above here
							else if (this->CurrentGameBoard[(column + this->NormalMovement[m].y)][(row + this->NormalMovement[m].x)] == RedChecker || this->CurrentGameBoard[(column + this->NormalMovement[m].y)][(row + this->NormalMovement[m].x)] == RedKing)
							{
								//If friendly checker or King in the way do nothing
							}

							else if (this->CurrentGameBoard[(column + this->NormalMovement[m].y)][(row + this->NormalMovement[m].x)] == WteChecker)
							{//if next space is enemy checker then check space after it.
								if (row + this->NormalMovement[m].x < 8 && row + this->NormalMovement[m].x >= 0 && column + this->NormalMovement[m].y < 8 && column + this->NormalMovement[m].y >= 0)//edfafsfafsfasf
								{
									if (this->CurrentGameBoard[(column + this->NormalMovement[m].y * 2)][(row + this->NormalMovement[m].x * 2)] == FreeSpace)//IF picec behind red checker is clear add to possible JUMP
									{
										temp.score += Move::TakeChecker;
										temp.PossibleJumps.push_back(std::make_pair(Coord(row, column), Coord(row + this->NormalMovement[m].x * 2, column + this->NormalMovement[m].y * 2)));
										temp.JumpedPieceCoord = Coord(row + this->NormalMovement[m].x, column + this->NormalMovement[m].y);
										temp.MustJump = true;
									}
								}
							}
							else if (this->CurrentGameBoard[(column + this->NormalMovement[m].y)][(row + this->NormalMovement[m].x)] == WteKing)//IF picec behind red checker is clear add to possible JUMP
							{
								if (row + this->NormalMovement[m].x < 8 && row + this->NormalMovement[m].x >= 0 && column + this->NormalMovement[m].y < 8 && column + this->NormalMovement[m].y >= 0)//edfafsfafsfasf
								{
									if (this->CurrentGameBoard[(column + this->NormalMovement[m].y * 2)][(row + this->NormalMovement[m].x * 2)] == FreeSpace)//IF picec behind red checker is clear add to possible JUMP
									{
										temp.score += Move::TakeKing;
										temp.PossibleJumps.push_back(std::make_pair(Coord(row, column), Coord(row + this->NormalMovement[m].x * 2, column + this->NormalMovement[m].y * 2)));
										temp.MustJump = true;
										temp.JumpedPieceCoord = Coord(row + this->NormalMovement[m].x, column + this->NormalMovement[m].y);
									}
								}
							}

						}
						if (MovementsAssesed == 2)
						{
							if (temp.isEmptyMove())
							{
							}
							else
							{
								CurrentAvailMoves.push_back(temp);
								temp.clearLists();
							}
						}
					}
				}
				//WHITEKING LOOP AND LOGIC SHOULD BE HERE
				if (this->CurrentGameBoard[column][row] == RedKing)//if current piece is white piece test it's movement to see if movement is possible
				{
					this->KingMovement[0] = Coord(-1, 1);
					this->KingMovement[1] = Coord(1, 1);
					this->KingMovement[2] = Coord(-1, -1);
					this->KingMovement[3] = Coord(1, -1);
					int MovementsAssesed = 0;

					for (int m = 0; m < 4; ++m)//Loop to check both movements m reporesents number of possible moves that a piece can try, 2 for a normal piece and 4 for a king
					{
						MovementsAssesed++;
						if (row + this->KingMovement[m].x < 8 && row + this->KingMovement[m].x >= 0 && column + this->KingMovement[m].y < 8 && column + this->KingMovement[m].y >= 0)//edfafsfafsfasf
						{//BoundsCHecking
							temp.PieceType = RedKing;
							if (this->CurrentGameBoard[(column + this->KingMovement[m].y)][(row + this->KingMovement[m].x)] == FreeSpace)//if move is valid to freespace add to list
							{//if next space = freespace fo nothjing
								temp.PossibleMoves.push_back(std::make_pair(Coord(row, column), Coord(row + this->KingMovement[m].x, column + this->KingMovement[m].y)));
								temp.MustJump = false;
							}//swapped column and js above here
							else if (this->CurrentGameBoard[column + this->KingMovement[m].x][row + this->KingMovement[m].y] == RedChecker || this->CurrentGameBoard[column + this->KingMovement[m].x][row + this->KingMovement[m].y] == RedKing)
							{
								//If friendly checker or King in the way do nothing
							}
							else if (this->CurrentGameBoard[column + this->KingMovement[m].x][row + this->KingMovement[m].y] == WteChecker)//else if JUMPING RED
							{//if next space is enemy checker then check space after it.
								if (column + (this->KingMovement[m].x * 2) < 8 && column + (this->KingMovement[m].x * 2) >= 0 && row + (this->KingMovement[m].y * 2) < 8 && row + (this->KingMovement[m].y) >= 0)//edfafsfafsfasf
								{
									if (this->CurrentGameBoard[(column + this->KingMovement[m].y * 2)][(row + this->KingMovement[m].x * 2)] == FreeSpace)//IF picec behind red checker is clear add to possible JUMP
									{
										temp.score += Move::TakeChecker;
										temp.PossibleJumps.push_back(std::make_pair(Coord(row, column), Coord(row + this->KingMovement[m].x * 2, column + this->KingMovement[m].y * 2)));
										temp.MustJump = true;
									}
								}
							}
							else if (this->CurrentGameBoard[column + this->KingMovement[m].x][row + this->KingMovement[m].y] == WteKing)//
							{
								if (column + (this->KingMovement[m].x * 2) < 8 && column + (this->KingMovement[m].x * 2) >= 0 && row + (this->KingMovement[m].y * 2) < 8 && row + (this->KingMovement[m].y) >= 0)
								{
									if (this->CurrentGameBoard[(column + this->KingMovement[m].y * 2)][(row + this->KingMovement[m].x * 2)] == FreeSpace)
									{
										temp.score += Move::TakeKing;
										temp.PossibleJumps.push_back(std::make_pair(Coord(row, column), Coord(row + this->KingMovement[m].x * 2, column + this->KingMovement[m].y * 2)));
										temp.MustJump = true;
									}
								}
							}
						}
						if (MovementsAssesed == 4)
						{
							if (temp.isEmptyMove())
							{
							}
							else
							{
								CurrentAvailMoves.push_back(temp);
								temp.clearLists();
							}
						}
					}

				}
			}
			temp.clearLists();
		}
	}
	return CurrentAvailMoves;
}
/*
Move CheckersBoard::CanJumpAgain(Coord LandingCoord, CheckerEnum PieceType)
{
	if (PieceType == WteChecker)
	{
		Move temp;
		this->NormalMovement[0] = Coord(1, -1);
		this->NormalMovement[1] = Coord(-1, -1);
		int MovementsAssesed = 0;

		for (int m = 0; m < 2; ++m)//Loop to check both movements m reporesents number of possible moves that a piece can try, 2 for a normal piece and 4 for a king
		{
			MovementsAssesed++;
			if (LandingCoord.x + this->NormalMovement[m].x < 8 && LandingCoord.x + this->NormalMovement[m].x >= 0 && LandingCoord.y + this->NormalMovement[m].y < 8 && LandingCoord.y + this->NormalMovement[m].y >= 0)//edfafsfafsfasf
			{//BoundsCHecking
				temp.PieceType = WteChecker;
				if (this->CurrentGameBoard[(LandingCoord.y + this->NormalMovement[m].y)][(LandingCoord.x + this->NormalMovement[m].x)] == FreeSpace)
				{
					//if next space = freespace don't add anything as we are checking for more jumps
				}
				else if (this->CurrentGameBoard[(LandingCoord.y + this->NormalMovement[m].y)][(LandingCoord.x + this->NormalMovement[m].x)] == RedChecker)
				{//if next space is enemy checker then check space after it.
					//BOUNDS CHECKING LANDING ISNT OUT OF RANGE OF BOARD goes here
					if (LandingCoord.y + (this->NormalMovement[m].x * 2) < 8 && LandingCoord.y + (this->NormalMovement[m].x * 2) >= 0 && LandingCoord.x + (this->NormalMovement[m].y * 2) < 8 && LandingCoord.x + (this->NormalMovement[m].y) >= 0)//edfafsfafsfasf
					{
						if (this->CurrentGameBoard[(LandingCoord.y + this->NormalMovement[m].y * 2)][(LandingCoord.x + this->NormalMovement[m].x * 2)] == FreeSpace)//IF square behind if free then this piece can jump again
						{
							temp.score += Move::TakeChecker;
							temp.PossibleJumps.push_back(std::make_pair(Coord(LandingCoord.x, LandingCoord.y), Coord(LandingCoord.x + this->NormalMovement[m].x * 2, LandingCoord.y + this->NormalMovement[m].y * 2)));
							temp.MustJump = true;
						}
					}					
				}
				else if (this->CurrentGameBoard[(LandingCoord.y + this->NormalMovement[m].y)][(LandingCoord.x + this->NormalMovement[m].x)] == RedKing)//IF picec behind red checker is clear add to possible JUMP
				{
					if (LandingCoord.y + (this->NormalMovement[m].x * 2) < 8 && LandingCoord.y + (this->NormalMovement[m].x * 2) >= 0 && LandingCoord.x + (this->NormalMovement[m].y * 2) < 8 && LandingCoord.x + (this->NormalMovement[m].y) >= 0)//edfafsfafsfasf
					{
						if (this->CurrentGameBoard[(LandingCoord.y + this->NormalMovement[m].y * 2)][(LandingCoord.x + this->NormalMovement[m].x * 2)] == FreeSpace)//IF picec behind red checker is clear add to possible JUMP
						{
							temp.score += Move::TakeKing;
							temp.PossibleJumps.push_back(std::make_pair(Coord(LandingCoord.x, LandingCoord.y), Coord(LandingCoord.x + this->NormalMovement[m].x * 2, LandingCoord.y + this->NormalMovement[m].y * 2)));
							temp.MustJump = true;
						}
					}
				}
			}
			if (MovementsAssesed == 2)
			{
				if (temp.isEmptyMove())
				{
				}
				else
				{
					return temp;	
				}
			}
		}
	}
	if (PieceType == WteKing)
	{
		Move temp;
		this->KingMovement[0] = Coord(-1, 1);
		this->KingMovement[1] = Coord(1, 1);
		this->KingMovement[2] = Coord(-1, -1);
		this->KingMovement[3] = Coord(1, -1);
		int MovementsAssesed = 0;

		for (int m = 0; m < 4; ++m)
		{
			MovementsAssesed++;
			if (LandingCoord.x + this->NormalMovement[m].x < 8 && LandingCoord.x + this->NormalMovement[m].x >= 0 && LandingCoord.y + this->NormalMovement[m].y < 8 && LandingCoord.y + this->NormalMovement[m].y >= 0)//edfafsfafsfasf
			{//BoundsCHecking
				temp.PieceType = WteKing;
				if (this->CurrentGameBoard[(LandingCoord.y + this->NormalMovement[m].y)][(LandingCoord.x + this->NormalMovement[m].x)] == FreeSpace)
				{
					//if next space = freespace don't add anything as we are checking for more jumps
				}
				else if (this->CurrentGameBoard[(LandingCoord.y + this->NormalMovement[m].y)][(LandingCoord.x + this->NormalMovement[m].x)] == RedChecker)
				{//if next space is enemy checker then check space after it.
					if (LandingCoord.y + (this->NormalMovement[m].x * 2) < 8 && LandingCoord.y + (this->NormalMovement[m].x * 2) >= 0 && LandingCoord.x + (this->NormalMovement[m].y * 2) < 8 && LandingCoord.x + (this->NormalMovement[m].y) >= 0)//edfafsfafsfasf
					{
						if (this->CurrentGameBoard[(LandingCoord.y + this->NormalMovement[m].y * 2)][(LandingCoord.x + this->NormalMovement[m].x * 2)] == FreeSpace)//IF square behind if free then this piece can jump again
						{
							temp.score += Move::TakeChecker;
							temp.PossibleJumps.push_back(std::make_pair(Coord(LandingCoord.x, LandingCoord.y), Coord(LandingCoord.x + this->NormalMovement[m].x * 2, LandingCoord.y + this->NormalMovement[m].y * 2)));
							temp.MustJump = true;
						}
					}
				}
				else if (this->CurrentGameBoard[(LandingCoord.y + this->NormalMovement[m].y)][(LandingCoord.x + this->NormalMovement[m].x)] == RedKing)//IF picec behind red checker is clear add to possible JUMP
				{
					if (LandingCoord.y + (this->NormalMovement[m].x * 2) < 8 && LandingCoord.y + (this->NormalMovement[m].x * 2) >= 0 && LandingCoord.x + (this->NormalMovement[m].y * 2) < 8 && LandingCoord.x + (this->NormalMovement[m].y) >= 0)//edfafsfafsfasf
					{
						if (this->CurrentGameBoard[(LandingCoord.y + this->NormalMovement[m].y * 2)][(LandingCoord.x + this->NormalMovement[m].x * 2)] == FreeSpace)//IF picec behind red checker is clear add to possible JUMP
						{
							temp.score += Move::TakeKing;
							temp.PossibleJumps.push_back(std::make_pair(Coord(LandingCoord.x, LandingCoord.y), Coord(LandingCoord.x + this->NormalMovement[m].x * 2, LandingCoord.y + this->NormalMovement[m].y * 2)));
							temp.MustJump = true;
						}
					}
				}
			}
			if (MovementsAssesed == 4)
			{
				if (temp.isEmptyMove())
				{
				}
				else
				{
					return temp;
				}
			}
		}
	}
	if (PieceType == RedChecker)
	{
		Move temp;
		this->NormalMovement[0] = Coord(1, 1);
		this->NormalMovement[1] = Coord(-1, 1);
		int MovementsAssesed = 0;

		for (int m = 0; m < 2; ++m)//Loop to check both movements m reporesents number of possible moves that a piece can try, 2 for a normal piece and 4 for a king
		{
			MovementsAssesed++;
			if (LandingCoord.x + this->NormalMovement[m].x < 8 && LandingCoord.x + this->NormalMovement[m].x >= 0 && LandingCoord.y + this->NormalMovement[m].y < 8 && LandingCoord.y + this->NormalMovement[m].y >= 0)//edfafsfafsfasf
			{//BoundsCHecking
				temp.PieceType = RedChecker;
				if (this->CurrentGameBoard[(LandingCoord.y + this->NormalMovement[m].y)][(LandingCoord.x + this->NormalMovement[m].x)] == FreeSpace)
				{
					//if next space = freespace don't add anything as we are checking for more jumps
				}
				else if (this->CurrentGameBoard[(LandingCoord.y + this->NormalMovement[m].y)][(LandingCoord.x + this->NormalMovement[m].x)] == WteChecker)
				{//if next space is enemy checker then check space after it.
					//BOUNDS CHECKING LANDING ISNT OUT OF RANGE OF BOARD goes here
					if (LandingCoord.y + (this->NormalMovement[m].x * 2) < 8 && LandingCoord.y + (this->NormalMovement[m].x * 2) >= 0 && LandingCoord.x + (this->NormalMovement[m].y * 2) < 8 && LandingCoord.x + (this->NormalMovement[m].y) >= 0)//edfafsfafsfasf
					{
						if (this->CurrentGameBoard[(LandingCoord.y + this->NormalMovement[m].y * 2)][(LandingCoord.x + this->NormalMovement[m].x * 2)] == FreeSpace)//IF square behind if free then this piece can jump again
						{
							temp.score += Move::TakeChecker;
							temp.PossibleJumps.push_back(std::make_pair(Coord(LandingCoord.x, LandingCoord.y), Coord(LandingCoord.x + this->NormalMovement[m].x * 2, LandingCoord.y + this->NormalMovement[m].y * 2)));
							temp.MustJump = true;
						}
					}
				}
				else if (this->CurrentGameBoard[(LandingCoord.y + this->NormalMovement[m].y)][(LandingCoord.x + this->NormalMovement[m].x)] == WteKing)//IF picec behind red checker is clear add to possible JUMP
				{
					if (LandingCoord.y + (this->NormalMovement[m].x * 2) < 8 && LandingCoord.y + (this->NormalMovement[m].x * 2) >= 0 && LandingCoord.x + (this->NormalMovement[m].y * 2) < 8 && LandingCoord.x + (this->NormalMovement[m].y) >= 0)//edfafsfafsfasf
					{
						if (this->CurrentGameBoard[(LandingCoord.y + this->NormalMovement[m].y * 2)][(LandingCoord.x + this->NormalMovement[m].x * 2)] == FreeSpace)//IF picec behind red checker is clear add to possible JUMP
						{
							temp.score += Move::TakeKing;
							temp.PossibleJumps.push_back(std::make_pair(Coord(LandingCoord.x, LandingCoord.y), Coord(LandingCoord.x + this->NormalMovement[m].x * 2, LandingCoord.y + this->NormalMovement[m].y * 2)));
							temp.MustJump = true;
						}
					}
				}
			}
			if (MovementsAssesed == 2)
			{
				if (temp.isEmptyMove())
				{
				}
				else
				{
					return temp;
				}
			}
		}
	}
	if (PieceType == RedKing)
	{
		Move temp;
		this->KingMovement[0] = Coord(-1, 1);
		this->KingMovement[1] = Coord(1, 1);
		this->KingMovement[2] = Coord(-1, -1);
		this->KingMovement[3] = Coord(1, -1);
		int MovementsAssesed = 0;

		for (int m = 0; m < 4; ++m)
		{
			MovementsAssesed++;
			if (LandingCoord.x + this->NormalMovement[m].x < 8 && LandingCoord.x + this->NormalMovement[m].x >= 0 && LandingCoord.y + this->NormalMovement[m].y < 8 && LandingCoord.y + this->NormalMovement[m].y >= 0)//edfafsfafsfasf
			{//BoundsCHecking
				temp.PieceType = RedKing;
				if (this->CurrentGameBoard[(LandingCoord.y + this->NormalMovement[m].y)][(LandingCoord.x + this->NormalMovement[m].x)] == FreeSpace)
				{
					//if next space = freespace don't add anything as we are checking for more jumps
				}
				else if (this->CurrentGameBoard[(LandingCoord.y + this->NormalMovement[m].y)][(LandingCoord.x + this->NormalMovement[m].x)] == WteChecker)
				{//if next space is enemy checker then check space after it.
					if (LandingCoord.y + (this->NormalMovement[m].x * 2) < 8 && LandingCoord.y + (this->NormalMovement[m].x * 2) >= 0 && LandingCoord.x + (this->NormalMovement[m].y * 2) < 8 && LandingCoord.x + (this->NormalMovement[m].y) >= 0)//edfafsfafsfasf
					{
						if (this->CurrentGameBoard[(LandingCoord.y + this->NormalMovement[m].y * 2)][(LandingCoord.x + this->NormalMovement[m].x * 2)] == FreeSpace)//IF square behind if free then this piece can jump again
						{
							temp.score += Move::TakeChecker;
							temp.PossibleJumps.push_back(std::make_pair(Coord(LandingCoord.x, LandingCoord.y), Coord(LandingCoord.x + this->NormalMovement[m].x * 2, LandingCoord.y + this->NormalMovement[m].y * 2)));
							temp.MustJump = true;
						}
					}
				}
				else if (this->CurrentGameBoard[(LandingCoord.y + this->NormalMovement[m].y)][(LandingCoord.x + this->NormalMovement[m].x)] == WteKing)//IF picec behind red checker is clear add to possible JUMP
				{
					if (LandingCoord.y + (this->NormalMovement[m].x * 2) < 8 && LandingCoord.y + (this->NormalMovement[m].x * 2) >= 0 && LandingCoord.x + (this->NormalMovement[m].y * 2) < 8 && LandingCoord.x + (this->NormalMovement[m].y) >= 0)//edfafsfafsfasf
					{
						if (this->CurrentGameBoard[(LandingCoord.y + this->NormalMovement[m].y * 2)][(LandingCoord.x + this->NormalMovement[m].x * 2)] == FreeSpace)//IF picec behind red checker is clear add to possible JUMP
						{
							temp.score += Move::TakeKing;
							temp.PossibleJumps.push_back(std::make_pair(Coord(LandingCoord.x, LandingCoord.y), Coord(LandingCoord.x + this->NormalMovement[m].x * 2, LandingCoord.y + this->NormalMovement[m].y * 2)));
							temp.MustJump = true;
						}
					}
				}
			}
			if (MovementsAssesed == 4)
			{
				if (temp.isEmptyMove())
				{
				}
				else
				{
					return temp;
				}
			}
		}
	}
}
*/
void CheckersBoard::makeMove(Coord startCoord, Coord endCoord)
{
	CheckerEnum CurrentPiece = this->CurrentGameBoard[startCoord.y][startCoord.x];//first[] = y axis, 2nd = x
	this->CurrentGameBoard[startCoord.y][startCoord.x] = FreeSpace;
	this->CurrentGameBoard[endCoord.y][endCoord.x] = CurrentPiece;
}
void CheckersBoard::makeJump(Coord startCoord, Coord endCoord, Move m,int index)
{
	CheckerEnum CurrentPiece = this->CurrentGameBoard[startCoord.y][startCoord.x];//first[] = y axis, 2nd = x
	this->CurrentGameBoard[startCoord.y][startCoord.x] = FreeSpace;//Staring location is made a free space
	this->CurrentGameBoard[m.JumpedPieceCoord.y][m.JumpedPieceCoord.x] = FreeSpace;//Jumped piece is made to freespace
	if (CurrentPiece == WteChecker || CurrentPiece == WteKing)
	{
		++redGrave;
	}
	else
		++wteGrave;

	this->CurrentGameBoard[endCoord.y][endCoord.x] = CurrentPiece;//Set landing coord to the piece jumping, stored earlier
}

indexMove CheckersBoard::Choices(std::vector<Move> ListofMovesperPiece)
{
	int input = -1;
	bool JumpExists = false;

	for (size_t i = 0; i < ListofMovesperPiece.size(); ++i)
	{
		if (ListofMovesperPiece[i].PossibleJumps.size() > 0)
		{
			JumpExists = true;
		}
	}

	for (size_t i = 0; i < ListofMovesperPiece.size(); ++i)
	{
		if (ListofMovesperPiece[i].PossibleJumps.size() >= 1)
		{
			std::cout << "Jumps are possible. Select the Friendly Checker that will make the jump :\n";
			for (size_t jumps = 0; jumps < ListofMovesperPiece.size(); ++jumps)
			{
				if (ListofMovesperPiece[jumps].PossibleJumps.size() != 0)
					std::cout << jumps +1 << ". (" << ListofMovesperPiece[jumps].PossibleJumps[0].first.x +1 << "," << ListofMovesperPiece[jumps].PossibleJumps[0].first.y +1 << ")\n";//Print currrent location of pieces that have a jump move available
			}
			std::cout << "Please input the index number beside the Coordinate of the Checker that will move and press enter: \n";

			std::cin >> input;
			input = input - 1;// subtract 1 from input as array accessed from zero
			std::cout << std::endl;
			return indexMove(input, ListofMovesperPiece[input]);
		}
		else if (!JumpExists && ListofMovesperPiece[i].PossibleMoves.size() != 0)
		{
			std::cout << "No Jumps are possible. Select the Coord of the Friendly Checker that will make a move : \n";
			for (size_t piece = 0; piece < ListofMovesperPiece.size(); ++piece)
			{
				std::cout << piece + 1 << ". (" << ListofMovesperPiece[piece].PossibleMoves[0].first.x + 1 << "," << ListofMovesperPiece[piece].PossibleMoves[0].first.y + 1 << ")\n";//Print Coord of piece that can Move
			}
			std::cout << "Please input the index number beside the Coordinate of the piece you would like to move and press enter: \n";

			std::cin >> input;
			input = input - 1;// subtract 1 from input as array accessed from zero
			std::cout << std::endl;
			return indexMove(input, ListofMovesperPiece[input]);
		}
	}
}

bool CheckersBoard::wteWin()
{
	if (redGrave == 12)
		return true;
	else 
		return false;
}
bool CheckersBoard::redWin()
{
	if (wteGrave == 12)
		return true;
	else
		return false;
}


bool node::hasChildren()
{
	if (this->children.size() == 0)
		return false;
	else
		return true;
}