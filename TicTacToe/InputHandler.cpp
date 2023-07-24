#include <iostream>
//#include <string>
#include "Grid.h"

char inputPlayerShape;
CellState playerShape;

void ShowStartDialogue()
{
	std::cout << "Welcome to C++ Tic-Tac-Toe\nHere you can play a old time classic game.\nDo you want to be the cross or circle?\n";
	while (inputPlayerShape != 'X' || inputPlayerShape != 'O')
	{
		std::cin >> inputPlayerShape;
		std::cout << "\nTyp X or O.";
	}
	if (inputPlayerShape == 'X') playerShape = CellState::Cross;
	else if(inputPlayerShape == 'O') playerShape = CellState::Circle;
}