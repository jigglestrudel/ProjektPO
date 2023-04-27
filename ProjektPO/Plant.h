#pragma once
#include "Organism.h"

class Plant : public Organism {

public:


	virtual void die() override;
	virtual void spreadSeeds(Vector2D target) = 0;
	virtual void sproutMessage(Vector2D target);

	virtual void action() override;
	virtual void collision(Organism* colliding) override;
};