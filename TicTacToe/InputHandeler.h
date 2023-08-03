#ifndef INPUTHANDELER_H
#define INPUTHANDELER_H
#include "Grid.h"

extern CellState playerShape;
extern CellState player2Shape;

void ShowStartDialogue();
void AskCoopOrAI();
void AskWhereToPlace(CellState currentPlayer, bool isAITurn = false);
void AskAgain(CellState currentPlayer);
void PlayerPlace(CellState currentPlayer);
void AIPLace(CellState aiPlayer);
void ChooseShape();
void AskWichDifficulty();
void SetAIToEmpty();
void InValidInput(CellState currentPlayer);
bool PlayAgain();
CellState CoinFlip();
CellState SwitchPlayer(CellState currentPlayer);

#endif