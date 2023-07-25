#ifndef MAIN_H
#define MAIN_H
#include <iostream>

enum CellState { Empty = '.', Cross = 'X', Circle = 'O'};
extern CellState playerShape;
extern CellState player2Shape;

extern CellState grid[3][3];

void ShowStartDialogue();
void ShowGrid();
bool CheckForThreeInARow(CellState state);
void SetGridEmpty();
void AskWhereToPlace(CellState currentPlayer);
void SetCellToSomething(CellState targetState, int place);
int RandomNumber();
bool CheckForWinner();

#endif // !MAIN_H