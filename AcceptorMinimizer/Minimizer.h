#pragma once
#include "EquivalenceClass.h"
#include "Acceptor.h"

class Minimizer
{
public:
	Minimizer();
	Minimizer(int wordLength);
	~Minimizer();
private:
	int wordLength;
	int nrOfEqClasses;
	vector<EquivalenceClass> eqClasses;
public:
	void setWordLength(int length);
	int getWordLength();
	void addEqClass(EquivalenceClass* pClass);
	EquivalenceClass* getEqClass(int i);
	void setNrOfEqClasses();
	int getNrOfEqClasses();
	void printEqClasses();
	void minimize(Acceptor* pAcceptor);
	void minimize(Acceptor& pAcceptor, Minimizer& pPrevMinimizer);
private:

};

