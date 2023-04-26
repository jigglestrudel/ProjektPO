#include "World.h"

World::World()
{
	std::srand(time(NULL));
	height = 0;
	width = 0;
	roundCount = 0;
}

World::~World()
{
	std::cout << "World deletion\n";
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

void World::setWidht( int w)
{
	width = w;
}

void World::nextRound()
{
	roundCount++;
	std::cout << roundCount << "\n";
	manageOrganisms();
	clearCorpses();
	printState();
}

void World::addOrganism(Organism* organism)
{
	organism->setWorld(this);
	toAdd.push_back(organism);
}

void World::addOrganismsToAdd()
{
	for (Organism* organism : toAdd)
	{
		organisms.push_back(organism);
	}
	toAdd.clear();
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
	Organism* colliding = nullptr;

	std::sort(organisms.begin(), organisms.end(),
		[](Organism* left, Organism* right)
		{
			if (left->getInnitiative() == right->getInnitiative()) return left->getAge() > right->getAge();
			return left->getInnitiative() > right->getInnitiative();
		});

	for (Organism* organism : organisms)
	{
		if (organism->isAlive())
		{
			organism->action();

			colliding = findOrganismAtPosition(organism->getPosition());
			if (colliding != nullptr && colliding != organism && colliding->isAlive())
			{
				organism->collision(colliding);
			}

		}
		organism->makeOlder();
	}

	addOrganismsToAdd();
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

Organism* World::findFutureOrganismAtPosition(Vector2D position)
{
	for (Organism* organism : toAdd)
	{
		if (organism->getPosition() == position)
			return organism;
	}
	return nullptr;
}

Vector2D World::findEmptyPlaceAround(Vector2D position)
{
	for (int dx = -1; dx < 2; dx++)
	{
		for (int dy = -1; dy < 2; dy++)
		{
			if (!(dx == 0 && dy == 0) &&
				position.x + dx >= 0 && position.x + dx < width &&
				position.y + dy >= 0 && position.y + dy < height &&
				findOrganismAtPosition({ position.x + dx , position.y + dy }) == nullptr &&
				findFutureOrganismAtPosition({ position.x + dx , position.y + dy }) == nullptr)

				return Vector2D({ position.x + dx , position.y + dy });
		}
	}
	//std::cout << "Didnt find an empty place aroud " << position << "\n";
	return Vector2D({-1, -1});
	
}

void World::printState()
{
	for (Organism* organism : organisms)
	{
		std::cout << organism << " " << organism->getID() << " age " << organism->getAge() << " at " << organism->getPosition() << "\n";
	}
}
