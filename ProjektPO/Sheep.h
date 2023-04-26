#pragma once
#include "./Organism.h"
#include "./Animal.h"

class Sheep : public Animal {
public:
	Sheep(Vector2D position);
	virtual void giveBirth(Vector2D position) override;
};