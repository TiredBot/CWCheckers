#include "Enum.h"
class CheckerPiece
{
	CheckerEnum PieceType;
	static Coord possibleMovesForPiece[2];
	virtual void FunctionForVirtual() = 0;
};

class RedCheckerPiece : public CheckerPiece
{
	virtual void FunctionForVirtual() = 0;
	Coord possibleMovesForPiece[2] = { Coord(-1, -1), Coord(-1, 1) };
};
class WteCheckerPiece : public CheckerPiece
{
	virtual void FunctionForVirtual() = 0;
	Coord possibleMovesForPiece[2] = { Coord(1, -1), Coord(1, 1) };
};