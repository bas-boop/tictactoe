#include <iostream>
#include "AI.h"
#include "Grid.h"
#include "InputHandeler.h"

AIDifficulty currentDifficulty;

std::string GetAIDifficultyName(AIDifficulty difficulty) {
    switch (difficulty) {
    case AIDifficulty::Easy:
        return "Easy!";
    case AIDifficulty::Medium:
        return "Medium!";
    case AIDifficulty::Hard:
        return "Hard!";
    default:
        return "Unknown";
    }
}

void SetDifficulty(char target)
{
    AIDifficulty selectedDifficulty{};
    if (target == 'E') selectedDifficulty = AIDifficulty::Easy;
    else if (target == 'M') selectedDifficulty = AIDifficulty::Medium;
    else if (target == 'H') selectedDifficulty = AIDifficulty::Hard;

    currentDifficulty = selectedDifficulty;
    std::cout << "The computer has been set to: " << GetAIDifficultyName(currentDifficulty) << " ";
}

int RandomNumber()
{
	/* initialize random seed: */
	srand(time(NULL));

	/* generate secret number: */
	return rand() % 9 + 1;
}

void AIPlaceCell()
{
    switch (currentDifficulty) {
    case AIDifficulty::Easy:
        EasyPlacement();
        break;
    case AIDifficulty::Medium:
        MediumPlacement();
        break;
    case AIDifficulty::Hard:
        HardPlacement();
        break;
    }

	char charValue = static_cast<char>(player2Shape);
	std::cout << "\nThe computer has placed " << charValue << " "; 

	ShowGrid();
	AskWhereToPlace(SwitchPlayer(player2Shape), false);
}

void EasyPlacement() 
{
    while (true)
    {
        if (SetCellToSomething(player2Shape, RandomNumber())) break; // Successfully placed the cell, exit the loop
    }
}

void MediumPlacement()
{

}

void HardPlacement() 
{

}

