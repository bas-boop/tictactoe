#include <iostream>
#include "InputHandeler.h"
#include "Grid.h"

int main()
{
    ShowStartDialogue();
    SetGridEmpty();
    SetAIToEmpty();
    AskCoopOrAI();
    if(PlayAgain()) main();

    return 0;
}
