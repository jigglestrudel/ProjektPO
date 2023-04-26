#include "Organism.h"

Organism::Organism()
{
	id = classID(0);

	strength = 0;
	innitiative = 0;
	
	age = 0;
	alive = true;
	
	position = { 0, 0 };
	worldReference = nullptr;
}

Organism::Organism(classID cl, int s, int i, Vector2D pos, World* wr)
{
	id = cl;
	strength = s;
	innitiative = i;
	
	age = 0;
	alive = true;

	position = pos;
	worldReference = wr;
}

void Organism::bringToLife()
{

	age = 0;
	alive = true;
}

Organism::~Organism()
{
	std::cout << "organism " << this << " deleted\n";
}

classID Organism::getID()
{
	return id;
}

void Organism::setID(classID id)
{
	this->id = id;
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
	//std::cout << this << " " <<  this->position;
	this->position = position;
	//std::cout << this->position << "\n";

}

World* Organism::getWorld()
{
	return worldReference;
}

void Organism::setWorld(World* worldReference)
{
	this->worldReference = worldReference;
}

bool Vector2D::operator==(Vector2D right)
{
	return this->x == right.x && this->y == right.y;
}

std::ostream& operator<<(std::ostream& os, Vector2D vector)
{
	os << "(" << vector.x << ", " << vector.y << ")";
	return os;
}
