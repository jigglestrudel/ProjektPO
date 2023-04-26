#include "Sheep.h"

Sheep::Sheep(Vector2D position)
{

	setID(SHEEP);
	setStrength(4);
	setInnitiative(4);
	setPosition(position);
	makeBreedable();
}

void Sheep::giveBirth(Vector2D position)
{
	Sheep* lamb = new Sheep(position);

	lamb->bringToLife();

	this->getWorld()->addOrganism(lamb);

	std::cout << lamb << " NEW BABY SHEEP\n";
	// komunikat
}
