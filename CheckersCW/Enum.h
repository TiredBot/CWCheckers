#ifndef ENUM_H_GUARD
#define ENUM_H_GUARD

struct Coord
{
	int x, y;
	Coord();
	Coord(int X, int Y)
	{
		x = X;
		y = Y;
	}
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


#endif