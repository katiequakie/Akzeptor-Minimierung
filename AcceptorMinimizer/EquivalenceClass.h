#pragma once
#include <vector>

using namespace std;

class EquivalenceClass
{
public:
	EquivalenceClass();
	EquivalenceClass(int wordLength);
	~EquivalenceClass();
private:
	int representantive;
	vector<int> equalStates;
	int wordLength;
public:
	void setRepresentantive(int rep);
	int getRepresentantive();
	void addEqualState(int s);
	int getEqualState(int i);
	int getNrOfEqualStates();
	void setWordLength(int length);
	int getWordLength();
};

