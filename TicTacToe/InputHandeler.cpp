#include <iostream>
#include "InputHandeler.h"
#include "Grid.h"

CellState playerShape;
CellState player2Shape;
int targetPlace;

void ShowStartDialogue()
{
	std::cout << "Welcome to C++ Tic-Tac-Toe\nHere you can play a old time classic game.\nPress any key & enter!\n";
	char inputPlayerShape;
	std::cin >> inputPlayerShape;

	do {
		std::cout << "\nTyp X or O.";
		std::cin >> inputPlayerShape;
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
    if (currentPlayer == playerShape)
    {
		newPlayer = player2Shape;
		std::cout << "\nP1";
    }
    else if (currentPlayer == player2Shape)
    {
		newPlayer = playerShape;
		std::cout << "\nP2";
    }

    AskWhereToPlace(newPlayer);
}

void AskAgain(CellState currentPlayer)
{
	char charValue = static_cast<char>(currentPlayer);
	std::cout << "\nThat spot is already taken, chose a diffrent place.\nWhere do you want to place " << charValue << " ";
	std::cin >> targetPlace;

	if (!SetCellToSomething(currentPlayer, targetPlace)) AskAgain(currentPlayer);
}
