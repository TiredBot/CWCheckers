#include "CheckersBoard.h"

int main(int argc, char** argv)
{
	CheckersBoard b = CheckersBoard();
	
	//b.resetBoard();
	//b.copyArrayInto(StartingBoardState,b.CurrentBoardState);//using this with the Starting BoardStateAbove for the time being
	b.printBoard();
	
	 std::vector<Move> x = b.getValidMoves();
	
	getchar();
	

	
}