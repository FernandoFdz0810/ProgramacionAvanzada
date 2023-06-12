#pragma warning(disable: 4996)

#include "CHora.h"

using namespace utils;

void CHora::Iniciar()
{
	m_nHoras = 0;
	m_nMinutos = 0;
	m_nSegundos = 0;
	m_pszFormato = NULL;
}

bool CHora::EsHoraCorrecta() const
{
	// Si el formato es "AM" o "PM" o "24 HORAS"
	if (Formato24() == true)
	{
		if (m_nHoras >= 0 && m_nHoras <= 24)
		{
			if (m_nMinutos >= 0 && m_nMinutos < 60)
			{
				if (m_nSegundos >= 0 && m_nMinutos < 60)
					return true;
				else
				{
					cout << "Segundos incorrectas. Introduzca datos de nuevo\n";
					return false;
				}
			}
			else
			{
				cout << "Minutos incorrectas. Introduzca datos de nuevo\n";
				return false;
			}
		}
		else
		{
			cout << "Horas incorrectas. Introduzca datos de nuevo\n";
			return false;
		}
	}

	else
	{
		if (strcmp(m_pszFormato, "AM") == 0 || strcmp(m_pszFormato, "PM") == 0)
		{
			if (m_nHoras >= 0 && m_nHoras <= 12)
			{
				if (m_nMinutos >= 0 && m_nMinutos < 60)
				{
					if (m_nSegundos >= 0 && m_nMinutos < 60)
						return true;
					else
					{
						cout << "Segundos incorrectos. Introduzca datos de nuevo\n";
						return false;
					}
				}
				else
				{
					cout << "Minutos incorrectos. Introduzca datos de nuevo\n";
					return false;
				}
			}
			else
			{
				cout << "Horas incorrectas. Introduzca datos de nuevo\n";
				return false;
			}
		}

		else
		{
			cout << "Formato incorrecto. Introduzca datos de nuevo \n";
			return false;
		}
		
	}
	
	return false;
}

bool CHora::AsignarHora(int nHoras, int nMinutos, int nSegundos, char *pszFormato)
{
	if (m_pszFormato != NULL)
		CHora::Destruir();

	m_nHoras = nHoras;
	m_nMinutos = nMinutos;
	m_nSegundos = nSegundos;
	AsignarFormato(pszFormato);

	// Despues de asignar los valores comprobamos que el formato de la hora sea el correcto.

	if (EsHoraCorrecta() != true)
	{
		cout << "La hora introducida no concuerda con el formato, vuelva a introducirlo\n\n";
		return false;
	}

	else
		return true;
}

bool CHora::AsignarFormato(char* pszFormato)
{
	if (pszFormato == NULL)
	{
		cout << "\n ERROR: Formato incorrecto, introduzca de nuevo los datos." << endl;
		return false;
	}
	else
	{
		m_pszFormato = new (nothrow) char[strlen(pszFormato) + 1];

		if (m_pszFormato == NULL)
			return false;

		strcpy(m_pszFormato, pszFormato);
		m_pszFormato = CUtils::ConverMayus(m_pszFormato);

		return true;
	}
}

bool CHora::Formato24() const
{
	if (strcmp(m_pszFormato, "24 HORAS") == 0)
	{
		return true;
	}

	else
		return false;
}

void CHora::Destruir()
{
	if (m_pszFormato == NULL)
		return;

	delete[] m_pszFormato;

	Iniciar();
}

void CHora::ObtenerHora(int& nHoras, int& nMinutos, int& nSegundos, char* pszFormato) const
{
	nHoras = m_nHoras;
	nMinutos = m_nMinutos;
	nSegundos = m_nSegundos;

	if (m_pszFormato == NULL)
	{
		strcpy(pszFormato, "0");
		return;
	}

	if (m_pszFormato != 0 && pszFormato != 0)
		strcpy(pszFormato, m_pszFormato);
}

void VisualizarHora(const CHora& hora)
{
	int nHoras, nMinutos, nSegundos;
	char pszFormato[9];

	hora.ObtenerHora(nHoras, nMinutos, nSegundos, pszFormato);
	
	if (strcmp(pszFormato, "0") == 0)
	{
		cout << "\n Error: No hay hora establecida " << endl;
		return;
	}

	cout << "\n Horas: " << nHoras << " Minutos: " << nMinutos << " Segundos: " << nSegundos << " Formato: " << pszFormato << endl;
}

// Creacion de Constructores por defecto y constructor copia

CHora::CHora(int hh, int mm, int ss, char* ff) : m_nHoras(hh), m_nMinutos(mm), m_nSegundos(ss), m_pszFormato(0)
{
	AsignarFormato(ff);
	cout << "\nConstructor por omision invocado \n";
}

CHora::CHora(const CHora& obj) : m_nHoras(obj.m_nHoras), m_nMinutos(obj.m_nMinutos), m_nSegundos(obj.m_nSegundos), m_pszFormato(0)
{
	AsignarFormato(obj.m_pszFormato);
	cout << "\nConstructor copia invocado\n";
}

CHora& CHora::operator= (const CHora& obj)
{
	if (this == &obj)
		return *this;

	Destruir();
	
	m_nHoras = obj.m_nHoras;
	m_nMinutos = obj.m_nMinutos;
	m_nSegundos = obj.m_nSegundos;
	AsignarFormato(obj.m_pszFormato);

	cout << "\nOperador de asignacion invocado\n";

	return *this;
	
}


CHora::~CHora()
{
	Destruir();
	cout << "\nDestructor invocado\n";
}
