#include "Human.h"

Human::Human(Vector2D position)
{
	setID(Types::HUMAN);
	setStrength(5);
	setInnitiative(4);
	setPosition(position);
	makeImpotent();
	bringToLife();
	specialPowerActivated = false;
	powerTurnsLeft = 0;
}

void Human::action()
{
	if (specialPowerSuccess())
	{
		this->getWorld()->addEvent(this->toString() + string(" feels as fast as an antilope"));
		direction = direction * 2;
	}
	if (checkIfDestinationLegal(getPosition() + direction))
		setPosition(getPosition() + direction);

	direction = Vector2D(0, 0);
}

Human* Human::giveBirth(Vector2D position)
{
	this->getWorld()->addEvent("Divine intervention!");

	Human* kid = new Human(position);

	return kid;
}

bool Human::isSpecialPowerActive()
{
	return specialPowerActivated;
}

void Human::activateSpecialPower()
{
	specialPowerActivated = true;
	powerTurnsLeft = 5;
}

void Human::specialPowerUpdate()
{
	powerTurnsLeft--;
	if (powerTurnsLeft == 0)
		specialPowerActivated = false;
}

bool Human::specialPowerSuccess()
{
	return specialPowerActivated && (powerTurnsLeft >= 3 || std::rand() % 2);
}

Vector2D Human::getDirection()
{
	return direction;
}

void Human::setDirection(Vector2D direction)
{
	this->direction = direction;
}
