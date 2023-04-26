#include "Wolf.h"

Wolf::Wolf(Vector2D position)
{
	setID(WOLF);
	setStrength(9);
	setInnitiative(5);
	setPosition(position);
	makeBreedable();
}

void Wolf::giveBirth(Vector2D position)
{
	Wolf* pup = new Wolf(position);

	pup->bringToLife();

	this->getWorld()->addOrganism(pup);

	std::cout << pup << " NEW BABY WOLF\n";
	// komunikat
}
