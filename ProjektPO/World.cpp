#include "World.h"

World::World()
{
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

void World::setHeight(unsigned int h)
{
	height = h;
}

void World::setWidht(unsigned int w)
{
	width = w;
}

void World::nextRound()
{
	roundCount++;


}

void World::addOrganism(Organism& organism)
{
	organism.setWorld(this);
	organisms.push_back(organism);
}

void World::clearCorpses()
{
	int position = 0;
	for (Organism& organism : organisms)
	{
		if (!organism.isAlive())
		{
			organisms.erase(organisms.begin() + position);
			delete &organism;
		}
		position++;
	}
}

void World::manageOrganisms()
{
	std::sort(organisms.begin(), organisms.end(), 
		[](Organism* left, Organism* right)
		{
			if (left->getInnitiative() == right->getInnitiative())
		})

}
