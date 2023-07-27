#include <iostream>
#include "InputHandeler.h"
#include "Grid.h"

CellState CoinFlip();

int main()
{
    ShowStartDialogue();
    SetGridEmpty();
    ShowGrid();
    AskWhereToPlace(playerShape);
    //AskWhereToPlace(CoinFlip());
    if(PlayAgain()) main();

    return 0;
}

CellState CoinFlip()
{
    srand(time(NULL));
    int randomNumber = rand() % 2;
    if (randomNumber == 0) {
        std::cout << "\nPlayer 1 goes first.";
        return playerShape;
    }
    else if (randomNumber == 1)
    {
        std::cout << "\nPlayer 2 goes first.";
        return player2Shape;
    }
}