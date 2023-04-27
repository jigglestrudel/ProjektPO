#pragma once
#include "Plant.h"

class Hogweed : public Plant
{
public:
	Hogweed(Vector2D position);
	virtual void action() override;
	virtual void collision(Organism* eater) override;
	virtual void spreadSeeds(Vector2D target) override;
};