#include <iostream>
#include "MediumAI.h"
#include "InputHandeler.h"
#include "Grid.h"

int MediumAI::RandomNumber()
{
	srand(time(NULL));
	return rand() % 9 + 1;
}

void MediumAI::StartPlacing()
{
	int lastSpot = IsOneEmptySpotLeft();
	int targetCell = CheckForAlmostThreeInARow(player2Shape);

	if (lastSpot != -1)   SetCellToSomething(player2Shape, lastSpot);
	else if (targetCell == 0) 
	{
		while (true)
		{
			if (SetCellToSomething(player2Shape, RandomNumber())) break; // Successfully placed the cell, exit the loop
		}
	}
	else SetCellToSomething(player2Shape, targetCell);

	
	std::cout << "\nAI has placed\n";
}