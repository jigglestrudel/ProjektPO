#include "Fox.h"

Fox::Fox(Vector2D position)
{
	setID(FOX);
	setStrength(3);
	setInnitiative(7);
	setPosition(position);
	makeBreedable();
}

void Fox::giveBirth(Vector2D position)
{
	Fox* pup = new Fox(position);

	pup->bringToLife();

	this->getWorld()->addOrganism(pup);

	std::cout << pup << " NEW BABY FOX\n";
}
