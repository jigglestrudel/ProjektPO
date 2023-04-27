#include "Guarana.h"

Guarana::Guarana(Vector2D position)
{
	setID(Types::GUARANA);
	setStrength(0);
	setPosition(position);
	bringToLife();
}

void Guarana::collision(Organism* eater)
{
	eater->setStrength(eater->getStrength() + 3);
	Plant::collision(eater);
}

void Guarana::spreadSeeds(Vector2D target)
{

	Guarana* seeds = new Guarana(target);

	sproutMessage(target);
	this->getWorld()->addOrganism(seeds);

}
