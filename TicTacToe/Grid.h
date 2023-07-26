#ifndef MAIN_H
#define MAIN_H
#include <iostream>

enum CellState { Empty = '.', Cross = 'X', Circle = 'O'};
extern CellState playerShape;
extern CellState player2Shape;

extern CellState grid[3][3];

extern bool validCells[9];

void ShowStartDialogue();
void ShowGrid();
bool CheckForThreeInARow(CellState state);
void SetGridEmpty();
void AskWhereToPlace(CellState currentPlayer);
bool SetCellToSomething(CellState targetState, int place);
int RandomNumber();
bool CheckForWinner();
bool IsValidCell(int place);
bool CheckForDraw();
void AskAgain(CellState currentPlayer);

#endif // !MAIN_H