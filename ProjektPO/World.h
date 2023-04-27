#pragma once
#include "Organism.h"
#include "Vector2D.h"
#include "GameManager.h"

#include <iostream>
#include <algorithm> 
#include <vector>
#include <string>
using std::vector;
using std::string;

class Vector2D;
class Organism;
class GameManager;

class World {
	friend class GameManager;

private:
	bool humanAlive;
	int height, width, roundCount;
	vector<Organism*> organisms;
	vector<string> history;

public:
	World();
	~World();

	void shuffle();



	int getHeight();
	void setHeight(int h);
	
	int getWidth();
	void setWidth(int w);

	void nextRound();

	void addOrganism(Organism* organism);

	void clearCorpses();

	void manageOrganisms();
	Organism* findOrganismAtPosition(Vector2D position);
	Organism* findOrganismAroundPosition(Vector2D position);
	Organism* findOrganismAtPosition(Organism* checkOrganism);
	
	bool isPointWithinBounds(Vector2D point);
	Vector2D findEmptyPlaceAround(Vector2D position);

	void addEvent(string message);
	void printState();

	bool isHumanAlive();
	void killHuman();
	void summonHuman();
	Organism* getHuman();

};