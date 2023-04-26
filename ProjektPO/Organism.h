#pragma once
#include "World.h"

#include <iostream>
#include <cstdlib>

class World;

typedef struct Vector2D
{
	int x, y;

	bool operator==(Vector2D right);
}Vector2D;

std::ostream& operator<<(std::ostream& os, Vector2D vector);

enum classID {
	WOLF,
	SHEEP,
	FOX,
	TORTOISE,
	ANTILOPE,
	CYBERSHEEP,

	CLASSIDBORDER,

	GRASS,
	DANDELION,
	GUARANA,
	NIGHTSHADE,
	HOGWEED,
};

class Organism {

private:
	classID id;
	int strength;
	int innitiative;

	int age;
	bool alive;

	Vector2D position;
	World* worldReference;

public:
	Organism();
	Organism(classID cl, int s, int i, Vector2D pos, World* wr);

	~Organism();

	void bringToLife();

	classID getID();
	void setID(classID id);

	int getStrength();
	void setStrength(int strength);

	int getInnitiative();
	void setInnitiative(int innitiative);

	int getAge();
	virtual void makeOlder();

	bool isAlive();
	void die();

	Vector2D getPosition();
	void setPosition(Vector2D position);

	World* getWorld();
	void setWorld(World* worldReference);

	virtual void action() = 0;
	virtual void collision(Organism* colliding) = 0;

};