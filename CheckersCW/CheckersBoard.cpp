#include "CheckersBoard.h"
#include <algorithm>

/*
bool Move::canJumpAgain(Coord startingCoord, Move &move)//rather than take board take Coord and asses, maybe only call from within Generate possible moves
{//Don't remove anything from possible jumps, can clear at the end of the function or at the end of a player turn
		if (move.PieceType == WteKing || move.PieceType == RedKing)//PieceType is saved from initial Move obj Construction. No risk of changing movement
		{
				for (int i = 0; i < move.PossibleJumps.size(); ++i)//for each pair, so I can use the destination coord as the starting point for another jump
				{
					for (int m = 0; m < 4; ++m)//Loop for movements
					{//second element isn't Origin coord it is the coord of the piece being taken------------
						if (move.PossibleJumps[i].second.x + CheckersBoard::KingMovement[m].x >7 || move.PossibleJumps[i].second.x + CheckersBoard::KingMovement[m].x < 0 || move.PossibleJumps[i].second.y + CheckersBoard::KingMovement[m].y > 7 || move.PossibleJumps[i].second.y + CheckersBoard::KingMovement[m].y < 0)//out of bouds do nothing/ if DestPos+movement>7 or <0
						//This checksall pieces areound the target piece CORRECT logic for reaching space on other side of target piece, needs to go in direction of jump instead
						{//Each condition Checks if Jumping over a piece would put you out of range, if out of range remove from possible jump vector
							//If you are going off the board remove from the possible jumps
							//move.PossibleJumps.erase(move.PossibleJumps.begin() + i);//If out of range remove from possible jump vector
							
						}
						else if (CheckersBoard::inspectSpace(Coord(move.PossibleJumps[i].second.x + CheckersBoard::KingMovement[m].x, move.PossibleJumps[i].second.y + CheckersBoard::KingMovement[m].y != FreeSpace)))//If there is a piece behind the jump remove from list also
						{
								move.PossibleJumps.erase(move.PossibleJumps.begin() + i);
						}

						//Top 2 conditions remove jumps from the list where there is a pieve behind it
						else //Jump is valid as there is freesapce behind piece to jump
						{
							Coord EnemyCoord = Coord(move.PossibleJumps[i].second.x, move.PossibleJumps[i].second.y);
							std::pair<Coord, Coord> FinalCoord = std::make_pair(EnemyCoord, Coord(move.PossibleJumps[i].second.x + CheckersBoard::KingMovement[m].x, move.PossibleJumps[i].second.y + CheckersBoard::KingMovement[m].y));
								//FirstCoord is Where piece is located before moves are made -- I THINK
							//Create vector of route then push it to the RoutesVector of routes
							std::vector<Coord> aRoute;//Route is made for each possible move
							aRoute.push_back(startingCoord);//push starting location
							aRoute.push_back(EnemyCoord);//push location of piece to jump
							aRoute.push_back(Coord(FinalCoord.second.x ,FinalCoord.second.y));//push location jumped to
							move.Routes.push_back(aRoute);//Route has been created for one possible jump, Route = starting location and every location until the landing location


							//Route to jumped to location has been stored, Check if more jumps are still possible
							
							//May have to generate List of possible jumps from 
						}
					}
				}
		}
		else if (move.PieceType == WteChecker || move.PieceType == RedChecker)//Normcheckers
		{
			for (int i = 0; i < move.PossibleJumps.size(); ++i)//for each pair, so I can use the destination coord as the starting point for another jump
			{
				for (int m = 0; m < 2; ++m)//Loop for movements possible by each piece
				if (move.PossibleJumps[i].second.x + CheckersBoard::NormalMovement[m].x >7 || move.PossibleJumps[i].second.x + CheckersBoard::NormalMovement[m].x < 0 || move.PossibleJumps[i].second.y + CheckersBoard::NormalMovement[m].y > 7 || move.PossibleJumps[i].second.y + CheckersBoard::NormalMovement[m].y < 0)//out of bouds do nothing/ if DestPos+movement>7 or <0
				{//If jumping the piece would go off the board, remove the pair from the vector;
					move.PossibleJumps.erase(move.PossibleJumps.begin() + i);
				}
				else if (CheckersBoard::inspectSpace(Coord(move.PossibleJumps[i].second.x + CheckersBoard::KingMovement[m].x, move.PossibleJumps[i].second.y + CheckersBoard::KingMovement[m].y != FreeSpace)))
				{
					
						move.PossibleJumps.erase(move.PossibleJumps.begin() + i);//CANT DO THIS IT BREAKS EVERYTHING
				}
				else
				{
					Coord CurrentCoord = Coord(move.PossibleJumps[i].first.x, move.PossibleJumps[i].first.y);
					std::pair<Coord, Coord> FinalCoord = std::make_pair(CurrentCoord, Coord(move.PossibleJumps[i].second.x + CheckersBoard::NormalMovement[m].x, move.PossibleJumps[i].second.y + CheckersBoard::NormalMovement[m].y));
					//FirstCoord is Where piece is located before moves are made -- I THINK
					move.ConfirmedJumps.push_back(FinalCoord);
				}
			}
		}
		if (move.ConfirmedJumps.empty())
		{
			return false;
		}
		else
			return true;
}
*/

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
	{ UnusedSpace, RedChecker, UnusedSpace, RedChecker, UnusedSpace, FreeSpace, UnusedSpace, RedChecker },
	{ FreeSpace, UnusedSpace, FreeSpace, UnusedSpace, RedChecker, UnusedSpace, FreeSpace, UnusedSpace },
	{ UnusedSpace, FreeSpace, UnusedSpace, WteChecker, UnusedSpace, FreeSpace, UnusedSpace, FreeSpace },
	{ WteChecker, UnusedSpace, FreeSpace, UnusedSpace, WteChecker, UnusedSpace, WteChecker, UnusedSpace },
	{ UnusedSpace, WteChecker, UnusedSpace, WteChecker, UnusedSpace, WteChecker, UnusedSpace, WteChecker },
	{ WteChecker, UnusedSpace, WteChecker, UnusedSpace, WteChecker, UnusedSpace, WteChecker, UnusedSpace }
};

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
	canKing = 0;
}
Move::~Move()
{
	score = 0;
	MustJump = 0;
	canKing = 0;
}
Move::Move(CheckerEnum piece)
{
	PieceType = piece;
	score = 0;
	MustJump = 0;
	canKing = 0;
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
				std::cout << "# "; 
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
	std::cout << "   __________________" << std::endl;
}
void CheckersBoard::resetBoard()
{
	std::copy(&this->FreshBoard[0][0], &this->FreshBoard[0][0] + (8 * 8), &this->CurrentGameBoard[0][0]);
}

