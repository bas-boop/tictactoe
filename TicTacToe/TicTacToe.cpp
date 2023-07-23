// TicTacToe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Grid.h"

void CheckIfCrossHasWon();
void CheckIfCircleHasWon();

int main()
{
    ShowGrid();

    CheckIfCrossHasWon();
    CheckIfCircleHasWon();

    return 0;
}

void CheckIfCrossHasWon() {
    if (CheckForThreeInARow(CellState::Cross)) std::cout << "\nCross has won!\n";
}
void CheckIfCircleHasWon() {
    if (CheckForThreeInARow(CellState::Circle)) std::cout << "\Circle has won!\n";
}
