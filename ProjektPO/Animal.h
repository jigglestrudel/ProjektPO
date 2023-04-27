#pragma once
#include "Organism.h"
#include "Plant.h"

class Plant;

class Animal : public Organism
{
private:
	bool canBreed;
	Vector2D positionBeforeAttack;

	
public:
	Animal();

	bool isBreedable();
	void makeBreedable();
	void makeImpotent();

	virtual void die() override;

	void goBack();

	virtual void action();
	virtual void makeLegalMove(std::vector<Vector2D> possibleMoves);
	virtual bool checkIfDestinationLegal(Vector2D possibleDestination);
	virtual void collision(Organism* colliding);

	void breed(Animal* partner);
	virtual Animal* giveBirth(Vector2D position) = 0;
	virtual void makeOlder() override;
	virtual std::string birthMessage();

	virtual bool didBounceOffAttack(Organism* attacker);
	virtual bool didRunAway();
};