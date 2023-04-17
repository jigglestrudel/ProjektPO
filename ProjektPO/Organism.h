#pragma once
#include <iostream>

class World;

typedef struct Vector2D
{
	int x, y;
};


class Organism {

private:
	int strength;
	int innitiative;

	int age;
	bool alive;

	Vector2D position;
	World* worldReference;

public:
	Organism();
	Organism(int s, int i, Vector2D pos, World* wr);

	~Organism();

	int getStrength();
	void setStrength(int strength);

	int getInnitiative();
	void setInnitiative(int innitiative);

	int getAge();
	void makeOlder();

	bool isAlive();
	void die();

	Vector2D getPosition();
	void setPosition(Vector2D position);

	World* getWorld();
	void setWorld(World* worldReference);

	virtual void action() = 0;
	virtual void collision() = 0;

};