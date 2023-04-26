// ProjektPO.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "World.h"
#include "Organism.h"
#include "Animal.h"
#include "Wolf.h"
#include "Sheep.h"

int main()
{
	World* earth = new World;
	earth->setHeight(10);
	earth->setWidht(10);
	Wolf* wilk1 = new Wolf({ 0, 0 });
	//Wolf* wilk2 = new Wolf({ 1, 0 });
	//Wolf* wilk3 = new Wolf({ 0, 1 });
	Sheep* owca1 = new Sheep({ 0, 2 });
	Sheep* owca2 = new Sheep({ 1, 2 });
	Sheep* owca3 = new Sheep({ 2, 2 });
	Sheep* owca4 = new Sheep({ 3, 2 });
	Sheep* owca5 = new Sheep({ 4, 2 });

	earth->addOrganism(wilk1);
	//earth->addOrganism(wilk2);
	//earth->addOrganism(wilk3);
	earth->addOrganism(owca1);
	earth->addOrganism(owca2);
	earth->addOrganism(owca3);
	earth->addOrganism(owca4);
	earth->addOrganism(owca5);

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
