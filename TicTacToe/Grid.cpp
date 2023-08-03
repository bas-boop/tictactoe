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

	int CheckForAlmostThreeInARow(CellState state) {
		for (int i = 0; i < 3; ++i) {

			// Check rows for almost-3-in-a-row
			if ((grid[i][0] == state && grid[i][1] == state && grid[i][2] == CellState::Empty) ||
				(grid[i][0] == state && grid[i][1] == CellState::Empty && grid[i][2] == state) ||
				(grid[i][0] == CellState::Empty && grid[i][1] == state && grid[i][2] == state)) {

				// Return the index of the empty cell in the row
				if (grid[i][0] == CellState::Empty) 
					return i * 3 + 1;
				if (grid[i][1] == CellState::Empty) 
					return i * 3 + 2;
				if (grid[i][2] == CellState::Empty) 
					return i * 3 + 3;
			}

			// Check columns for almost-3-in-a-row
			if ((grid[0][i] == state && grid[1][i] == state && grid[2][i] == CellState::Empty) ||
				(grid[0][i] == state && grid[1][i] == CellState::Empty && grid[2][i] == state) ||
				(grid[0][i] == CellState::Empty && grid[1][i] == state && grid[2][i] == state)) {
				// Return the index of the empty cell in the column
				if (grid[0][i] == CellState::Empty) 
					return i + 1;
				if (grid[1][i] == CellState::Empty) 
					return i + 4;
				if (grid[2][i] == CellState::Empty) 
					return i + 7;
			}
		}

		// Check diagonals for almost-3-in-a-row
		if ((grid[0][0] == state && grid[1][1] == state && grid[2][2] == CellState::Empty) ||
			(grid[0][0] == state && grid[1][1] == CellState::Empty && grid[2][2] == state) ||
			(grid[0][0] == CellState::Empty && grid[1][1] == state && grid[2][2] == state) ||
			(grid[0][2] == state && grid[1][1] == state && grid[2][0] == CellState::Empty) ||
			(grid[0][2] == state && grid[1][1] == CellState::Empty && grid[2][0] == state) ||
			(grid[0][2] == CellState::Empty && grid[1][1] == state && grid[2][0] == state)) {

			// Return the index of the empty cell in the diagonal
			if (grid[0][0] == CellState::Empty) return 1;
			if (grid[1][1] == CellState::Empty) return 5;
			if (grid[2][2] == CellState::Empty) return 9;
			if (grid[0][2] == CellState::Empty) return 3;
			if (grid[2][0] == CellState::Empty) return 7;
		}

		return 0; // No almost-3-in-a-row found
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