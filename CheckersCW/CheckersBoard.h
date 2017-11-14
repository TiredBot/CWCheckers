#pragma once

#include <iostream>
#include <vector>

enum CheckerEnum 
{
	FreeSpace,//0
	WteChecker,//1
	WteKing,//2
	RedChecker,//3
	RedKing,//4
	UnusedSpace//5
};

struct Coord
{
	int x, y;
	Coord(){};
	Coord(int X, int Y)
	{
		x = X;
		y = Y;
	};
};



struct Move
{
	CheckerEnum PieceType;
	Move();
	Move(CheckerEnum piece);
	~Move();

	bool canJumpAgain(Coord startingCoord, Move &move);//CURRENTLY WORKING ON THIS
	std::vector<std::pair<Coord, Coord>> PossibleMoves;//First coord is origin of piece, 2nd is destination
	std::vector<std::pair<Coord, Coord>> PossibleJumps;
	std::vector<std::pair<Coord, Coord>> ConfirmedJumps;
	std::vector<std::vector<Coord>> Routes;
	bool MustJump;
	int score = 0;
	static const int MakeKing = 10;
	bool canKing;
	static const int TakeKing = 5;
	static const int TakeChecker = 2;
	void clearLists();
	void clearNonJumpsIfJumpsExist();
	void printChoices(std::vector<Move> ListofMoves);
	
};

class CheckersBoard
{
public:
	//Clear travelled line by jumping piece
	static Coord NormalMovement[2];
	static Coord KingMovement[4];
	static const CheckerEnum FreshBoard[8][8]; //maybe const expr
	int redGrave, wteGrave;
	bool playerTurn;
	CheckerEnum CurrentGameBoard[8][8];
	

	void ChangeMovementDirection();//function to multiply the  moment[1,2] y coord by -1
	void printBoard();
	void resetBoard();
	std::vector<Move> getValidMoves();
	
	//Function that returns what kind of peice is at a Coord on the board; This can then be used withni the get Valid Moves function
	//Function that returns if a true if a piece can make a jump to take a piece



	CheckersBoard();
	~CheckersBoard();

};




