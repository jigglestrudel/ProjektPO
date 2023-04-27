#include "Dandelion.h"

Dandelion::Dandelion(Vector2D position)
{
	setID(Types::DANDELION);
	setStrength(0);
	setPosition(position);
	bringToLife();
}

void Dandelion::action()
{
	for (int i = 0; i < 3; i++)
	{
		Plant::action();
	}
}

void Dandelion::spreadSeeds(Vector2D target)
{
	Dandelion* seeds = new Dandelion(target);

	sproutMessage(target);
	this->getWorld()->addOrganism(seeds);
}
