#pragma once
#include "Plant.h"

class Grass : public Plant
{
public:
	Grass(Vector2D position);
	virtual void spreadSeeds(Vector2D target) override;
};