#pragma once
#include "Plant.h"

class Nightshade : public Plant
{
public:
	Nightshade(Vector2D position);
	virtual void collision(Organism* eater) override;
	virtual void spreadSeeds(Vector2D target) override;
};