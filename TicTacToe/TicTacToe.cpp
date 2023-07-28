#include <iostream>
#include "InputHandeler.h"
#include "Grid.h"

int main()
{
    ShowStartDialogue();
    SetGridEmpty();
    //ChooseShape();
    AskCoopOrAI();
    if(PlayAgain()) main();

    return 0;
}
