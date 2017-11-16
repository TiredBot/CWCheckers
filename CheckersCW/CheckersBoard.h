#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <stack>

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

	//Move canJumpAgain(Coord startingCoord, Move move);
	//CURRENTLY WORKING ON THIS
	std::vector<std::pair<Coord, Coord>> PossibleMoves;//First coord is origin of piece, 2nd is destination
	std::vector<std::pair<Coord, Coord>> PossibleJumps;
	std::vector<std::vector<Coord>> Routes;
	bool MustJump;
	int score = 0;

	static const int MakeKing = 10;
	static const int TakeKing = 5;
	static const int TakeChecker = 2;
	static const int ToEdge = 1;

	Coord JumpedPieceCoord;//Loop through this at the end of each turn if a jump is made. Remove pieces at each location
	int JumpsThisTurn;
	void clearLists();
	void clearNonJumpsIfJumpsExist();
	
	bool isEmptyMove();
	
};
struct indexMove//Pass  back from choices so that the index can be kept for further jumps
{
	int index;
	Move move;
	indexMove();

	indexMove(int Index, Move m)
	{
		this->index = Index;
		this->move = m;
	}

};
class CheckersBoard
{
public:
	static Coord NormalMovement[2];
	static Coord KingMovement[4];
	static const CheckerEnum FreshBoard[8][8]; //maybe const expr
	int redGrave, wteGrave;
	bool playerTurn;
	CheckerEnum CurrentGameBoard[8][8];
	

	void ChangeMovementDirection();//function to multiply the  moment[1,2] y coord by -1
	void printBoard();
	void resetBoard();
	//void dropEmptyMoves(std::vector<Move> x);
	std::vector<Move> getValidMoves();
	void makeMove(Coord startCoord, Coord endCoord);
	void makeJump(Coord startCoord, Coord endCoord, Move m,int index);
	void makeKing();
	//Function that returns what kind of peice is at a Coord on the board; This can then be used withni the get Valid Moves function
	//Function that returns if a true if a piece can make a jump to take a piece

	std::stack<std::pair<Coord, Coord>> GameHistory;
	std::stack<std::pair<Coord, Coord>> UndoStack;
	std::stack<std::pair<Coord, Coord>> RedoStack;
	void undo();
	

	indexMove Choices(std::vector<Move> ListofMovesperPiece);//Displays available moves to the user and returns move that is picked by the user
	Move CanJumpAgain(Coord LandingCoord, CheckerEnum PieceType);
	bool canJumpAgain1(Coord startingCoord, Move move);
	bool wteWin();
	bool redWin();//Check these at end of each players turn
	CheckersBoard();
	~CheckersBoard();
	std::pair<bool, Move> canJumpAgain(Coord LandingCoord, Move move);
};


struct node
{
	int value;
	CheckersBoard board;
	std::vector<node> children;
	bool hasChildren();
	bool AIturn;

};



/*
void scoreFunction(CheckersBoard board, int depth)
{

}



*/


