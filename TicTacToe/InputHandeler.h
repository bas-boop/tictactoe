#ifndef INPUTHANDELER_H
#define INPUTHANDELER_H
#include "Grid.h"

extern CellState playerShape;
extern CellState player2Shape;

void ShowStartDialogue();
void AskWhereToPlace(CellState currentPlayer);
void AskAgain(CellState currentPlayer);
bool PlayAgain();

#endif