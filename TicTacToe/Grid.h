#ifndef MAIN_H
#define MAIN_H
#include <iostream>

enum CellState { Empty = '.', Cross = 'X', Circle = 'O'};
extern CellState playerShape;

extern CellState grid[3][3];

void ShowStartDialogue();
void ShowGrid();
bool CheckForThreeInARow(CellState state);
void SetGridEmpty();

#endif // !MAIN_H