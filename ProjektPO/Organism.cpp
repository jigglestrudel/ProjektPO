#include "Organism.h"


Organism::Organism()
{
	id = Types::classID(0);

	strength = 0;
	innitiative = 0;
	
	age = 0;
	alive = true;
	
	position = { 0, 0 };
	worldReference = nullptr;
}


void Organism::bringToLife()
{
	age = 0;
	alive = true;
}

Organism::~Organism()
{
}

Types::classID Organism::getID()
{
	return id;
}

void Organism::setID(Types::classID id)
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


 std::string Organism::toString()
{
	std::string str;
	str += Types::getString(this->getID()); 
	str += std::string(" at ");
	str += this->getPosition().toString();
	return str;
}

 std::string Types::getString(Types::classID id)
 {
	 std::string str;
	 switch (id)
	 {
	 case WOLF:
		 str = "Wolf";
		 break;
	 case SHEEP:
		 str = "Sheep";
		 break;
	 case FOX:
		 str = "Fox";
		 break;
	 case TORTOISE:
		 str = "Tortoise";
		 break;
	 case ANTILOPE:
		 str = "Antilope";
		 break;
	 case CYBERSHEEP:
		 str = "Cybersheep";
		 break;
	 case GRASS:
		 str = "Grass";
		 break;
	 case DANDELION:
		 str = "Dandelion";
		 break;
	 case GUARANA:
		 str = "Guarana";
		 break;
	 case NIGHTSHADE:
		 str = "Deadly nightshade";
		 break;
	 case HOGWEED:
		 str = "Heracleum sosnowskyi";
		 break;
	 default:
		 str = "UNKNOWN TYPE";
		 break;
	 }

	 return str;
 }
