#pragma once

#include <iostream>
#include <vector>

const enum CheckerEnum 
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
		jumpAvailable = 0; //default no jump available. This variable is only toggled if there is a piece that can be jump in the range of a piece
	};
	bool jumpAvailable;//This variable is only toggled if there is a piece that can be jump in the range of a piece
	Coord(int X, int Y, bool jump)
	{
		x = X;
		y = Y;
		jumpAvailable = jump;
	};
};

struct Move
{
	CheckerEnum PieceType;
	Move(CheckerEnum piece)
	{
		PieceType = piece;
	}
	std::vector<std::pair<Coord,Coord>> PosibleMoves;//First coord is origin of piece, 2nd is destination
	std::vector<std::pair<Coord, Coord>> PosibleJumps;
	int score = 0;
	static const int MakeKing = 10;
	static const int TakeKing = 5;
	static const int TakePiece = 2;
};


class CheckersBoard
{
public:
	int redGrave, wteGrave;
	Coord movement[2];
	bool playerTurn;
	static const CheckerEnum FreshBoard[8][8];
	CheckerEnum CurrentGameBoard[8][8];
	
	void printBoard();
	void resetBoard();
	std::vector<Move> getValidMoves();
	CheckerEnum inspectSpace(Coord square);
	//Function that returns what kind of peice is at a Coord on the board; This can then be used withni the get Valid Moves function
	//Function that returns if a true if a piece can make a jump to take a piece

	CheckersBoard();
	~CheckersBoard();
	enum CheckerEnum
{
	FreeSpace,//0
	WteChecker,//1
	WteKing,//2
	RedChecker,//3
	RedKing,//4
	UnusedSpace//5
};
};




