#include "GameManager.h"

GameManager::GameManager()
{
	std::srand(time(NULL));
	world = new World();

	world->setHeight(25);
	world->setWidth(25);

	world->shuffle();
	world->summonHuman();


}

GameManager::~GameManager()
{
	delete world;
}

void GameManager::updateGame()
{
	world->nextRound();
}
