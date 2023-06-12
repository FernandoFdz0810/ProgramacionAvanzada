#include "CMonomio.h"

ostream& operator<<(ostream& os, const CMonomio& mono)
{
	os << showpos; // Poner + para valores positivos
	if (!mono.GetExp()) //Si la x esta elevada a 0
		os << mono.GetCoef(); //vale 1 y se muestra solo el coef.
	else 
	{
		if (mono.GetCoef() != 1)
			os << mono.GetCoef(); //Mostrar el coeficiente si solo es distinto que 1
		os << noshowpos;
		if (mono.GetExp() == 1) // Si el exponente es 1
			os << 'x';	//Basta x
		else
			os << "x^" << mono.GetExp(); // Si no, ponemos x^...
	}

	os << noshowpos;
	return os; //Devolver referencia al ostream recibido para permitir el encadenamieno: cout << m1 << m2...
}