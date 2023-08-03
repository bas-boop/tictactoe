#include <iostream>
#include "HardAI.h"
#include "InputHandeler.h"
#include "Grid.h"

int HardAI::RandomStartingCell()
{
	srand(time(NULL));
	int randomNumber = rand() % 5;

	if(randomNumber == 0) return 0;
	else if (randomNumber == 1) return 3;
	else if (randomNumber == 2) return 5;
	else if (randomNumber == 3) return 7;
	else if (randomNumber == 4) return 9;
}

void HardAI::StartPlacing()
{
	int targetCell = CheckForAlmostThreeInARow(player2Shape);
	int playerTargetCell = CheckForAlmostThreeInARow(playerShape);

	if (targetCell != 0) SetCellToSomething(player2Shape, targetCell);
	else if (playerTargetCell != 0) SetCellToSomething(player2Shape, playerTargetCell);
	else 
	{
		while (true)
		{
			if (SetCellToSomething(player2Shape, RandomStartingCell())) break; // Successfully placed the cell, exit the loop
		}
	}

	std::cout << "\nAI has placed\n";
}