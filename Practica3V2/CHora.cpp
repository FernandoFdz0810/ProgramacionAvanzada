#include"CHora.h"
#include"utils.h"

/*

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
*/


bool CHora::Formato24() const
{
	if (m_sFormato == "24 HORAS")
		return true;
	else
		return false;
}


bool CHora::EsHoraCorrecta() const
{
	if (Formato24() == true)
		if (m_nHoras >= 0 && m_nHoras <= 23 && m_nMinutos >= 0 && m_nMinutos <= 59 && m_nSegundos >= 0 && m_nSegundos <= 59)
			return true;

	if (m_sFormato == "AM" || m_sFormato == "PM")
		if (m_nHoras >= 0 && m_nHoras <= 12 && m_nMinutos >= 0 && m_nMinutos <= 59 && m_nSegundos >= 0 && m_nSegundos <= 59)
			return true;

	return false;
}


void CHora::Iniciar()
{
	m_nHoras = 0;
	m_nMinutos = 0;
	m_nSegundos = 0;
	m_sFormato = "0";
}


bool CHora::AsignarHora(int nHoras, int nMinutos, int nSegundos, string& Formato)
{
	if (m_sFormato != "0")
	{ 
		Destruir();
	}// resuelve falla al introducir una segunda hora
		

	m_nHoras = nHoras;
	m_nMinutos = nMinutos;
	m_nSegundos = nSegundos;
	ConverMayus(Formato);
	m_sFormato = Formato;


	// AsignarFormato(pszFormato);

	if (EsHoraCorrecta() != true)
	{
		cout << "\n ERROR: Formato incorrecto, introduzca de nuevo los datos." << endl;
		return false;
	}

	return true;
}


void CHora::ObtenerHora(int& nHoras, int& nMinutos, int& nSegundos, string& Formato) const
{
	nHoras = m_nHoras;
	nMinutos = m_nMinutos;
	nSegundos = m_nSegundos;

	/*
	if (m_sFormato == "0") // DUDAS AQUI, SOBRE COMO CONTINUAR
	{
		Formato = "0";	// resuelve falla de la visualizacion(pszformato vacio)
		return;
	}
	*/
	Formato =  m_sFormato;
	
}


void CHora::Destruir()
{
	if (m_sFormato == "0")//check
	{
		m_nHoras = 0;
		m_nMinutos = 0;
		m_nSegundos = 0;

		return;
	}

	else
		Iniciar();
}

void VisualizarHora(const CHora& hora)
{
	int  nHoras, nMinutos, nSegundos;
	string pszFormato;

	// Dudas obtener hora

	hora.ObtenerHora(nHoras, nMinutos, nSegundos, pszFormato);

	if (pszFormato == "0") //check hora
	{
		cout << "\n ERROR: No hay hora establecida." << endl;
		return;
	}

	cout << "\n HORA: " << nHoras << ":" << nMinutos << ":" << nSegundos << " " << pszFormato << endl;
}