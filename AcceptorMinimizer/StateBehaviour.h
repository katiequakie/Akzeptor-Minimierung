#pragma once
#include "EquivalenceClass.h"

class StateBehaviour
{
public:
	StateBehaviour();
	~StateBehaviour();
private:
	unsigned int state;
	bool favourable;
	unsigned int transformedState_a;
	unsigned int transformedState_b;
	EquivalenceClass* pEquivalenceClass;
public:
	void setState(unsigned int state);
	unsigned int getState();
	void setFavourable(bool fav);
	bool getFavourable();
	void setTransformedState_a(unsigned int transformedState_a);
	unsigned int getTransformedState_a();
	void setTransformedState_b(unsigned int transformedState_b);
	unsigned int getTransformedState_b();
	void setEquivalenceClass(EquivalenceClass* pEquivalenceClass);
	EquivalenceClass* getEquivalenceClass();
};

