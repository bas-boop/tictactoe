#ifndef	HARDAI_H
#define HARDAI_H

#include "BaseAI.h"

class BaseAI; // Forward declaration

class HardAI : public BaseAI
{
private:
	int RandomStartingCell();

public:
	void StartPlacing() override;
};

#endif