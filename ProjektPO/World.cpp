#include "World.h"
#include "Organism.h"
#include "Animal.h"
#include "Wolf.h"
#include "Sheep.h"
#include "Fox.h"
#include "Tortoise.h"
#include "Antilope.h"
#include "Plant.h"
#include "Grass.h"
#include "Dandelion.h"
#include "Guarana.h"
#include "Nightshade.h"
#include "Hogweed.h"
#include "Human.h"

World::World()
{
	humanAlive = false;
	height = 0;
	width = 0;
	roundCount = 0;
}

World::~World()
{
	for (Organism* organism : organisms)
	{
		delete organism;
	}
}

void World::shuffle()
{
	Organism* newOrganism;
	Vector2D position;

	for (int i = 100; i >= 0; i--)
	{
		position = Vector2D(std::rand() % getWidth(), std::rand() % getHeight());
		if (findOrganismAtPosition(position) != nullptr) continue;

		switch (Types::classID(std::rand() % 11))
		{
		case Types::WOLF:
			newOrganism = new Wolf(position);
			break;
		case Types::SHEEP:
			newOrganism = new Sheep(position);
			break;
		case Types::FOX:
			newOrganism = new Fox(position);
			break;
		case Types::TORTOISE:
			newOrganism = new Sheep(position);
			break;
		case Types::ANTILOPE:
			newOrganism = new Antilope(position);
			break;
		case Types::CYBERSHEEP:
			newOrganism = new Sheep(position);
			break;
		case Types::GRASS:
			newOrganism = new Grass(position);
			break;
		case Types::DANDELION:
			newOrganism = new Dandelion(position);
			break;
		case Types::GUARANA:
			newOrganism = new Guarana(position);
			break;
		case Types::NIGHTSHADE:
			newOrganism = new Nightshade(position);
			break;
		case Types::HOGWEED:
			newOrganism = new Hogweed(position);
			break;
		default:
			break;
		}
	}
}


int World::getHeight()
{
	return height;
}

int World::getWidth()
{
	return width;
}

void World::setHeight( int h)
{
	height = h;
}

void World::setWidth( int w)
{
	width = w;
}

void World::nextRound()
{
	history.clear();

	roundCount++;
	addEvent(string("Round ") + std::to_string(roundCount));
	manageOrganisms();
	clearCorpses();
	printState();
}

void World::addOrganism(Organism* organism)
{
	organism->setWorld(this);
	organisms.push_back(organism);
}


void World::clearCorpses()
{
	int position = 0;
	for (Organism* organism : organisms)
	{
		if (!organism->isAlive())
		{
			organisms.erase(organisms.begin() + position);
			delete organism;
		}
		position++;
	}
}


void World::manageOrganisms()
{
	Organism* colliding;

	std::sort(organisms.begin(), organisms.end(),
		[](Organism* left, Organism* right)
		{
			if (left->getInnitiative() == right->getInnitiative()) return left->getAge() > right->getAge();
			return left->getInnitiative() > right->getInnitiative();
		});

	int sizeBeforeTurn = organisms.size();
	Organism* organism;
	for (int i = 0; i < sizeBeforeTurn; i++)
	{
		organism = organisms[i];
		if (organism->isAlive())
		{
			organism->action();

			colliding = findOrganismAtPosition(organism);
			if (colliding != nullptr && colliding != organism && colliding->isAlive())
			{
				organism->collision(colliding);
			}

		}
		organism->makeOlder();
	}

}

Organism* World::findOrganismAtPosition(Vector2D position)
{
	for (Organism* organism : organisms)
	{
		if (organism->getPosition() == position)
			return organism;
	}
	return nullptr;
}

Organism* World::findOrganismAroundPosition(Vector2D position)
{
	for (int dx = -1; dx < 2; dx++)
	{
		for (int dy = -1; dy < 2; dy++)
		{
			if (dx != dy && (dx == 0 || dy == 0) &&
				isPointWithinBounds(position + Vector2D(dx, dy)) &&
				findOrganismAtPosition(position + Vector2D(dx, dy)) != nullptr &&
				findOrganismAtPosition(position + Vector2D(dx, dy))->isAlive())

				return findOrganismAtPosition(position + Vector2D(dx, dy));
		}
	
	}
	return nullptr;
}

Organism* World::findOrganismAtPosition(Organism* checkOrganism)
{
	for (Organism* organism : organisms)
	{
		if (organism->getPosition() == checkOrganism->getPosition() && organism != checkOrganism)
			return organism;
	}
	return nullptr;
}


bool World::isPointWithinBounds(Vector2D point)
{
	return point.x < getWidth() && point.x >= 0 &&
		point.y < getHeight() && point.y >= 0;
}

Vector2D World::findEmptyPlaceAround(Vector2D position)
{
	for (int dx = -1; dx < 2; dx++)
	{
		for (int dy = -1; dy < 2; dy++)
		{
			if (dx != dy && (dx == 0 || dy == 0) &&
				isPointWithinBounds(position + Vector2D(dx, dy)) &&
				findOrganismAtPosition(position + Vector2D(dx, dy)) == nullptr)

				return position + Vector2D(dx, dy);
		}
	}
	return Vector2D(-1, -1);
	
}

void World::addEvent(string message)
{
	history.push_back(message);
}

void World::printState()
{
	for (string mess : history)
	{
		std::cout << mess << "\n";
	}

	for (Organism* organism : organisms)
	{
		std::cout << organism->toString() << "\n";
	}
}

bool World::isHumanAlive()
{
	return humanAlive;
}

void World::killHuman()
{
	humanAlive = false;
}

void World::summonHuman()
{
	humanAlive = true;
	Human* person = new Human(Vector2D(width / 2, height / 2));
	if (findOrganismAtPosition(Vector2D(width / 2, height / 2)) != nullptr)
		findOrganismAtPosition(Vector2D(width / 2, height / 2))->die();
	addOrganism(person);
}

Organism* World::getHuman()
{
	if (humanAlive)
		for (Organism* organism : organisms)
		{
			if (organism->getID() == Types::HUMAN)
				return organism;
		}
	return nullptr;
}


