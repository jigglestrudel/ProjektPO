// ProjektPO.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
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

int main()
{
	World* earth = new World;
	earth->setHeight(2);
	earth->setWidth(2);
	/*Wolf* wilk1 = new Wolf({ 0, 0 });
	Wolf* wilk2 = new Wolf({ 1, 0 });
	Sheep* owca1 = new Sheep({ 0, 2 });
	Sheep* owca2 = new Sheep({ 1, 2 });
	Sheep* owca3 = new Sheep({ 2, 1 });*/
	Sheep* owca4 = new Sheep({ 1, 1 });
	/*Fox* lis1 = new Fox({ 3, 1 });
	Fox* lis2 = new Fox({ 2, 2 });
	Tortoise* zolw1 = new Tortoise({ 3, 3 });
	Tortoise* zolw2 = new Tortoise({ 3, 5 });
	Antilope* antylopa1 = new Antilope({ 4, 4 });
	Antilope* antylopa2 = new Antilope({ 4, 5 });*/

	//Grass* trawa1 = new Grass({ 0, 0 });
	Dandelion* mlecz1 = new Dandelion({ 0, 0 });
	

	/*earth->addOrganism(wilk1);
	earth->addOrganism(wilk2);
	earth->addOrganism(owca1);
	earth->addOrganism(owca2);
	earth->addOrganism(owca3);*/
	earth->addOrganism(owca4);
	//earth->addOrganism(lis1);
	//earth->addOrganism(lis2);
	//earth->addOrganism(zolw1);
	//earth->addOrganism(zolw2);
	//earth->addOrganism(antylopa1);
	//earth->addOrganism(antylopa2);
	//earth->addOrganism(trawa1);
	earth->addOrganism(mlecz1);

	while (true)
	{
		earth->nextRound();
		std::cin.get();
	}
	
	//earth->printState();

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
