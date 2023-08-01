	#include <iostream>
	#include "Grid.h"

	CellState grid[3][3] = {
		{ CellState::Empty, CellState::Empty, CellState::Empty },
		{ CellState::Empty, CellState::Empty, CellState::Empty },
		{ CellState::Empty, CellState::Empty, CellState::Empty }
	};
	bool validCells[9];

	void ShowGrid()
	{
		std::cout << "\n";
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				char charValue = static_cast<char>(grid[i][j]);
				std::cout << charValue << " ";
			}
			std::cout << "\n";
		}
	}

	bool CheckForThreeInARow(CellState state) 
	{
		for (int i = 0; i < 3; ++i) {
			if ((grid[i][0] == state && grid[i][1] == state && grid[i][2] == state) || // Check rows
				(grid[0][i] == state && grid[1][i] == state && grid[2][i] == state))   // Check columns
			{
				return true;
			}
		}

		// Check diagonals
		if ((grid[0][0] == state && grid[1][1] == state && grid[2][2] == state) ||
			(grid[0][2] == state && grid[1][1] == state && grid[2][0] == state))
		{
			return true;
		}

		return false;
	}

	void SetGridEmpty()
	{
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				grid[i][j] = CellState::Empty;
			}
		}
		for (int i = 0; i < 9; ++i)
		{
			validCells[i] = false;
		}
	}

	bool SetCellToSomething(CellState targetState, int place)
	{
		if (IsValidCell(place))
		{
			int row = (place - 1) / 3;
			int col = (place - 1) % 3;
			grid[row][col] = targetState;
			return true;
		}

		return false;
	}

	bool IsValidCell(int place)
	{
		if (place >= 10 || place <= 0) return false;
		if (validCells[place - 1]) return false;

		validCells[place - 1] = true;
		return true;
	}

	bool CheckForWinner() {
		if (CheckForThreeInARow(CellState::Cross))
		{
			std::cout << "\nCross has won!\n";
			return true;
		}
		if (CheckForThreeInARow(CellState::Circle))
		{
			std::cout << "\nCircle has won!\n";
			return true;
		}

		return false;
	}


	bool CheckForDraw()
	{
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				if (grid[i][j] == CellState::Empty)
				{
					return false; // Found an empty cell, game is not a draw
				}
			}
		}

		std::cout << "It's a draw!\n";
		return true; // No empty cells found, game is a draw
	}