#include "Sheep.h"

Sheep::Sheep(Vector2D position)
{

	setID(Types::SHEEP);
	setStrength(4);
	setInnitiative(4);
	setPosition(position);
	makeBreedable();
}

Sheep* Sheep::giveBirth(Vector2D position)
{
	Sheep* lamb = new Sheep(position);

	lamb->bringToLife();

	return lamb;
}
