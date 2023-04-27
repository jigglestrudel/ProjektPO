#pragma once
#include "./Organism.h"
#include "./Animal.h"

class Antilope : public Animal
{
public:
	Antilope(Vector2D position);
	virtual Antilope* giveBirth(Vector2D position) override;
	virtual void action() override;
	virtual bool didRunAway() override;
};
