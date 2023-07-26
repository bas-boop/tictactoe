#include <iostream>
#include "InputHandeler.h"
#include "Grid.h"

CellState playerShape;
CellState player2Shape;
int targetPlace;

void ShowStartDialogue()
{
	std::cout << "Welcome to C++ Tic-Tac-Toe\nHere you can play a old time classic game.\n";
	char inputPlayerShape;

	do {
		std::cout << "Typ X or O.\n";
		std::cin >> inputPlayerShape; //todo: input can only be 1 char, not a string.
		if (inputPlayerShape == 'X' || inputPlayerShape == 'O') break;
	}
	while (inputPlayerShape != 'X' || inputPlayerShape != 'O');

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

void AskWhereToPlace(CellState currentPlayer)
{
	char charValue = static_cast<char>(currentPlayer);
	std::cout << "\nWhere do you want to place " << charValue << " ";
	std::cin >> targetPlace;

	if (!SetCellToSomething(currentPlayer, targetPlace)) AskAgain(currentPlayer);
	ShowGrid();

    if (CheckForWinner() || CheckForDraw()) return;

    // Switch between players by modifying the newPlayer reference
	CellState newPlayer;
    if (currentPlayer == playerShape) newPlayer = player2Shape;
    else if (currentPlayer == player2Shape) newPlayer = playerShape;

    AskWhereToPlace(newPlayer);
}

void AskAgain(CellState currentPlayer)
{
	char charValue = static_cast<char>(currentPlayer);
	std::cout << "\nThat spot is already taken, chose a diffrent place.\nWhere do you want to place " << charValue << " ";
	std::cin >> targetPlace;

	if (!SetCellToSomething(currentPlayer, targetPlace)) AskAgain(currentPlayer);
}

bool PlayAgain()
{
	char playAgain;
	std::cout << "\nWant to play again?\nY/N\n";
	std::cin >> playAgain;

	if (playAgain == 'Y') return true;
	else return false;
}
