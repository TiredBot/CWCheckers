#include "CheckersBoard.h"

int main(int argc, char** argv)
{
	CheckersBoard b = CheckersBoard();
	
	//b.resetBoard();
	//b.copyArrayInto(StartingBoardState,b.CurrentBoardState);//using this with the Starting BoardStateAbove for the time being
	b.printBoard();
	getchar();
	std::cout << b.movement[1].x << " " << b.movement[1].y << "|" << b.movement[2].x << " " << b.movement[2].y << std::endl;

	
}