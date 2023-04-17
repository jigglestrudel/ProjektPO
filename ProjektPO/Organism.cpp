#include "Organism.h"

Organism::Organism()
{
	strength = 0;
	innitiative = 0;
	
	age = 0;
	alive = true;
	
	position = { 0, 0 };
	worldReference = nullptr;
}

Organism::Organism(int s, int i, Vector2D pos, World* wr)
{
	strength = s;
	innitiative = i;
	
	age = 0;
	alive = true;

	position = pos;
	worldReference = wr;
}

Organism::~Organism()
{
	std::cout << "organism " << this << " deleted\n";
}

int Organism::getStrength()
{
	return strength;
}

void Organism::setStrength(int strength)
{
	this->strength = strength;
}

int Organism::getInnitiative()
{
	return innitiative;
}

void Organism::setInnitiative(int innitiative)
{
	this->innitiative = innitiative;
}

int Organism::getAge()
{
	return age;
}

void Organism::makeOlder()
{
	age++;
}

bool Organism::isAlive()
{
	return alive;
}

void Organism::die()
{
	alive = false;
}

Vector2D Organism::getPosition()
{
	return position;
}

void Organism::setPosition(Vector2D position)
{
	this->position = position;
}

World* Organism::getWorld()
{
	return worldReference;
}

void Organism::setWorld(World* worldReference)
{
	this->worldReference = worldReference;
}
