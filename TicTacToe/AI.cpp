#include <iostream>
#include "Grid.h"
#include "InputHandeler.h"

int RandomNumber()
{
	/* initialize random seed: */
	srand(time(NULL));

	/* generate secret number: */
	return rand() % 9 + 1;
}

void PlaceCell()
{
	while (true)
	{
		if (SetCellToSomething(player2Shape, RandomNumber())) break; // Successfully placed the cell, exit the loop
	}

	char charValue = static_cast<char>(player2Shape);
	std::cout << "\nThe computer has placed " << charValue << " "; 

	ShowGrid();
	AskWhereToPlace(playerShape);
}
