#include "Acceptor.h"
#include "StateBehaviour.h"
#include <iostream>

Acceptor::Acceptor()
{
	nrOfStates = 0;
}

Acceptor::Acceptor(unsigned int n)
{
	nrOfStates = n;
}

Acceptor::~Acceptor()
{
}

void Acceptor::setNrOfStates(unsigned int nrOfStates)
{
	this->nrOfStates = nrOfStates;
}

unsigned int Acceptor::getNrOfStates()
{
	return this->nrOfStates;
}

void Acceptor::setRow(StateBehaviour* pRow)
{
	this->table.push_back(*pRow);
}

StateBehaviour* Acceptor::getRow(int i)
{
	return &(this->table.at(i));
}


void Acceptor::define()
{
	for (unsigned int i = 0; i < this->getNrOfStates(); i++)
	{
		StateBehaviour row = StateBehaviour();
		unsigned int temp1;
		bool temp2;
		// Struct an seinen Platz im Array setzen
		this->setRow(&row);
		// Platz im Array + 1 ist gleichzeitig Zustandbezeichner
		this->table.at(i).setState(i + 1);
		// Abbildungsverhalten einlesen
		std::cout << "\n\nZustand " << this->table.at(i).getState() << ":";
		std::cout << "\nIst dies ein akzeptierter Zustand? (1 = ja, 0 = nein) ";
		std::cin >> temp2;
		this->table.at(i).setFavourable(temp2);
		std::cout << "\nAbbildungsverhalten A eingeben: ";
		std::cin >> temp1;
		this->table.at(i).setTransformedState_a(temp1);
		std::cout << "\nAbbildungsverhalten B eingeben: ";
		std::cin >> temp1;
		this->table.at(i).setTransformedState_b(temp1);
	}
}

void Acceptor::printStateBehaviourTable()
{
	std::cout << "\n\nZustandsueberfuehrungstabelle:";
	std::cout << "\n\nZ - F - a - b\n";
	for (int i = 0; i < this->getNrOfStates(); i++)
	{
		std::cout << this->table.at(i).getState() << " - " << this->table.at(i).getFavourable() << " - " << this->table.at(i).getTransformedState_a() << " - " << this->table.at(i).getTransformedState_b() << "\n";
	}
}