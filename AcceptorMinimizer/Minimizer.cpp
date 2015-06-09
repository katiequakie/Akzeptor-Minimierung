#include "Minimizer.h"
#include "StateBehaviour.h"
#include <iostream>


Minimizer::Minimizer()
: wordLength(0)
{
}

Minimizer::Minimizer(int wordLength)
: wordLength(wordLength)
{
}

Minimizer::~Minimizer()
{
}

void Minimizer::setWordLength(int length)
{
	this->wordLength = length;
}

int Minimizer::getWordLength()
{
	return this->wordLength;
}

void Minimizer::addEqClass(EquivalenceClass* pClasses)
{
	this->eqClasses.push_back(*pClasses);
}

void Minimizer::setNrOfEqClasses()
{
	this->nrOfEqClasses = this->eqClasses.size();
}

int Minimizer::getNrOfEqClasses()
{
	return this->nrOfEqClasses;
}

EquivalenceClass* Minimizer::getEqClass(int i)
{
	return &this->eqClasses.at(i);
}

void Minimizer::printEqClasses()
{
	cout << "\n\nAequivalenzklassen der " << this->getWordLength() << " - Aequivalenzrelation:";
	for (int i = 0; i < this->eqClasses.size(); i++)
	{
		cout << "\n\n[" << this->eqClasses.at(i).getRepresentantive() << "] = {";
		for (int j = 0; j < this->eqClasses.at(i).getNrOfEqualStates(); j++)
		{
			cout << eqClasses.at(i).getEqualState(j) << ", ";
		}
		cout << "}\n";
	}
}

void Minimizer::minimize(Acceptor* pAcceptor)
{
	// Zeiger auf Akzeptor zur Verwendung dereferenzieren
	Acceptor Acceptor = *pAcceptor;
	// Für 0 - Äquivalenzrelation zwei Äquivalenzklassen initialisieren
	EquivalenceClass EQ_1 = EquivalenceClass(0);
	EquivalenceClass EQ_2 = EquivalenceClass(0);
	// Liste der Zustände durchsuchen
	for (int i = 0; i < Acceptor.getNrOfStates(); i++)
	{
		// für aktuellen Zustand Zeile mit dessen Verhaltensinformationen in temporärer Variable speichern
		StateBehaviour temp_row = *(Acceptor.getRow(i));
		// ---------Equivalenzklasse 1 für gefundenen akzeptierenden Zustand bilden und füllen
		if (temp_row.getFavourable())
		{
			if (!(EQ_1.getRepresentantive()))
			{
				EQ_1.setRepresentantive(temp_row.getState());
			}
			// ist der Zustand schon enthalten?
			bool alreadyListed = false;
			// durchsuche die Äquivalenzklasse
			for (int m = 0; m < EQ_1.getNrOfEqualStates(); m++)
			{
				if (EQ_1.getEqualState(m) == temp_row.getState())
				{
					alreadyListed = true;
				}
			}
			// ist der Zustand noch nicht enthalten, füge ihn hinzu
			if (!alreadyListed)
			{
				EQ_1.addEqualState(temp_row.getState());
			}
		}
		// ---------Equivalenzklasse 2 für nicht akzeptierende Zustände bilden und füllen
		else if (!(temp_row.getFavourable()))
		{
			if (!(EQ_2.getRepresentantive()))
			{
				EQ_2.setRepresentantive(temp_row.getState());
			}
			// ist der Zustand schon enthalten?
			bool alreadyListed = false;
			// durchsuche die Äquivalenzklasse
			for (int m = 0; m < EQ_2.getNrOfEqualStates(); m++)
			{
				if (EQ_2.getEqualState(m) == temp_row.getState())
				{
					alreadyListed = true;
				}
			}
			// ist der Zustand noch nicht enthalten, füge ihn hinzu
			if (!alreadyListed)
			{
				EQ_2.addEqualState(temp_row.getState());
			}
		}
		else
			break;
	}
	this->addEqClass(&EQ_1);
	this->addEqClass(&EQ_2);
}

void Minimizer::minimize(Acceptor& pAcceptor, Minimizer& pPrevMinimizer)
{
}