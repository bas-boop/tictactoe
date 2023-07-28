#include <iostream>
#include "InputHandeler.h"
#include "Grid.h"
#include "AI.h"

CellState playerShape;
CellState player2Shape;
int targetPlace;
bool isAI;

void ShowStartDialogue()
{
	std::cout << "Welcome to C++ Tic-Tac-Toe.\nHere you can play a old time classic game.\n";
}

void ChooseShape()
{
	std::cout << "Do you want to be cross or circle?\n";
	char inputPlayerShape;

	do {
		std::cout << "Typ X or O.\n";
		std::cin >> inputPlayerShape; //todo: input can only be 1 char, not a string.
		if (inputPlayerShape == 'X' || inputPlayerShape == 'O') break;
	} while (inputPlayerShape != 'X' || inputPlayerShape != 'O');

	if (inputPlayerShape == 'X')
	{
		playerShape = CellState::Cross;
		player2Shape = CellState::Circle;
	}
	else if (inputPlayerShape == 'O')
	{
		playerShape = CellState::Circle;
		player2Shape = CellState::Cross;
	}

	std::cout << "\nThe spots are in this order:\n1,2,3\n4,5,6\n7,8,9\n";
}

void AskCoopOrAI()
{
	std::cout << "Do you play against the computer or with a friend?\nTyp C or F";
	char input;
	std::cin >> input;

	ChooseShape();

	if (input == 'C') 
	{ 
		isAI = true;
		AskWhereToPlace(CoinFlip(), isAI); 
	}
	else if (input == 'F') 
		AskWhereToPlace(CoinFlip());
}

void AskWhereToPlace(CellState currentPlayer, bool isAITurn)
{
	if (CheckForWinner() || CheckForDraw()) return;

	if (isAITurn || (isAI && currentPlayer == player2Shape))
		AIPLace(currentPlayer);
	else
		PlayerPlace(currentPlayer);
}

void AskAgain(CellState currentPlayer)
{
	char charValue = static_cast<char>(currentPlayer);
	std::cout << "\nThat spot is already taken, choose a different place.\nWhere do you want to place " << charValue << " ";
	std::cin >> targetPlace;

	if (!SetCellToSomething(currentPlayer, targetPlace))
		AskAgain(currentPlayer);
}

void PlayerPlace(CellState currentPlayer)
{
	char charValue = static_cast<char>(currentPlayer);
	std::cout << "\nWhere do you want to place " << charValue << " ";
	std::cin >> targetPlace;

	if (!SetCellToSomething(currentPlayer, targetPlace))
		AskAgain(currentPlayer);

	ShowGrid();
	AskWhereToPlace(SwitchPlayer(currentPlayer));
}

void AIPLace(CellState aiPlayer)
{
	std::cout << "\nIt's the computer's turn.";
	AIPlaceCell();
}

bool PlayAgain()
{
	char playAgain;
	std::cout << "\nWant to play again?\nY/N\n";
	std::cin >> playAgain;

	if (playAgain == 'Y') return true;
	else return false;
}

CellState CoinFlip()
{
	srand(time(NULL));
	int randomNumber = rand() % 2;

	if (randomNumber == 1)
	{
		std::cout << "\nPlayer 2 goes first.\n";
		return player2Shape;
	}

	std::cout << "\nPlayer 1 goes first.\n";
	return playerShape;
}

CellState SwitchPlayer(CellState currentPlayer)
{
	// Switch between players by modifying the newPlayer reference
	CellState newPlayer;
	if (currentPlayer == playerShape) return player2Shape;
	else if (currentPlayer == player2Shape) return playerShape;
}
