#include <iostream>
#include "AI.h"
#include "EasyAI.h"
#include "MediumAI.h"
#include "HardAI.h"
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

void AIPlaceCell()
{
    EasyAI easy;
    MediumAI medium;
    HardAI hard;
    
    switch (currentDifficulty) {
    case AIDifficulty::Easy:
        easy.StartPlacing();
        break;
    case AIDifficulty::Medium:
        medium.StartPlacing();
        break;
    case AIDifficulty::Hard:
        hard.StartPlacing();
        break;
    }

	char charValue = static_cast<char>(player2Shape);
	std::cout << "\nThe computer has placed " << charValue << " "; 

	ShowGrid();
	AskWhereToPlace(SwitchPlayer(player2Shape), false);
}
