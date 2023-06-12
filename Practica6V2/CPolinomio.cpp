#include "CPolinomio.h"


CPolinomio::CPolinomio(double coeficiente, int exponente)	//construir un polinomio de un solo termino
{
	CMonomio mono(coeficiente, exponente);
	m_monomios.push_back(mono);		//añade el elemento al final
}


CPolinomio::CPolinomio(vector<CMonomio>& monomios)		//constructor de polinomio a partir de un vetor de la clase Cmonomio
{
	for (int i = 0; i < monomios.size(); i++)
		*this << monomios[i];
}


CPolinomio::CPolinomio(const CMonomio& monomio)			//construir polinomio a partir  de un monomio de 1 solo termino
{
	CMonomio mono(monomio);
	m_monomios.push_back(mono);
}


void CPolinomio::MostrarPoli(ostream& os) const
{
	if (!m_monomios.empty())
	{
		for (int i = 0; i < m_monomios.size(); i++)
			os << m_monomios[i] << ' ';
	}
	else
		os << "0 ";
}


CPolinomio& CPolinomio::operator<<(const CPolinomio& polinomio)
{
	*this = polinomio;

	return *this;

}


CPolinomio& CPolinomio::operator<<(const CMonomio& mono) //operador de asignacion monomio
{
	int pos = 0;
	CMonomio aux;

	if (mono.GetCoef() != 0)
	{
		if (m_monomios.empty())					//el vector esta vacio
			m_monomios.push_back(mono);
		else
		{
			m_monomios.insert(m_monomios.begin(), 1, mono);	//lo inserta al principio

			for (pos; pos + 1 < m_monomios.size(); pos++)
			{
				if (m_monomios[pos].GetExp() <= m_monomios[pos + 1].GetExp())
				{
					if (m_monomios[pos].GetExp() < m_monomios[pos + 1].GetExp())
					{
						aux = m_monomios[pos];
						m_monomios[pos] = m_monomios[pos + 1];
						m_monomios[pos + 1] = aux;
					}
					else
					{
						aux.SetCoef(m_monomios[pos].GetCoef() + m_monomios[pos + 1].GetCoef());
						aux.SetExp(m_monomios[pos].GetExp());
						m_monomios[pos] = aux;
						m_monomios.erase(m_monomios.begin() + (pos + 1));

						if (m_monomios[pos].GetCoef() == 0)
							m_monomios.erase(m_monomios.begin() + pos);
					}
				}
			}
		}
	}

	return *this;
}
// si el coeficiente no es cero, se añade al polinomio; si es cero no se añade.
	// si la lista está vacía, nuevo término al principio
	// si la lista no está vacía...
		// buscar un exponente igual o menor que el de "mono"
			// si el exponente es igual que el de "mono"
				// suma los coeficientes
				// si suman cero
					// borrar término de la lista
				// devolver el polinomio
			// si el exponente es menor que el de "mono"
				// crear un nuevo término
					// e incluirlo correctamente
				// devolver el polinomio
			// si el exponente es mayor que el de "mono"
			// seguir buscando
		// si llegamos al final de la lista
		// crear nuevo término e incluirlo al final
// devolver el polinomio


int CPolinomio::Grado() const
{
	int grado;

	if (m_monomios.empty())
		grado = 0;
	else
		grado = m_monomios.begin()->GetExp();

	return grado;
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

	for (int i = 0; i < unario.m_monomios.size(); i++)
		unario.m_monomios[i] = -unario.m_monomios[i];

	return unario;
}


const CPolinomio CPolinomio::operator+(const CPolinomio& polinomio)
{
	CPolinomio suma = *this;

	for (int i = 0; i < polinomio.m_monomios.size(); i++)
		suma << polinomio.m_monomios[i];

	return suma;
}


const CPolinomio CPolinomio::operator-(const CPolinomio& polinomio)
{
	CPolinomio resta = *this;

	for (int i = 0; i < polinomio.m_monomios.size(); i++)
		resta << -(polinomio.m_monomios[i]);

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

	for (int i = 0; i < m_monomios.size(); i++)
	{
		if (exponente == m_monomios[i].GetExp())
		{
			coeficiente = m_monomios[i].GetCoef();
			return coeficiente;
		}
		else
			coeficiente = 0;
	}

	return coeficiente;
}


double CPolinomio::operator()(float x)
{
	double resultado = 0;

	for (int i = 0; i < m_monomios.size(); i++)
		resultado += m_monomios[i].GetCoef() * (pow(x, m_monomios[i].GetExp()));

	return resultado;
}


const CPolinomio CPolinomio::operator*(const CPolinomio& polinomio)
{
	CPolinomio aux;
	double coef; 
	int exp;

	for (int i = 0; i < this->m_monomios.size(); i++)
		for (int j = 0; j < polinomio.m_monomios.size(); j++)
		{
			coef = this->m_monomios[i].GetCoef() * polinomio.m_monomios[j].GetCoef();
			exp = this->m_monomios[i].GetExp() + polinomio.m_monomios[j].GetExp();
			CMonomio mono(coef, exp);
			aux << mono;
		}

	return aux;
}


CPolinomio& CPolinomio::operator*=(const CPolinomio& polinomio)
{
	*this = *this * polinomio;
	return *this;
}




ostream& operator<<(ostream& os, const CPolinomio& Poli)
{
	Poli.MostrarPoli(cout);
	return os;
}