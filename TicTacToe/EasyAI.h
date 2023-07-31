#ifndef	EASYAI_H
#define EASYAI_H

#include "BaseAI.h"

class BaseAI; // Forward declaration

class EasyAI : public BaseAI
{
private:
	int RandomNumber();

public:
	void StartPlacing() override;
};

#endif