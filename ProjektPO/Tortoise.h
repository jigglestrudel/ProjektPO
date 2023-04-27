#pragma once
#include "./Organism.h"
#include "./Animal.h"

class Tortoise : public Animal
{
public:
	Tortoise(Vector2D position);
	virtual Tortoise* giveBirth(Vector2D position) override;
	virtual bool didBounceOffAttack(Organism* attacker) override;
	virtual void action() override;
};
