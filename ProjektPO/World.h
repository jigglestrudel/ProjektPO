#pragma once
#include "Organism.h"

#include <iostream>
#include <algorithm> 
#include <vector>
#include <string>
using std::vector;
using std::string;


class World {
private:
	unsigned int height, width, roundCount;
	vector<Organism&> organisms;
	vector<string> history;

public:
	World();
	~World();

	int getHeight();
	void setHeight(unsigned int h);
	
	int getWidth();
	void setWidht(unsigned int w);

	void nextRound();

	void addOrganism(Organism& organism);
	void clearCorpses();

	void manageOrganisms();
};