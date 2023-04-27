#include "Wolf.h"

Wolf::Wolf(Vector2D position)
{
	setID(Types::WOLF);
	setStrength(9);
	setInnitiative(5);
	setPosition(position);
	makeBreedable();
}

Wolf* Wolf::giveBirth(Vector2D position)
{
	Wolf* pup = new Wolf(position);

	pup->bringToLife();

	return pup;
}
