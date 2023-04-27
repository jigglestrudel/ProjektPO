#pragma once
#include "./Organism.h"
#include "./Animal.h"

class Wolf : public Animal
{
public:
	Wolf(Vector2D position);
	virtual Wolf* giveBirth(Vector2D position) override;
};