void Move::clearLists()
{
	this->PossibleMoves.clear();
	this->PossibleJumps.clear();
	this->ConfirmedJumps.clear();
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
							{//if next space = freespace fo nothjing
								temp.PossibleMoves.push_back(std::make_pair(Coord(row, column), Coord(row + this->NormalMovement[m].x, column + this->NormalMovement[m].y)));
								temp.MustJump = false;
							}//swapped column and js above here
							else if (this->CurrentGameBoard[(column + this->NormalMovement[m].y)][(row + this->NormalMovement[m].x)] == WteChecker || this->CurrentGameBoard[(column + this->NormalMovement[m].y)][(row + this->NormalMovement[m].x)] == WteChecker)
							{
								//If friendly checker or King in the way do nothing
							}

							else if (this->CurrentGameBoard[(column + this->NormalMovement[m].y)][(row + this->NormalMovement[m].x)] == RedChecker)//else if JUMPING RED
							{//if next space is enemy checker then check space after it.
								//BOUNDS CHECKING LANDING ISNT OUT OF RANGE OF BOARD goes here
								if (column + (this->NormalMovement[m].x * 2) < 8 && column + (this->NormalMovement[m].x * 2) >= 0 && row + (this->NormalMovement[m].y * 2) < 8 && row + (this->NormalMovement[m].y) >= 0)//edfafsfafsfasf
								{
									if (this->CurrentGameBoard[(column + this->NormalMovement[m].y * 2)][(row + this->NormalMovement[m].x * 2)] == FreeSpace)//IF picec behind red checker is clear add to possible JUMP
									{
										temp.score += Move::TakeChecker;
										temp.PossibleJumps.push_back(std::make_pair(Coord(row, column), Coord(row + this->NormalMovement[m].x * 2, column + this->NormalMovement[m].y * 2)));
										temp.MustJump = true;
									}
								}
							}
							else if (this->CurrentGameBoard[(column + this->NormalMovement[m].y)][(row + this->NormalMovement[m].x)] == RedKing)//IF picec behind red checker is clear add to possible JUMP
							{
								if (column + (this->NormalMovement[m].x * 2) < 8 && column + (this->NormalMovement[m].x * 2) >= 0 && row + (this->NormalMovement[m].y * 2) < 8 && row + (this->NormalMovement[m].y) >= 0)//edfafsfafsfasf
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
						if (row + this->NormalMovement[m].x < 8 && row + this->NormalMovement[m].x >= 0 && column + this->NormalMovement[m].y < 8 && column + this->NormalMovement[m].y >= 0)//edfafsfafsfasf
						{//BoundsCHecking
							temp.PieceType = WteKing;
							if (this->CurrentGameBoard[(column + this->NormalMovement[m].y)][(row + this->NormalMovement[m].x)] == FreeSpace)//if move is valid to freespace add to list
							{//if next space = freespace fo nothjing
								temp.PossibleMoves.push_back(std::make_pair(Coord(row, column), Coord(row + this->NormalMovement[m].x, column + this->NormalMovement[m].y)));
								temp.MustJump = false;
							}//swapped column and js above here
							else if (this->CurrentGameBoard[column + this->NormalMovement[m].x][row + this->NormalMovement[m].y] == WteChecker || this->CurrentGameBoard[column + this->NormalMovement[m].x][row + this->NormalMovement[m].y] == WteChecker)
							{
								//If friendly checker or King in the way do nothing
							}

							else if (this->CurrentGameBoard[column + this->NormalMovement[m].x][row + this->NormalMovement[m].y] == RedChecker)//else if JUMPING RED
							{//if next space is enemy checker then check space after it.
								if (column + (this->NormalMovement[m].x * 2) < 8 && column + (this->NormalMovement[m].x * 2) >= 0 && row + (this->NormalMovement[m].y * 2) < 8 && row + (this->NormalMovement[m].y) >= 0)//edfafsfafsfasf
								{
									if (this->CurrentGameBoard[(column + this->NormalMovement[m].y * 2)][(row + this->NormalMovement[m].x * 2)] == FreeSpace)//IF picec behind red checker is clear add to possible JUMP
									{
										temp.score += Move::TakeChecker;
										temp.PossibleJumps.push_back(std::make_pair(Coord(row, column), Coord(row + this->NormalMovement[m].x * 2, column + this->NormalMovement[m].y * 2)));
										temp.MustJump = true;
									}
								}
							}
							else if (this->CurrentGameBoard[column + this->NormalMovement[m].x][row + this->NormalMovement[m].y] == RedKing)//IF picec behind red checker is clear add to possible JUMP
							{
								if (column + (this->NormalMovement[m].x * 2) < 8 && column + (this->NormalMovement[m].x * 2) >= 0 && row + (this->NormalMovement[m].y * 2) < 8 && row + (this->NormalMovement[m].y) >= 0)//edfafsfafsfasf
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

							else if (this->CurrentGameBoard[(column + this->NormalMovement[m].y)][(row + this->NormalMovement[m].x)] == WteChecker)//else if JUMPING RED
							{//if next space is enemy checker then check space after it.
								//BOUNDS CHECKING LANDING ISNT OUT OF RANGE OF BOARD goes here
								if (column + (this->NormalMovement[m].x * 2) < 8 && column + (this->NormalMovement[m].x * 2) >= 0 && row + (this->NormalMovement[m].y * 2) < 8 && row + (this->NormalMovement[m].y) >= 0)//edfafsfafsfasf
								{
									if (this->CurrentGameBoard[(column + this->NormalMovement[m].y * 2)][(row + this->NormalMovement[m].x * 2)] == FreeSpace)//IF picec behind red checker is clear add to possible JUMP
									{
										temp.score += Move::TakeChecker;
										temp.PossibleJumps.push_back(std::make_pair(Coord(row, column), Coord(row + this->NormalMovement[m].x * 2, column + this->NormalMovement[m].y * 2)));
										temp.MustJump = true;
									}
								}
							}
							else if (this->CurrentGameBoard[(column + this->NormalMovement[m].y)][(row + this->NormalMovement[m].x)] == WteKing)//IF picec behind red checker is clear add to possible JUMP
							{
								if (column + (this->NormalMovement[m].x * 2) < 8 && column + (this->NormalMovement[m].x * 2) >= 0 && row + (this->NormalMovement[m].y * 2) < 8 && row + (this->NormalMovement[m].y) >= 0)//edfafsfafsfasf
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
						if (row + this->NormalMovement[m].x < 8 && row + this->NormalMovement[m].x >= 0 && column + this->NormalMovement[m].y < 8 && column + this->NormalMovement[m].y >= 0)//edfafsfafsfasf
						{//BoundsCHecking
							temp.PieceType = RedKing;
							if (this->CurrentGameBoard[(column + this->NormalMovement[m].y)][(row + this->NormalMovement[m].x)] == FreeSpace)//if move is valid to freespace add to list
							{//if next space = freespace fo nothjing
								temp.PossibleMoves.push_back(std::make_pair(Coord(row, column), Coord(row + this->NormalMovement[m].x, column + this->NormalMovement[m].y)));
								temp.MustJump = false;
							}//swapped column and js above here
							else if (this->CurrentGameBoard[column + this->NormalMovement[m].x][row + this->NormalMovement[m].y] == RedChecker || this->CurrentGameBoard[column + this->NormalMovement[m].x][row + this->NormalMovement[m].y] == WteChecker)
							{
								//If friendly checker or King in the way do nothing
							}
							else if (this->CurrentGameBoard[column + this->NormalMovement[m].x][row + this->NormalMovement[m].y] == WteChecker)//else if JUMPING RED
							{//if next space is enemy checker then check space after it.
								if (column + (this->NormalMovement[m].x * 2) < 8 && column + (this->NormalMovement[m].x * 2) >= 0 && row + (this->NormalMovement[m].y * 2) < 8 && row + (this->NormalMovement[m].y) >= 0)//edfafsfafsfasf
								{
									if (this->CurrentGameBoard[(column + this->NormalMovement[m].y * 2)][(row + this->NormalMovement[m].x * 2)] == FreeSpace)//IF picec behind red checker is clear add to possible JUMP
									{
										temp.score += Move::TakeChecker;
										temp.PossibleJumps.push_back(std::make_pair(Coord(row, column), Coord(row + this->NormalMovement[m].x * 2, column + this->NormalMovement[m].y * 2)));
										temp.MustJump = true;
									}
								}
							}
							else if (this->CurrentGameBoard[column + this->NormalMovement[m].x][row + this->NormalMovement[m].y] == WteKing)//
							{
								if (column + (this->NormalMovement[m].x * 2) < 8 && column + (this->NormalMovement[m].x * 2) >= 0 && row + (this->NormalMovement[m].y * 2) < 8 && row + (this->NormalMovement[m].y) >= 0)
								{
									if (this->CurrentGameBoard[(column + this->NormalMovement[m].y * 2)][(row + this->NormalMovement[m].x * 2)] == FreeSpace)
									{
										temp.score += Move::TakeKing;
										temp.PossibleJumps.push_back(std::make_pair(Coord(row, column), Coord(row + this->NormalMovement[m].x * 2, column + this->NormalMovement[m].y * 2)));
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

void CheckersBoard::makeMove(Coord startCoord, Coord endCoord)
{
	CheckerEnum CurrentPiece = this->CurrentGameBoard[startCoord.y][startCoord.x];//first[] = y axis, 2nd = x
	this->CurrentGameBoard[startCoord.y][startCoord.x] = FreeSpace;
	this->CurrentGameBoard[endCoord.y][endCoord.x] = CurrentPiece;
}
void CheckersBoard::makeJump(Coord startCoord, Coord endCoord)
{
	CheckerEnum CurrentPiece = this->CurrentGameBoard[startCoord.y][startCoord.x];//first[] = y axis, 2nd = x
	this->CurrentGameBoard[startCoord.y][startCoord.x] = FreeSpace;
	this->CurrentGameBoard[endCoord.y][endCoord.x] = CurrentPiece;
	Coord JumpedPiece = Coord(endCoord.x - startCoord.x, endCoord.y - startCoord.y);
	std::cout << endCoord.x - startCoord.x << " " << endCoord.y - startCoord.y;
}

Move CheckersBoard::Choices(std::vector<Move> ListofMovesperPiece)
{
	int input = -1;
	bool JumpExists = 0;

	for (size_t i = 0; i < ListofMovesperPiece.size(); ++i)
	{
		if (ListofMovesperPiece[i].PossibleJumps.size() >= 1)
		{
			std::cout << "Jumps are possible. Select the Friendly Checker that will make the jump :\n";
			for (size_t jumps = 0; jumps < ListofMovesperPiece.size(); ++jumps)
			{
				if(ListofMovesperPiece[jumps].PossibleJumps.size() != 0)
					std::cout << jumps +1 << ". (" << ListofMovesperPiece[jumps].PossibleJumps[0].first.x +1 << "," << ListofMovesperPiece[jumps].PossibleJumps[0].first.y +1 << ")\n";//Print currrent location of pieces that have a jump move available
			}
			std::cout << "Please input the index number beside the Coordinate of the Checker that will move and press enter: \n";

			std::cin >> input;
			input = input - 1;// subtract 1 from input as array accessed from zero
			std::cout << std::endl;
			return ListofMovesperPiece[input];
		}
		else if (ListofMovesperPiece[i].PossibleJumps.size() == 0 && ListofMovesperPiece[i].PossibleMoves.size() != 0)
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



			return ListofMovesperPiece[input];//returns the moves for the piece at the coord selected
		}
	}
}