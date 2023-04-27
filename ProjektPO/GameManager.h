#pragma once
#include <iostream>
#include "World.h"


class World;
class Organism;

class GameManager {
private:
	World* world;
public:
	GameManager();
	~GameManager();

	void updateGame();
	void draw();
	void getInput();


};