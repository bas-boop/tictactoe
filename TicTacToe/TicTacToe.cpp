// TicTacToe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Grid.h"

void CheckForWinner();
CellState playerShape;

int main()
{
    ShowStartDialogue();
    char charValue = static_cast<char>(playerShape);
    std::cout << charValue << " ";
    /*ShowGrid();
    SetGridEmpty();
    ShowGrid();
    CheckForWinner();*/

    return 0;
}

void CheckForWinner() {
    if (CheckForThreeInARow(CellState::Cross)) std::cout << "\nCross has won!\n";
    if (CheckForThreeInARow(CellState::Circle)) std::cout << "\Circle has won!\n";
}
