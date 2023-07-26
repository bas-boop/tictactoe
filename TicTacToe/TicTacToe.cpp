#include <iostream>
#include "InputHandeler.h"
#include "Grid.h"

int main()
{
    ShowStartDialogue();
    SetGridEmpty();
    ShowGrid();
    AskWhereToPlace(playerShape);

    return 0;
}