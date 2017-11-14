#include "CheckersBoard.h"
/*
void PrintMoves(std::vector<Move> TurnMoves)
{
	for (int eapiece = 0; TurnMoves.size(); ++eapiece)
	{
		if (TurnMoves[eapiece].PossibleJumps.size() > 0 || TurnMoves[eapiece].PossibleMoves.size() > 0)
		{
			if (TurnMoves[eapiece].PossibleJumps.size() == 0)
			{
				for (int i = 0; i < TurnMoves[eapiece].PossibleMoves.size(); ++i)
				{
					std::cout << "(" << TurnMoves[eapiece].PossibleMoves[i].first.x   << ", " <<
						TurnMoves[eapiece].PossibleMoves[i].first.y     << ") TO -> (" << TurnMoves[eapiece].PossibleMoves[i].second.x     << ", " <<
						TurnMoves[eapiece].PossibleMoves[i].second.y     << ")\n";
				}
				std::cout << "_____" << std::endl;

			}
			else if (TurnMoves[eapiece].PossibleJumps.size() != 0)
			{
				for(int i = 0; i < TurnMoves[eapiece].PossibleJumps.size(); ++i)
				{
					std::cout << "(" << TurnMoves[eapiece].PossibleJumps[i].first.x   << ", " <<
						TurnMoves[eapiece].PossibleJumps[i].first.y   << ") JUMPTO -> (" << TurnMoves[eapiece].PossibleJumps[i].second.x   << ", " <<
						TurnMoves[eapiece].PossibleJumps[i].second.y   << ")" << std::endl;
				}
			}
		}
	}
}*/

int main(int argc, char** argv)
{
	CheckersBoard board = CheckersBoard();
	int playFlag = true;
	//b.resetBoard();
	//b.copyArrayInto(StartingBoardState,b.CurrentBoardState);//using this with the Starting BoardStateAbove for the time being
	board.printBoard();

	std::vector<Move> CurrentMoveList = board.getValidMoves();
//	while (playFlag)
	//{
	/*if(board.playerTurn == false)//White Checkers turn
		{
			std::cout << "Player one's turn!\n";
			
			
			for (size_t PieceWithMove = 0;PieceWithMove < CurrentMoveList.size(); ++PieceWithMove)
			{
				CurrentMoveList[PieceWithMove].clearNonJumpsIfJumpsExist();
			}
			CurrentMoveList[0].printChoices(CurrentMoveList);

			std::cout <<std::endl;
		}*/
	//	else
	//	{
	//		std::cout << "Player one's turn!\n";
	//	}

	//}


	/*
	std::vector<Move> CurrentPlayerMoves = b.getValidMoves();
	int x = CurrentPlayerMoves.size();
	std::cout << x << std::endl;
	std::cout << "Hello "<< std::endl;
	*/
	/*
	for (int piece = 0; piece < x; ++piece)
	{
		std::cout << "Moves for piece is located at : (" << CurrentPlayerMoves[piece].PossibleMoves[piece].first.x + 1 << ", " << CurrentPlayerMoves[piece].PossibleMoves[piece].first.y + 1 << ")" << std::endl;
		std::cout << "_____________________________" << std::endl;
		
		std::cout <<  CurrentPlayerMoves[piece].PossibleMoves.size() << std::endl;
		for (int moves = 0; moves < CurrentPlayerMoves[piece].PossibleMoves.size(); ++moves)
		{
				
			std::cout << "(" << CurrentPlayerMoves[piece].PossibleMoves[moves].second.x + 1 << ", " << CurrentPlayerMoves[piece].PossibleMoves[moves].second.y + 1 << ")" << std::endl;
	
		}
	}*/

	std::cout << "reeeeeeeeeeeeee" << std::endl;
	getchar();
	
	return 0;
	
}