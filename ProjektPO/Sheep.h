#pragma once
#include "./Organism.h"
#include "./Animal.h"

class Sheep : public Animal {
public:
	Sheep(Vector2D position);
	virtual Sheep* giveBirth(Vector2D position) override;
};