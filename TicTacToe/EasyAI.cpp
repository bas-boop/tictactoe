#include <iostream>
#include "EasyAI.h"
#include "InputHandeler.h"

int EasyAI::RandomNumber()
{
	srand(time(NULL));
	return rand() % 9 + 1;
}

void EasyAI::StartPlacing()
{
	int lastSpot = IsOneEmptySpotLeft();
	if (lastSpot != -1)   SetCellToSomething(player2Shape, lastSpot);
	else
	{
		while (true)
		{
			if (SetCellToSomething(player2Shape, RandomNumber())) break; // Successfully placed the cell, exit the loop
		}
	}
	
	std::cout << "\nAI has placed\n";
}