#include "Antilope.h"

Antilope::Antilope(Vector2D position)
{
	setID(Types::ANTILOPE);
	setStrength(4);
	setInnitiative(4);
	setPosition(position);
	makeBreedable();
}

Antilope* Antilope::giveBirth(Vector2D position)
{
	Antilope* calve = new Antilope(position);

	calve->bringToLife();

	return calve;
}

void Antilope::action()
{
	std::vector<Vector2D> possibleMoves;
	possibleMoves.push_back(Vector2D(1, 1));
	possibleMoves.push_back(Vector2D(-1, 1));
	possibleMoves.push_back(Vector2D(1, -1));
	possibleMoves.push_back(Vector2D(-1, -1));
	possibleMoves.push_back(Vector2D(2, 0));
	possibleMoves.push_back(Vector2D(0, 2));
	possibleMoves.push_back(Vector2D(-2, 0));
	possibleMoves.push_back(Vector2D(0, -2));

	makeLegalMove(possibleMoves);
}

bool Antilope::didRunAway()
{
	if (std::rand() % 2 == 0)
	{
		Vector2D runAwayPlace = getWorld()->findEmptyPlaceAround(this->getPosition());
		if (!(runAwayPlace == Vector2D(-1, -1)))
		{
			this->getWorld()->addEvent(this->toString() + string(" runs away to ") + runAwayPlace.toString());
			setPosition(runAwayPlace);
			return true;
		}
	}

	return false;

}
