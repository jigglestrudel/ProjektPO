#include "Animal.h"

Animal::Animal()
{
	canBreed = false;
	positionBeforeAttack = getPosition();
}

bool Animal::isBreedable()
{
	return canBreed;
}

void Animal::makeBreedable()
{
	canBreed = true;
}

void Animal::makeImpotent()
{
	canBreed = false;
}

void Animal::die()
{
	this->getWorld()->addEvent(this->toString() + string(" has died"));
	Organism::die();
}

void Animal::goBack()
{
	//this->getWorld()->addEvent(this->toString() + string(" goes back to ") + positionBeforeAttack.toString());
	setPosition(positionBeforeAttack);
}

void Animal::action()
{
	positionBeforeAttack = getPosition();
	
	std::vector<Vector2D> possibleMoves;
	possibleMoves.push_back(Vector2D(1, 0));
	possibleMoves.push_back(Vector2D(0, 1));
	possibleMoves.push_back(Vector2D(-1, 0));
	possibleMoves.push_back(Vector2D(0, -1));

	makeLegalMove(possibleMoves);
}

void Animal::makeLegalMove(std::vector<Vector2D> possibleMoves)
{
	Vector2D position = getPosition();
	

	Vector2D possibleDestination;
	for (int i = 0; i < possibleMoves.size(); i++)
	{
		possibleDestination = position + possibleMoves[i];
		if (!checkIfDestinationLegal(possibleDestination))
		{
			possibleMoves.erase(possibleMoves.begin() + i);
			i--;
		}
	}

	if (possibleMoves.size() != 0)
	{
		position = position + possibleMoves[std::rand() % possibleMoves.size()];

		setPosition(position);
	}
	
}

bool Animal::checkIfDestinationLegal(Vector2D possibleDestination)
{
	return this->getWorld()->isPointWithinBounds(possibleDestination);
}

void Animal::collision(Organism* colliding)
{
	this->getWorld()->addEvent(this->toString() + string(" moved from ") + this->positionBeforeAttack.toString() + string(" and stumbled upon ") + colliding->toString());
	
	if (dynamic_cast<Animal*>(colliding) != nullptr)
	{
		this->getWorld()->addEvent(string("It looks like a fight is about to breakout between ") + getString(this->getID()) + string(" and ") + colliding->toString());
		Animal* collidingAnimal = (Animal*)colliding;
		if (colliding->getID() == this->getID())
		{
			breed((Animal*)colliding);
		}
		else
		{
			if (this->didRunAway())
			{
				this->getWorld()->addEvent(this->toString() + string(" chickened out"));
			}
			else if (collidingAnimal->didBounceOffAttack(this) || this->didBounceOffAttack(collidingAnimal))
			{
				goBack();
			}
			else if (collidingAnimal->didRunAway())
			{
				this->getWorld()->addEvent(this->toString() + string(" was too slow for the ") + collidingAnimal->toString());
			}
			else if (this->getStrength() >= collidingAnimal->getStrength())
			{
				collidingAnimal->die();
			}
			else
			{
				this->die();
			}
		}
	}
	else if (dynamic_cast<Plant*>(colliding) != nullptr)
	{
		this->getWorld()->addEvent(this->toString() + string(" has decided to eat ") + colliding->toString());

		Plant* collidingPlant = (Plant*)colliding;
		collidingPlant->collision(this);
	}
	

}

void Animal::breed(Animal* partner)
{
	goBack();
	this->getWorld()->addEvent(this->toString() + string(" and ") + partner->toString() + string(" thought the world needed another " + getString(this->getID())));

	if (this->canBreed && partner->isBreedable())
	{
		Vector2D birthPlace = this->getWorld()->findEmptyPlaceAround(partner->getPosition());

		if (birthPlace == Vector2D(-1, -1)) 
			birthPlace = this->getWorld()->findEmptyPlaceAround(this->getPosition());

		if (birthPlace == Vector2D( -1, -1 ))
		{
			this->getWorld()->addEvent(this->toString() + string(" and ") + partner->toString() + string(" decided they should see other animals"));
			return;
		}
		else
		{
			Animal* child = partner->giveBirth(birthPlace);

			this->getWorld()->addOrganism(child);
			this->getWorld()->addEvent(child->birthMessage());

			this->makeImpotent();
			partner->makeImpotent();

		}
	}
}

void Animal::makeOlder()
{
	Organism::makeOlder();
	makeBreedable();
}

std::string Animal::birthMessage()
{
	return std::string(this->toString() + std::string(" has materialised out of thin air"));
}

bool Animal::didBounceOffAttack(Organism* attacker)
{
	return false;
}

bool Animal::didRunAway()
{
	return false;
}
