#pragma once
#include "Organism.h"

class Animal : public Organism
{
private:
	bool canBreed;
	Vector2D positionBeforeAttack;


public:
	//bool isSubmissive();
	bool isBreedable();
	void makeBreedable();
	void makeImpotent();

	void goBack();

	virtual void action();
	virtual void collision(Organism* colliding);

	void breed(Animal* partner);
	virtual void giveBirth(Vector2D position) = 0;
	virtual void makeOlder() override;

	virtual bool didBounceOffAttack();
	virtual bool didRunAway();
};