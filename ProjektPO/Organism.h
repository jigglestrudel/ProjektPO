#pragma once
#include "World.h"
#include "Vector2D.h"

#include <iostream>
#include <cstdlib>

class World;

namespace Types
{
	enum classID {
			WOLF,
			SHEEP,
			FOX,
			TORTOISE,
			ANTILOPE,
			CYBERSHEEP,

			GRASS,
			DANDELION,
			GUARANA,
			NIGHTSHADE,
			HOGWEED,

			HUMAN,
		};

	std::string getString(classID id);

}


class Organism {

private:

	Types::classID id;
	int strength;
	int innitiative;

	int age;
	bool alive;

	Vector2D position;
	World* worldReference;

public:
	Organism();
	~Organism();

	void bringToLife();

	Types::classID getID();
	void setID(Types::classID id);

	int getStrength();
	void setStrength(int strength);

	int getInnitiative();
	void setInnitiative(int innitiative);

	int getAge();
	virtual void makeOlder();

	bool isAlive();
	virtual void die();

	Vector2D getPosition();
	void setPosition(Vector2D position);

	World* getWorld();
	void setWorld(World* worldReference);

	std::string toString();

	virtual void action() = 0;
	virtual void collision(Organism* colliding) = 0;

	friend std::ostream& operator<<(std::ostream& os, Organism organism);
};