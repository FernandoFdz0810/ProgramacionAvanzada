#pragma warning(disable: 4996)
#include"CHora.h"
#include"utils.h"

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
		m_pszFormato = ConverMayus(m_pszFormato);

		return true;
	}
}


bool CHora::Formato24() const
{
	if (strcmp(m_pszFormato, "24 HORAS") == 0)
		return true;
	else
		return false;
}


bool CHora::EsHoraCorrecta() const
{
	if (Formato24() == true)
		if (m_nHoras >= 0 && m_nHoras <= 23 && m_nMinutos >= 0 && m_nMinutos <= 59 && m_nSegundos >= 0 && m_nSegundos <= 59)
			return true;

	if (strcmp(m_pszFormato, "AM") == 0 || strcmp(m_pszFormato, "PM") == 0)
		if (m_nHoras >= 0 && m_nHoras <= 12 && m_nMinutos >= 0 && m_nMinutos <= 59 && m_nSegundos >= 0 && m_nSegundos <= 59)
			return true;

	return false;
}


void CHora::Iniciar()
{
	m_nHoras = 0;
	m_nMinutos = 0;
	m_nSegundos = 0;
	m_pszFormato = NULL;
}


bool CHora::AsignarHora(int nHoras, int nMinutos, int nSegundos, char* pszFormato)
{
	if (m_pszFormato != NULL)	// resuelve falla al introducir una segunda hora
		Destruir();

	m_nHoras = nHoras;
	m_nMinutos = nMinutos;
	m_nSegundos = nSegundos;
	AsignarFormato(pszFormato);

	if (EsHoraCorrecta() != true)
	{
		cout << "\n ERROR: Formato incorrecto, introduzca de nuevo los datos." << endl;
		return false;
	}

	return true;
}


void CHora::ObtenerHora(int& nHoras, int& nMinutos, int& nSegundos, char* pszFormato) const
{
	nHoras = m_nHoras;
	nMinutos = m_nMinutos;
	nSegundos = m_nSegundos;

	if (m_pszFormato == NULL)
	{
		strcpy(pszFormato, "0");	// resuelve falla de la visualizacion(pszformato vacio)
		return;
	}

	strcpy(pszFormato, m_pszFormato);
}


void CHora::Destruir()
{
	if (m_pszFormato == NULL) //check
		return;

	delete[] m_pszFormato;
	Iniciar();
}

void VisualizarHora(const CHora& hora)
{
	int  nHoras, nMinutos, nSegundos;
	char pszFormato[9];

	hora.ObtenerHora(nHoras, nMinutos, nSegundos, pszFormato);

	if (strcmp(pszFormato, "0") == 0) //check hora
	{
		cout << "\n ERROR: No hay hora establecida." << endl;
		return;
	}

	cout << "\n HORA: " << nHoras << ":" << nMinutos << ":" << nSegundos << " " << pszFormato << endl;
}