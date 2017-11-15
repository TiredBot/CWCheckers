#include "CheckersBoard.h"

void PrintMoves(std::vector<Move> TurnMoves)//THIS IS JUST TO DEBUG - NOT IN USE NOT UPDATED
{
	for (size_t eapiece = 0; TurnMoves.size(); ++eapiece)
	{
		if (TurnMoves[eapiece].PossibleJumps.size() > 0)
		{
			if (TurnMoves[eapiece].PossibleJumps.size() == 0)
			{
				for (size_t i = 0; i < TurnMoves[eapiece].PossibleMoves.size(); ++i)
				{
					std::cout << "(" << TurnMoves[eapiece].PossibleMoves[i].first.x + 1 << ", " <<
						TurnMoves[eapiece].PossibleMoves[i].first.y + 1 << ") TO -> (" << TurnMoves[eapiece].PossibleMoves[i].second.x + 1 << ", " <<
						TurnMoves[eapiece].PossibleMoves[i].second.y + 1 << ")\n";
				}
				std::cout << "_____" << std::endl;

			}
			else if (TurnMoves[eapiece].PossibleJumps.size() != 0)
			{
				for (size_t i = 0; i < TurnMoves[eapiece].PossibleJumps.size(); ++i)
				{
					std::cout << "(" << TurnMoves[eapiece].PossibleJumps[i].first.x + 1 << ", " <<
						TurnMoves[eapiece].PossibleJumps[i].first.y + 1 << ") JUMPTO -> (" << TurnMoves[eapiece].PossibleJumps[i].second.x + 1 << ", " <<
						TurnMoves[eapiece].PossibleJumps[i].second.y +1  << ")" << std::endl;
				}
				std::cout << "_____" << std::endl;
			}
		}
	}
}

int main(int argc, char** argv)
{
	CheckersBoard board = CheckersBoard();
	int playFlag = true;
	board.printBoard();
	

	while (playFlag)
	{
		board.playerTurn = 0;
		if (board.playerTurn == false)//White Checkers turn
		{
			std::cout << "Player one's turn!\n";
			std::vector<Move> CurrentMoveList = board.getValidMoves();
			for (size_t PieceWithMove = 0; PieceWithMove < CurrentMoveList.size(); ++PieceWithMove)
			{
				CurrentMoveList[PieceWithMove].clearNonJumpsIfJumpsExist();
			}
			Move m = board.Choices(CurrentMoveList);

			if (m.PossibleJumps.size() >= 1)
			{
				std::cout << "Please input the number beside the Coordinate of the square you would like to JUMP to: \n";
				for (size_t move = 0; move < m.PossibleJumps.size(); ++move)
				{
					std::cout << move + 1 << ". (" << m.PossibleJumps[move].second.x + 1 << "," << m.PossibleJumps[move].second.y + 1 << ")\n";//Print Coord of piece that can Jump
				}
				int userInput;
				std::cin >> userInput;
				userInput = userInput - 1;// subtract 1 from input as accessed from zero
				std::cout << std::endl;
				Coord StartCoord, EndCoord;
				StartCoord.x = m.PossibleMoves[userInput].first.x;
				StartCoord.y = m.PossibleMoves[userInput].first.y;
				EndCoord.x = m.PossibleMoves[userInput].second.x;
				EndCoord.y = m.PossibleMoves[userInput].second.y;
				board.makeJump(StartCoord, EndCoord);
				board.printBoard();
			}
			else if (m.PossibleMoves.size() > 0 && m.PossibleJumps.size() == 0)//Move logic, works.
			{
				std::cout << "Please input the number beside the Coordinate of the square you would like to MOVE to: \n";
				for (size_t move = 0; move < m.PossibleMoves.size(); ++move)
				{
					std::cout << move + 1 << ". FROM(" << m.PossibleMoves[move].first.x + 1 << ", " << m.PossibleMoves[move].first.y + 1 << ") TO: (" << m.PossibleMoves[move].second.x + 1 << "," << m.PossibleMoves[move].second.y + 1 << ")\n";//Print Coord of piece that can Jump
				}
				int userInput;
				std::cin >> userInput;
				userInput = userInput - 1;// subtract 1 from input as accessed from zero
				std::cout << std::endl;
				Coord StartCoord, EndCoord;
				StartCoord.x = m.PossibleMoves[userInput].first.x;
				StartCoord.y = m.PossibleMoves[userInput].first.y;
				EndCoord.x = m.PossibleMoves[userInput].second.x;
				EndCoord.y = m.PossibleMoves[userInput].second.y;
				board.makeMove(StartCoord, EndCoord);
				board.printBoard();
			}
			board.playerTurn = 1;
		}

		else if (board.playerTurn == true)
		{
			std::vector<Move> CurrentMoveList = board.getValidMoves();
			std::cout << "Player two's turn!\n";
			for (size_t PieceWithMove = 0; PieceWithMove < CurrentMoveList.size(); ++PieceWithMove)
			{
				CurrentMoveList[PieceWithMove].clearNonJumpsIfJumpsExist();
			}
			Move m = board.Choices(CurrentMoveList);
			if (m.PossibleJumps.size() >= 1)
			{
				std::cout << "Please input the number beside the Coordinate of the square you would like to JUMP to: \n";
				for (size_t move = 0; move < m.PossibleJumps.size(); ++move)
				{
					std::cout << move + 1 << ". (" << m.PossibleJumps[move].second.x + 1 << "," << m.PossibleJumps[move].second.y + 1 << ")\n";//Print Coord of piece that can Jump
				}
				int userInput;
				std::cin >> userInput;
				userInput = userInput - 1;// subtract 1 from input as accessed from zero
				std::cout << std::endl;

				Coord StartCoord, EndCoord;
				StartCoord.x = m.PossibleMoves[userInput].first.x;
				StartCoord.y = m.PossibleMoves[userInput].first.y;
				EndCoord.x = m.PossibleMoves[userInput].second.x;
				EndCoord.y = m.PossibleMoves[userInput].second.y;

				board.makeJump(StartCoord, EndCoord);

				board.printBoard();
			}
			else if (m.PossibleMoves.size() > 0 && m.PossibleJumps.size() == 0)//Move logic, works.
			{
				std::cout << "Please input the number beside the Coordinate of the square you would like to MOVE to: \n";
				for (size_t move = 0; move < m.PossibleMoves.size(); ++move)
				{
					std::cout << move + 1 << ". FROM(" << m.PossibleMoves[move].first.x + 1 << ", " << m.PossibleMoves[move].first.y + 1 << ") TO: (" << m.PossibleMoves[move].second.x + 1 << "," << m.PossibleMoves[move].second.y + 1 << ")\n";//Print Coord of piece that can Jump
				}
				int userInput;
				std::cin >> userInput;
				userInput = userInput - 1;// subtract 1 from input as accessed from zero
				std::cout << std::endl;

				Coord StartCoord, EndCoord;
				StartCoord.x = m.PossibleMoves[userInput].first.x;
				StartCoord.y = m.PossibleMoves[userInput].first.y;
				EndCoord.x = m.PossibleMoves[userInput].second.x;
				EndCoord.y = m.PossibleMoves[userInput].second.y;

				board.makeMove(StartCoord, EndCoord);

				board.printBoard();
			}
		}
	}
	return 0;
}