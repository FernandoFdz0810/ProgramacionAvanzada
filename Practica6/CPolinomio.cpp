#include "CPolinomio.h"

//Constructor sin parametros

CPolinomio::CPolinomio()
{
	m_pCabecera = NULL;
}

//Constructor copia

CPolinomio::CPolinomio(const CPolinomio& obj) :m_pCabecera(NULL)
{
	if (obj.m_pCabecera == NULL)
		m_pCabecera = NULL;

	else {
		CTermino* aux = obj.m_pCabecera;

		do
		{
			*this << aux->GetMono();
			aux = aux->GetSig();
		} while (aux != NULL);
		// Se hace uso del operador de asignacion "<<" del punto 7.
	}
}

//Constructor polinomio con 1 termino

CPolinomio::CPolinomio(double coeficiente, int exponente)
{
	if (coeficiente == 0)
	{
		m_pCabecera = new (nothrow) CTermino;
		m_pCabecera = NULL;
	}

	else
	{
		m_pCabecera = new (nothrow) CTermino(coeficiente, exponente);
	}
}

//Constructor de polinomio a partir de un vector de la clase CMonomio

CPolinomio::CPolinomio(vector<CMonomio>& monomios)
{
	for (unsigned int i = 0; i < monomios.size(); i++)
	{
		*this << monomios[i];
	}
}

// Constructor polinomio a partir de un monomio

CPolinomio::CPolinomio(const CMonomio& monomio)
{
	if (monomio.GetCoef() == 0)
	{
		m_pCabecera = new (nothrow) CTermino;
		m_pCabecera = NULL;
	}

	else
		m_pCabecera = new (nothrow) CTermino(monomio);
}

// Destructor para liberar la memoria dinámica

CPolinomio::~CPolinomio()
{
	CTermino* aux;
	CTermino* aux2;

	aux = m_pCabecera;

	while (aux != NULL)
	{
		aux2 = aux->GetSig();
		delete aux;
		aux = aux2;
	}
}

CPolinomio& CPolinomio::operator<<(const CPolinomio& polinomio)
{
	if (m_pCabecera == polinomio.m_pCabecera)
		return *this;
	else
	{
		CTermino* aux = polinomio.m_pCabecera;

		while (aux != NULL)
		{
			*this << aux->GetMono();
			aux = aux->GetSig();
		}

		return *this;
	}

}

CPolinomio& CPolinomio::operator<<(const CMonomio& mono)
{
	// Si el coeficiente no es 0, se añade al polinomio, si es cero no se añadwe
	if (mono.GetCoef() != 0)
	{
		// Si la lista está vacia, nuevo término al principio
		if (m_pCabecera == NULL)
		{
			CTermino* pPos = new (nothrow) CTermino(mono);
			pPos->SetSig(NULL);
			m_pCabecera = pPos;
		}
		// Si la lista no esta vacia
		else
		{
			CTermino* pPos = new (nothrow) CTermino(mono);
			CTermino* pAnterior;
			CTermino* nuevo;
			CMonomio aux;

			double CoefpA, Coefn; // Suma de coeficientes de tipo double

			pAnterior = m_pCabecera;
			nuevo = pPos;
			nuevo->SetSig(pAnterior);
			m_pCabecera = nuevo;

			//Buscar un exponente igual o menor que el de "mono"
			if (nuevo->GetExp() <= pAnterior->GetExp())
			{
				while (nuevo != NULL)
				{
					pAnterior = nuevo->GetSig(); //Puntero al siguiente termino

					if ((pAnterior != NULL) && (nuevo->GetExp() < pAnterior->GetExp()))
					{
						aux.SetCoef(nuevo->GetCoef());
						aux.SetExp(nuevo->GetExp());
						nuevo->SetMono(pAnterior->GetMono());
						pAnterior->SetMono(aux);
					}

					else // Si el exponente es igual que el del monomio
					{
						if ((pAnterior != NULL) && (nuevo->GetExp() == pAnterior->GetExp()))
						{
							//Sumar los coeficiente
							pAnterior = nuevo->GetSig();
							CoefpA = pAnterior->GetCoef();
							Coefn = nuevo->GetCoef();
							nuevo->SetCoef(CoefpA + Coefn);

							pAnterior = nuevo;
							nuevo = nuevo->GetSig();
							pAnterior->SetSig(nuevo->GetSig());
							delete nuevo;
							nuevo = pAnterior;

							//Si suman 0
							if (nuevo->GetCoef() == 0)
							{
								//borrar termino de la lista
								nuevo = nuevo->GetSig();

								if (nuevo != NULL)
								{
									pAnterior->SetSig(nuevo->GetSig());
									pAnterior->SetMono(nuevo->GetMono());
									delete nuevo;
									nuevo = pAnterior;
								}

								else
								{
									pAnterior->SetMono(0);
									pAnterior->SetSig(NULL);
									nuevo = pAnterior;
								}
								// devolver el polinomio
							}
						}

						nuevo = nuevo->GetSig();
					}
				}
			}
		}
	}

	return *this;
}

