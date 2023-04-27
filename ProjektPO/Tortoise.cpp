#include "Tortoise.h"

Tortoise::Tortoise(Vector2D position)
{
	setID(Types::TORTOISE);
	setStrength(2);
	setInnitiative(1);
	setPosition(position);
	makeBreedable();
}

Tortoise* Tortoise::giveBirth(Vector2D position)
{
	Tortoise* hatched_egg = new Tortoise(position);

	hatched_egg->bringToLife();

	return hatched_egg;
}

bool Tortoise::didBounceOffAttack(Organism* attacker)
{
	if (attacker->getStrength() < 5)
	{
		this->getWorld()->addEvent(this->toString() + " hid in its shell from the attacker");
		return true;
	}
	else
	{
		this->getWorld()->addEvent(this->toString() + " had its shell crushed");
		return false;
	}
}

void Tortoise::action()
{
	if (std::rand() % 4 == 0)
	{
		Animal::action();
	}
}
