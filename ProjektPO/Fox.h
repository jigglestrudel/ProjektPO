#pragma once
#include "./Organism.h"
#include "./Animal.h"

class Fox : public Animal
{
public:
	Fox(Vector2D position);
	virtual Fox* giveBirth(Vector2D position) override;
	virtual bool checkIfDestinationLegal(Vector2D possibleDestination) override;
};
