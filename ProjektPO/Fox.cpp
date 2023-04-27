#include "Fox.h"

Fox::Fox(Vector2D position)
{
	setID(Types::FOX);
	setStrength(3);
	setInnitiative(7);
	setPosition(position);
	makeBreedable();
}

Fox* Fox::giveBirth(Vector2D position)
{
	Fox* pup = new Fox(position);

	pup->bringToLife();

	return pup;
}

bool Fox::checkIfDestinationLegal(Vector2D possibleDestination)
{
	bool goodSmell = getWorld()->findOrganismAtPosition(possibleDestination) != nullptr &&
		getWorld()->findOrganismAtPosition(possibleDestination)->getStrength() > getStrength();

	if (goodSmell)
	{
		this->getWorld()->addEvent(this->toString() + " has smelled danger at " + possibleDestination.toString());
	}

	return Animal::checkIfDestinationLegal(possibleDestination) && !(goodSmell);
}

