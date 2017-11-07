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

struct Moves
{
	CheckerEnum PieceType;
	Moves(CheckerEnum piece)
	{
		PieceType = piece;
	}
	std::vector<Coord> PosibleMoves;
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
	std::vector<Coord> getPiecesWithValidMoves();
	std::vector<Moves> generateCurrentPlayerMoves();

	CheckersBoard();
	~CheckersBoard();
};



