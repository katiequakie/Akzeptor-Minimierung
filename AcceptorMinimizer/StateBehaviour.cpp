#include "StateBehaviour.h"
#include <iostream>

StateBehaviour::StateBehaviour()
: state(0)
, favourable(true)
, transformedState_a(0)
, transformedState_b(0)
, pEquivalenceClass(NULL)
{
}

StateBehaviour::~StateBehaviour()
{
}

void StateBehaviour::setState(unsigned int state)
{
	this->state = state;
}

unsigned int StateBehaviour::getState()
{
	return this->state;
}

void StateBehaviour::setFavourable(bool fav)
{
	this->favourable = fav;
}

bool StateBehaviour::getFavourable()
{
	return this->favourable;
}

void StateBehaviour::setTransformedState_a(unsigned int transformedState_a)
{
	this->transformedState_a = transformedState_a;
}

unsigned int StateBehaviour::getTransformedState_a()
{
	return this->transformedState_a;
}

void StateBehaviour::setTransformedState_b(unsigned int transformedState_b)
{
	this->transformedState_b = transformedState_b;
}

unsigned int StateBehaviour::getTransformedState_b()
{
	return this->transformedState_b;
}

void StateBehaviour::setEquivalenceClass(EquivalenceClass* pEquivalenceClass)
{
	this->pEquivalenceClass = pEquivalenceClass;
}

EquivalenceClass* StateBehaviour::getEquivalenceClass()
{
	return this->pEquivalenceClass;
}
