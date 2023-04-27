#pragma once
#include "Plant.h"

class Guarana : public Plant
{
public:
	Guarana(Vector2D position);
	virtual void collision(Organism* eater) override;
	virtual void spreadSeeds(Vector2D target) override;
};