#pragma once
#include "./Organism.h"
#include "./Animal.h"

class Human : public Animal
{
private:
	bool specialPowerActivated;
	int powerTurnsLeft;
	Vector2D direction;

public:
	Human(Vector2D position);
	virtual void action() override;
	virtual Human* giveBirth(Vector2D position) override;

	bool isSpecialPowerActive();
	void activateSpecialPower();
	void specialPowerUpdate();
	bool specialPowerSuccess();

	Vector2D getDirection();
	void setDirection(Vector2D direction);
};
