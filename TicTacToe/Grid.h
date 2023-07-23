#ifndef MAIN_H
#define MAIN_H
#include <iostream>

enum CellState { Empty = '.', Cross = 'X', Circle = 'O'};

CellState grid[3][3] = {
	{CellState::Cross, CellState::Empty, CellState::Circle},
	{CellState::Empty, CellState::Cross, CellState::Empty},
	{CellState::Circle, CellState::Empty, CellState::Cross}
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

#endif // !MAIN_H