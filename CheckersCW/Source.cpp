#include <iostream>

class CheckersBoard
{
	
	CheckersBoard()
	{
		turnNumber = 0;
	}

	int turnNumber;
	enum CheckerEnum
	{
		FreeSpace,//0
		WteChecker,//1
		WteKing,//2
		RedChecker,//3
		RedKing//4
	};
	const CheckerEnum StartingBoard[8][8] = { { FreeSpace, WteChecker, FreeSpace, WteChecker, FreeSpace, WteChecker, FreeSpace, WteChecker },
											  { WteChecker, FreeSpace, WteChecker, FreeSpace, WteChecker, FreeSpace, WteChecker, FreeSpace },
											  { FreeSpace, WteChecker, FreeSpace, WteChecker, FreeSpace, WteChecker, FreeSpace, WteChecker },
											  { FreeSpace, FreeSpace, FreeSpace, FreeSpace, FreeSpace, FreeSpace, FreeSpace, FreeSpace },
											  { FreeSpace, FreeSpace, FreeSpace, FreeSpace, FreeSpace, FreeSpace, FreeSpace, FreeSpace },
											  { RedChecker, FreeSpace, RedChecker, FreeSpace, RedChecker, FreeSpace, RedChecker, FreeSpace },
											  { FreeSpace, RedChecker, FreeSpace, RedChecker, FreeSpace, RedChecker, FreeSpace, RedChecker },
											  { RedChecker, FreeSpace, RedChecker, FreeSpace, RedChecker, FreeSpace, RedChecker, FreeSpace }
											};

	CheckerEnum CurrentBoardState[8][8] = { { FreeSpace, WteChecker, FreeSpace, WteChecker, FreeSpace, WteChecker, FreeSpace, WteChecker },
											{ WteChecker, FreeSpace, WteChecker, FreeSpace, WteChecker, FreeSpace, WteChecker, FreeSpace },
											{ FreeSpace, WteChecker, FreeSpace, WteChecker, FreeSpace, WteChecker, FreeSpace, WteChecker },
											{ FreeSpace, FreeSpace, FreeSpace, FreeSpace, FreeSpace, FreeSpace, FreeSpace, FreeSpace },
											{ FreeSpace, FreeSpace, FreeSpace, FreeSpace, FreeSpace, FreeSpace, FreeSpace, FreeSpace },
											{ RedChecker, FreeSpace, RedChecker, FreeSpace, RedChecker, FreeSpace, RedChecker, FreeSpace },
											{ FreeSpace, RedChecker, FreeSpace, RedChecker, FreeSpace, RedChecker, FreeSpace, RedChecker },
											{ RedChecker, FreeSpace, RedChecker, FreeSpace, RedChecker, FreeSpace, RedChecker, FreeSpace }
										};
	void clearBoard()
	{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
				this->CurrentBoardState[i][j] = FreeSpace;
		}
	}




};