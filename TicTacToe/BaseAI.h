#ifndef BASEAI_H
#define BASEAI_H

#include "AI.h"

class BaseAI
{
public:
	AIDifficulty currentDifficulty;

	BaseAI();
	virtual ~BaseAI();

	virtual void StartPlacing() = 0;
};

#endif