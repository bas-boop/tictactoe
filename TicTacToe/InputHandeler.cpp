#include <iostream>
#include "Grid.h"

CellState playerShape;
CellState player2Shape;
int targetPlace;

void ShowStartDialogue()
{
	std::cout << "Welcome to C++ Tic-Tac-Toe\nHere you can play a old time classic game.\nDo you want to be the cross or circle?\n";
	char inputPlayerShape;
	std::cin >> inputPlayerShape;

	do {
		std::cout << "\nTyp X or O.";
		std::cin >> inputPlayerShape;
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
}

void AskWhereToPlace(CellState currentPlayer)
{
	char charValue = static_cast<char>(currentPlayer);
	std::cout << "\nWhere do you want to place " << charValue << " ";
	std::cin >> targetPlace;
	SetCellToSomething(currentPlayer, targetPlace);
	ShowGrid();

	if (CheckForWinner()) return;

	if (currentPlayer == playerShape) currentPlayer = player2Shape;
	else if (currentPlayer == player2Shape) currentPlayer = playerShape;

	AskWhereToPlace(currentPlayer);
}
