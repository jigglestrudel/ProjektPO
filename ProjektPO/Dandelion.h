#pragma once
#include "Plant.h"

class Dandelion : public Plant
{
public:
	Dandelion(Vector2D position);
	virtual void action() override;
	virtual void spreadSeeds(Vector2D target) override;
};