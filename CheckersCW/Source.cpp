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
	bool playFlag = true;
	board.printBoard();
	

	while (playFlag)
	{
		if (board.playerTurn == false)//White Checkers turn
		{
			std::cout << "Player 1s turn\n";
			std::vector<Move> CurrentMoveList = board.getValidMoves();
			for (size_t PieceWithMove = 0; PieceWithMove < CurrentMoveList.size(); ++PieceWithMove)
			{
				CurrentMoveList[PieceWithMove].clearNonJumpsIfJumpsExist();
			}
			indexMove m = board.Choices(CurrentMoveList);
			
			if (m.move.PossibleJumps.size() >= 1)
			{
				std::cout << "Please input the number beside the Coordinate of the square you would like to JUMP to: \n";
				for (size_t move = 0; move < m.move.PossibleJumps.size(); ++move)
				{
					std::cout << move + 1 << ". (" << m.move.PossibleJumps[move].second.x + 1 << "," << m.move.PossibleJumps[move].second.y + 1 << ")\n";//Print Coord of piece that can Jump
				}//This runs more than once even though move = size 1????
				int userInput;
				std::cin >> userInput;
				userInput = userInput - 1;// subtract 1 from input as accessed from zero
				std::cout << std::endl;

			
				Coord StartCoord = Coord(m.move.PossibleJumps[userInput].first.x, m.move.PossibleJumps[userInput].first.y);
				Coord EndCoord = Coord(m.move.PossibleJumps[userInput].second.x, m.move.PossibleJumps[userInput].second.y);

				board.makeJump(StartCoord, EndCoord, m.move,userInput);
				board.printBoard();
				
				bool AnotherOne = board.canJumpAgain(EndCoord, m.move).first;
				while ( AnotherOne == true)//this returns a pair, first true if another Jump can be made
				{//When you can Jump again prompt for choice and then make Jump
					std::vector<Move> JumpTemp;
					Move a = board.canJumpAgain(EndCoord, m.move).second;
					JumpTemp.push_back(a);
					indexMove JumpMove = board.Choices(JumpTemp);//Returns Move and index chosen related to move picked from PossibleJumps 
					
					StartCoord = JumpTemp[0].PossibleJumps[JumpMove.index].first;
					EndCoord = JumpTemp[0].PossibleJumps[JumpMove.index].second;

					board.makeJump(StartCoord, EndCoord, JumpMove.move, JumpMove.index);

					board.printBoard();
					
					m.move = board.canJumpAgain(EndCoord, m.move).second;
					/*std::vector<Move> AnotherOne;//Temp, required as choices() takes a Vector of Move
					AnotherOne.push_back(board.canJumpAgain(EndCoord, m.move).second);//Push back move that is returned from above function
					//Above pushes the Possible Jump on to AnoterOne
					std::cout << "Further ";
					m = board.Choices(AnotherOne);
					board.makeJump(EndCoord,m.move.PossibleJumps[m.index].second,m.move,m.index);*/
					JumpTemp.clear();
					
				}
				
			}
			else if (m.move.PossibleMoves.size() > 0 && m.move.PossibleJumps.size() == 0)//Move logic, works.
			{
				std::cout << "Please input the number beside the Coordinate of the square you would like to MOVE to: \n";
				for (size_t move = 0; move < m.move.PossibleMoves.size(); ++move)
				{
					std::cout << move + 1 << ". FROM(" << m.move.PossibleMoves[move].first.x + 1 << ", " << m.move.PossibleMoves[move].first.y + 1 << ") TO: (" << m.move.PossibleMoves[move].second.x + 1 << "," << m.move.PossibleMoves[move].second.y + 1 << ")\n";//Print Coord of piece that can Jump
				}
				int userInput;
				std::cin >> userInput;
				userInput = userInput - 1;// subtract 1 from input as accessed from zero
				std::cout << std::endl;
				Coord StartCoord = Coord(m.move.PossibleMoves[userInput].first.x, m.move.PossibleMoves[userInput].first.y);
				Coord EndCoord = Coord(m.move.PossibleMoves[userInput].second.x, m.move.PossibleMoves[userInput].second.y);

				board.makeMove(StartCoord, EndCoord);
			}
			board.printBoard();
			board.playerTurn = 1;
		}
		else if (board.playerTurn == true)//RED turn
		{
			std::cout << "Player 2s turn\n";
			std::vector<Move> CurrentMoveList = board.getValidMoves();
			for (size_t PieceWithMove = 0; PieceWithMove < CurrentMoveList.size(); ++PieceWithMove)
			{
				CurrentMoveList[PieceWithMove].clearNonJumpsIfJumpsExist();
			}
			indexMove m = board.Choices(CurrentMoveList);

			if (m.move.PossibleJumps.size() >= 1)
			{
				std::cout << "Please input the number beside the Coordinate of the square you would like to JUMP to: \n";
				for (size_t move = 0; move < m.move.PossibleJumps.size(); ++move)
				{
					std::cout << move + 1 << ". (" << m.move.PossibleJumps[move].second.x + 1 << "," << m.move.PossibleJumps[move].second.y + 1 << ")\n";//Print Coord of piece that can Jump
				}//This runs more than once even though move = size 1????
				int userInput;
				std::cin >> userInput;
				userInput = userInput - 1;// subtract 1 from input as accessed from zero
				std::cout << std::endl;


				Coord StartCoord = Coord(m.move.PossibleJumps[userInput].first.x, m.move.PossibleJumps[userInput].first.y);
				Coord EndCoord = Coord(m.move.PossibleJumps[userInput].second.x, m.move.PossibleJumps[userInput].second.y);

				board.makeJump(StartCoord, EndCoord, m.move, userInput);
				board.printBoard();


				while (board.canJumpAgain(EndCoord, m.move).first == true)//this returns a pair, first true if another Jump can be made
				{//When you can Jump again prompt for choice and then make Jump
					std::vector<Move> JumpTemp;
					Move a = board.canJumpAgain(EndCoord, m.move).second;
					JumpTemp.push_back(a);
					indexMove JumpMove = board.Choices(JumpTemp);//Returns Move and index chosen related to move picked from PossibleJumps 

					StartCoord = JumpTemp[0].PossibleJumps[JumpMove.index].first;
					EndCoord = JumpTemp[0].PossibleJumps[JumpMove.index].second;

					board.makeJump(StartCoord, EndCoord, JumpMove.move, JumpMove.index);

					board.printBoard();

					m.move = board.canJumpAgain(EndCoord, m.move).second;
					/*std::vector<Move> AnotherOne;//Temp, required as choices() takes a Vector of Move
					AnotherOne.push_back(board.canJumpAgain(EndCoord, m.move).second);//Push back move that is returned from above function
					//Above pushes the Possible Jump on to AnoterOne
					std::cout << "Further ";
					m = board.Choices(AnotherOne);
					board.makeJump(EndCoord,m.move.PossibleJumps[m.index].second,m.move,m.index);*/
					JumpTemp.clear();

				}

			}
			else if (m.move.PossibleMoves.size() > 0 && m.move.PossibleJumps.size() == 0)//Move logic, works.
			{
				std::cout << "Please input the number beside the Coordinate of the square you would like to MOVE to: \n";
				for (size_t move = 0; move < m.move.PossibleMoves.size(); ++move)
				{
					std::cout << move + 1 << ". FROM(" << m.move.PossibleMoves[move].first.x + 1 << ", " << m.move.PossibleMoves[move].first.y + 1 << ") TO: (" << m.move.PossibleMoves[move].second.x + 1 << "," << m.move.PossibleMoves[move].second.y + 1 << ")\n";//Print Coord of piece that can Jump
				}
				int userInput;
				std::cin >> userInput;
				userInput = userInput - 1;// subtract 1 from input as accessed from zero
				std::cout << std::endl;
				Coord StartCoord = Coord(m.move.PossibleMoves[userInput].first.x, m.move.PossibleMoves[userInput].first.y);
				Coord EndCoord = Coord(m.move.PossibleMoves[userInput].second.x, m.move.PossibleMoves[userInput].second.y);

				board.makeMove(StartCoord, EndCoord);
			}
			board.printBoard();
			board.playerTurn = 0;
		}
	}
	return 0;
}

//You stopped when multipple jumps was fucked in all the ways
//I hate this course