#include "Nightshade.h"

Nightshade::Nightshade(Vector2D position)
{
	setID(Types::NIGHTSHADE);
	setStrength(10);
	setPosition(position);
	bringToLife();
}

void Nightshade::collision(Organism* eater)
{
	eater->die();
	Plant::die();
}

void Nightshade::spreadSeeds(Vector2D target)
{
	Nightshade* seeds = new Nightshade(target);

	sproutMessage(target);
	this->getWorld()->addOrganism(seeds);
}