//Mostrar Grado Polinomio

int CPolinomio::Grado() const
{
	return m_pCabecera->GetExp();
}

bool CPolinomio::operator==(const CPolinomio& polinomio)
{
	return Grado() == polinomio.Grado();
}

bool CPolinomio::operator<(const CPolinomio& polinomio)
{
	return Grado() < polinomio.Grado();
}

bool CPolinomio::operator>(const CPolinomio& polinomio)
{
	return Grado() > polinomio.Grado();
}

CPolinomio CPolinomio::operator-() const
{
	CPolinomio unario = *this;
	CTermino* aux = unario.m_pCabecera;
	CMonomio mono;

	while (aux != NULL)
	{
		mono = aux->GetMono();
		aux->SetMono(-mono);
		aux = aux->GetSig();
	}

	return unario;
}

const CPolinomio CPolinomio::operator+(const CPolinomio& polinomio)
{
	CPolinomio suma = *this;
	CTermino* aux;

	aux = polinomio.m_pCabecera;

	while (aux != NULL)
	{
		suma << aux->GetMono();
		aux = aux->GetSig();
	}

	return suma;
}

const CPolinomio CPolinomio::operator-(const CPolinomio& polinomio)
{
	CPolinomio resta = *this;
	CTermino* aux;

	aux = polinomio.m_pCabecera;

	while (aux != NULL)
	{
		resta << -(aux->GetMono());
		aux = aux->GetSig();
	}

	return resta;
}

CPolinomio& CPolinomio::operator+=(const CPolinomio& polinomio)
{
	*this = *this + polinomio;
	return *this;
}

CPolinomio& CPolinomio::operator-=(const CPolinomio& polinomio)
{
	*this = *this - polinomio;
	return *this;
}

double CPolinomio::operator[](int exponente)
{
	double coeficiente = 0;
	CTermino* aux;

	aux = m_pCabecera;

	if (exponente > aux->GetExp() || exponente == 0)
		coeficiente = 0;

	else
	{
		while (aux != NULL)
		{
			if (exponente == aux->GetExp())
			{
				coeficiente = aux->GetCoef();
				return coeficiente;
			}
			else
			{
				coeficiente = 0;
			}

			//Continuacion con el siguiente termino hasta encontrar NULL
			aux = aux->GetSig();
		}
	}

	return coeficiente;
}

double CPolinomio::operator()(float x)
{
	CTermino* aux = m_pCabecera;
	double resultado = 0;

	while (aux != NULL)
	{
		resultado += aux->GetCoef() * (pow(x, aux->GetExp()));
		aux = aux->GetSig();
	}

	return resultado;
}

const CPolinomio CPolinomio::operator*(const CPolinomio& polinomio)
{
	CTermino* pPosPoli;
	CTermino* pPos = m_pCabecera;
	CPolinomio aux;

	while (pPos != NULL)
	{
		pPosPoli = polinomio.m_pCabecera;

		while (pPosPoli != NULL)
		{
			aux << CMonomio((pPos->GetCoef() * pPosPoli->GetCoef()), (pPos->GetExp() + pPosPoli->GetExp()));
			pPosPoli = pPosPoli->GetSig();
		}

		pPos = pPos->GetSig();
	}
	return aux;
}

const CPolinomio CPolinomio::operator*=(const CPolinomio& polinomio)
{
	*this = *this * polinomio;
	return *this;
}

CPolinomio& CPolinomio::operator=(const CPolinomio& polinomio)
{
	CTermino* aux = m_pCabecera;

	if (aux == polinomio.m_pCabecera)
		return *this;

	// Comprobamos si el polinomio en el que queremos guardar esta vacio,
	//  si no, se borra el contenido.

	if (aux != NULL)
	{
		while (aux != NULL)
		{
			m_pCabecera = aux->GetSig();
			delete aux;
			aux = m_pCabecera;
		}
	}

	aux = polinomio.m_pCabecera;

	while (aux != NULL)
	{
		*this << aux->GetMono();
		aux = aux->GetSig();
	}

	return *this;
}

void CPolinomio::MostarPoli(ostream& os) const
{
	const CTermino* pPos = m_pCabecera;

	if (pPos)
	{
		do
		{
			os << pPos->GetMono() << ' ';
			pPos = pPos->GetSig();
		} while (pPos);
	}

	else
	{
		os << "0";
	}
}

ostream& operator<<(ostream& os, const CPolinomio& Poli)
{
	Poli.MostarPoli(cout);
	return os;
}

