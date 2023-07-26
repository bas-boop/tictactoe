#ifndef GRID_H
#define GRID_H
#include <iostream>

enum CellState { Empty = '.', Cross = 'X', Circle = 'O'};
extern CellState grid[3][3];

extern bool validCells[9];

void ShowGrid();
void SetGridEmpty();
bool CheckForThreeInARow(CellState state);
bool SetCellToSomething(CellState targetState, int place);
bool CheckForWinner();
bool IsValidCell(int place);
bool CheckForDraw();
int RandomNumber();

#endif