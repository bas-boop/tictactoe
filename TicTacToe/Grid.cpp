#include <iostream>
#include "Grid.h"

CellState grid[3][3] = {
	{CellState::Cross, CellState::Cross, CellState::Circle},
	{CellState::Cross, CellState::Circle, CellState::Empty},
	{CellState::Cross, CellState::Empty, CellState::Circle}
};

void ShowGrid()
{
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			char charValue = static_cast<char>(grid[i][j]);
			std::cout << charValue << " ";
		}
		std::cout << "\n";
	}
}

bool CheckForThreeInARow(CellState state) {
	// Check rows
	for (int i = 0; i < 3; ++i) {
		if (grid[i][0] == state && grid[i][1] == state && grid[i][2] == state)
			return true;
	}

	// Check columns
	for (int j = 0; j < 3; ++j) {
		if (grid[0][j] == state && grid[1][j] == state && grid[2][j] == state)
			return true;
	}

	// Check diagonals
	if ((grid[0][0] == state && grid[1][1] == state && grid[2][2] == state) ||
		(grid[0][2] == state && grid[1][1] == state && grid[2][0] == state))
		return true;

	return false;
}

void SetGridEmpty()
{
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			grid[i][j] = CellState::Empty;
		}
	}
}

void SetCellToSomething(CellState targetState, int place)
{
	if (place > 9 || place < 1) return;

	if (place == 1) grid[0][0] = targetState;
	else if (place == 2) grid[0][1] = targetState;
	else if (place == 3) grid[0][2] = targetState;
	else if (place == 4) grid[1][0] = targetState;
	else if (place == 5) grid[1][1] = targetState;
	else if (place == 6) grid[1][2] = targetState;
	else if (place == 7) grid[2][0] = targetState;
	else if (place == 8) grid[2][1] = targetState;
	else if (place == 9) grid[2][2] = targetState;
}

int RandomNumber()
{
	/* initialize random seed: */
	srand(time(NULL));

	/* generate secret number: */
	return rand() % 9 + 1;
}