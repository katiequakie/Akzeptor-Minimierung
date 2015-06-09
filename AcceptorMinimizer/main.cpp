// Dies ist ein Programm zum Minimieren eines benutzerdefinierten Akzeptors.
// Das Programm verlangt zu Beginn einige Informationen über den Akzeptor und speichert diese
// in einer Instanz der Klasse "Acceptor". 

#include "Acceptor.h"
#include "StateBehaviour.h"
#include "Minimizer.h"
#include <iostream>
#include <stdlib.h>

int main(int argc, const char* argv[])
{
	unsigned int n;
	std::cout << "Anzahl der Zustaende des zu minimierenden Akzeptors : \n";
	std::cin >> n;
	Acceptor A = Acceptor(n);
	A.define();
	A.printStateBehaviourTable();

	int i = 0;
	Minimizer M_a, M_b;
	do
	{
		if (M_a.getWordLength() == 0)
		{
			M_a = Minimizer(i);
			M_a.minimize(&A);
			M_a.printEqClasses();
			M_b = Minimizer(i + 1);
			M_b.minimize(&A, &M_a);
			i++;
		}
		else
			M_a = M_b;
			M_b = Minimizer(i);
			M_b.minimize(&A, &M_a);
			i++;
	} while (M_a.getNrOfEqClasses() != M_b.getNrOfEqClasses());

	system ("pause");
	return 0;
}