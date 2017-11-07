#include "CheckersBoard.h"

int main(int argc, char** argv)
{
	CheckersBoard b = CheckersBoard();
	
	//b.resetBoard();
	//b.copyArrayInto(StartingBoardState,b.CurrentBoardState);//using this with the Starting BoardStateAbove for the time being
	b.printBoard();
	std::cout << b.movement[0].x << " " << b.movement[0].y << "|" << b.movement[1].x << " " << b.movement[1].y << std::endl;
	getchar();
	

	
}