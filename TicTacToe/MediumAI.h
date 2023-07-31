#ifndef	MEDIUMAI_H
#define MEDIUMAI_H

#include "BaseAI.h"

class BaseAI; // Forward declaration

class MediumAI : public BaseAI
{
private:
	int RandomNumber();

public:
	void StartPlacing() override;
};

#endif
