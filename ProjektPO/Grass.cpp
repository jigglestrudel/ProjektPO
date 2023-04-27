#include "Grass.h"

Grass::Grass(Vector2D position)
{
	setID(Types::GRASS);
	setStrength(0);
	setPosition(position);
	bringToLife();
}

void Grass::spreadSeeds(Vector2D target)
{
	Grass* seeds = new Grass(target);
	
	sproutMessage(target);
	this->getWorld()->addOrganism(seeds);
}
