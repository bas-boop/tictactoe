#include <iostream>
//#include "BaseAI.h"
#include "MediumAI.h"
#include "InputHandeler.h"
#include "Grid.h"

int MediumAI::RandomNumber()
{
	/* initialize random seed: */
	srand(time(NULL));

	/* generate secret number: */
	return rand() % 9 + 1;
}

void MediumAI::StartPlacing()
{
	int targetCell = CheckForAlmostThreeInARow(player2Shape);
	if (targetCell == 0) 
	{
		while (true)
		{
			if (SetCellToSomething(player2Shape, RandomNumber())) break; // Successfully placed the cell, exit the loop
		}
	}
	else SetCellToSomething(player2Shape, targetCell);

	
	std::cout << "\nAI has placed\n";
}