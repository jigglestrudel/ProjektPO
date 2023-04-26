#pragma once
#include "./Organism.h"
#include "./Animal.h"

class Fox : public Animal
{
public:
	Fox(Vector2D position);
	virtual void giveBirth(Vector2D position) override;
	virtual void action() override;
};
