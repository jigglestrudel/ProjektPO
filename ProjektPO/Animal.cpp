#include "Animal.h"

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

void Animal::goBack()
{
	std::cout << "going back ";
	setPosition(positionBeforeAttack);
}

void Animal::action()
{
	Vector2D position = getPosition();
	positionBeforeAttack = position;
	bool moved = false;

	while (!moved)
	switch (std::rand() % 4)
	{
	case 0:
		if (position.x < this->getWorld()->getWidth() - 1)
		{
			position.x++; 
			moved = true;
		}
		break;
	case 1:
		if (position.x > 0)
		{
			position.x--;
			moved = true;
		}
		break;
	case 2:
		if (position.y < this->getWorld()->getHeight() - 1)
		{
			position.y++;
			moved = true;
		}
		break;
	case 3:
		if (position.y > 0)
		{
			position.y--;
			moved = true;
		}
		break;
	}

	std::cout << this << " moved to " << position.x << ", " << position.y << "\n";
	setPosition(position);
}

void Animal::collision(Organism* colliding)
{
	if (colliding->getID() == this->getID())
	{
		std::cout << this << " <3 " << colliding << "\n";
		breed( (Animal*)colliding );
	}
	else
	{
		if (colliding->getID() < CLASSIDBORDER)
		{
			Animal* collidingAnimal = (Animal*)colliding;
			if (this->getStrength() >= collidingAnimal->getStrength() &&
				!collidingAnimal->didRunAway() && collidingAnimal->didBounceOffAttack())
			{
				collidingAnimal->die();
			}
			else if (this->getStrength() < collidingAnimal->getStrength())
			{
				this->die();
				//komunikat
			}
		}
	}

}

void Animal::breed(Animal* partner)
{
	goBack();
	if (this->canBreed && partner->isBreedable())
	{
		Vector2D birthPlace = this->getWorld()->findEmptyPlaceAround(partner->getPosition());
		if (birthPlace == Vector2D({-1, -1})) 
			birthPlace = this->getWorld()->findEmptyPlaceAround(this->getPosition());
		if (birthPlace == Vector2D({ -1, -1 }))
		{
			return;
		}
		else
		{

			partner->giveBirth(birthPlace);

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

bool Animal::didBounceOffAttack()
{
	return false;
}

bool Animal::didRunAway()
{
	return false;
}
