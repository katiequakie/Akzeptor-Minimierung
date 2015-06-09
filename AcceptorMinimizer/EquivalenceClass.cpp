#include "EquivalenceClass.h"


EquivalenceClass::EquivalenceClass()
{
	representantive = 0;
	wordLength = 0;
}

EquivalenceClass::EquivalenceClass(int wordLength)
: representantive(0)
, wordLength(wordLength)
{
}

EquivalenceClass::~EquivalenceClass()
{
}

void EquivalenceClass::setRepresentantive(int rep)
{
	this->representantive = rep;
}

int EquivalenceClass::getRepresentantive()
{
	return this->representantive;
}

void EquivalenceClass::addEqualState(int s)
{
	this->equalStates.push_back(s);
}

int EquivalenceClass::getEqualState(int i)
{
	return this->equalStates.at(i);
}

int EquivalenceClass::getNrOfEqualStates()
{
	return this->equalStates.size();
}

void EquivalenceClass::setWordLength(int length)
{
	this->wordLength = length;
}

int EquivalenceClass::getWordLength()
{
	return this->wordLength;
}