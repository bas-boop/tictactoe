#ifndef AI_H
#define AI_H

enum AIDifficulty { Easy, Medium, Hard };

void AIPlaceCell();
void SetDifficulty(char target);
std::string GetAIDifficultyName(AIDifficulty difficulty);
int RandomNumber();
void EasyPlacement();
void MediumPlacement();
void HardPlacement();

#endif