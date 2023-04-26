#pragma once
#include "Organism.h"

#include <iostream>
#include <algorithm> 
#include <vector>
#include <string>
using std::vector;
using std::string;

struct Vector2D;
class Organism;

class World {
private:
	int height, width, roundCount;
	vector<Organism*> organisms;
	vector<Organism*> toAdd;
	vector<string> history;

public:
	World();
	~World();

	int getHeight();
	void setHeight(int h);
	
	int getWidth();
	void setWidht(int w);

	void nextRound();

	void addOrganism(Organism* organism);
	void addOrganismsToAdd();
	void clearCorpses();

	void manageOrganisms();
	Organism* findOrganismAtPosition(Vector2D position);
	Organism* findFutureOrganismAtPosition(Vector2D position);
	Vector2D findEmptyPlaceAround(Vector2D position);


	void printState();

};