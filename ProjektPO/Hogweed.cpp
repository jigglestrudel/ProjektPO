#include "Hogweed.h"

Hogweed::Hogweed(Vector2D position)
{
	setID(Types::HOGWEED);
	setStrength(99);
	setPosition(position);
	bringToLife();
}

void Hogweed::action()
{
	Organism* victim = this->getWorld()->findOrganismAroundPosition(this->getPosition());
	while (victim != nullptr)
	{
		this->getWorld()->addEvent(victim->toString() + string(" was too close the ") + this->toString());
		victim->die();
		victim = this->getWorld()->findOrganismAroundPosition(this->getPosition());
	}

}

void Hogweed::collision(Organism* eater)
{
	eater->die();
	Plant::die();
}

void Hogweed::spreadSeeds(Vector2D target)
{
	Hogweed* seeds = new Hogweed(target);

	sproutMessage(target);
	this->getWorld()->addOrganism(seeds);
}
