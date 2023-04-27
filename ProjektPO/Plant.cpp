#include "Plant.h"

void Plant::die()
{
	this->getWorld()->addEvent(this->toString() + string(" has been eaten"));
	Organism::die();
}

void Plant::sproutMessage(Vector2D target)
{
	this->getWorld()->addEvent(string("Seeds of ") + this->toString() + string(" have sprouted at ") + target.toString());
}

void Plant::action()
{
	std::vector<Vector2D> possibleSeeds;
	possibleSeeds.push_back(Vector2D(1, 0));
	possibleSeeds.push_back(Vector2D(0, 1));
	possibleSeeds.push_back(Vector2D(-1, 0));
	possibleSeeds.push_back(Vector2D(0, -1));

	Vector2D seedSpread = getPosition() + possibleSeeds[std::rand() % 4];

	if (this->getWorld()->isPointWithinBounds(seedSpread) && this->getWorld()->findOrganismAtPosition(seedSpread) == nullptr && std::rand() % 2)
	{
		this->spreadSeeds(seedSpread);
	}
}

void Plant::collision(Organism* colliding)
{
	this->die();
}

