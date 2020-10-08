#pragma once
#include "Item.h"

#define POWER_HP_RESTORE			2

#define POWERUP_DISPLAY_DURATION	4500
#define POWERUP_DELAY				600

class PowerUp : public Item
{
public:
	PowerUp(float posX, float posY);
	~PowerUp();
};

