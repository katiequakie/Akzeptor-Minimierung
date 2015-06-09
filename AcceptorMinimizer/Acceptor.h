#pragma once
#include "StateBehaviour.h"

class Acceptor
{
public:
	Acceptor();
	Acceptor(unsigned int n);
	~Acceptor();
private:
	// Anzahl der Zustände
	unsigned int nrOfStates;
	// Dyn. Array aus allen Abbildungsausprägungen für a und b samt dazugehörigen Zustand
	vector<StateBehaviour> table;
public:
	void setNrOfStates(unsigned int nrOfStates);
	unsigned int getNrOfStates();
	void setRow(StateBehaviour* pRow);
	StateBehaviour* getRow(int i);
	void define();
	void printStateBehaviourTable();
};

