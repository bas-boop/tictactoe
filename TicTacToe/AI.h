#ifndef AI_H
#define AI_H
#include <iostream>

enum AIDifficulty { Easy, Medium, Hard };

void AIPlaceCell();
void SetDifficulty(char target);
std::string GetAIDifficultyName(AIDifficulty difficulty);

#endif