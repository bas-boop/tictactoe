// TicTacToe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Grid.h"

int main()
{
    ShowStartDialogue();
    SetGridEmpty();
    ShowGrid();
    AskWhereToPlace(playerShape);

    return 0;
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
