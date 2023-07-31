#include <iostream>
//#include "BaseAI.h"
#include "HardAI.h"
#include "InputHandeler.h"

int HardAI::RandomNumber()
{
	/* initialize random seed: */
	srand(time(NULL));

	/* generate secret number: */
	return rand() % 9 + 1;
}

void HardAI::StartPlacing()
{
	while (true)
	{
		if (SetCellToSomething(player2Shape, RandomNumber())) break; // Successfully placed the cell, exit the loop
	}
	std::cout << "\nAI has placed\n";
}