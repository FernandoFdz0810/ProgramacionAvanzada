#include"CHora.h"

using namespace utils;


bool CHora::AsignarFormato(string pszFormato)
{
	if (pszFormato == "0")
	{
		cout << "\n ERROR: Formato incorrecto, introduzca de nuevo los datos." << endl;
		Destruir();		// Borra el objeto por seguridad
		return false;
	}
	else
	{
		m_pszFormato = pszFormato;
		m_pszFormato = CUtils::ConverMayus(m_pszFormato);

		return true;
	}
}


bool CHora::Formato24() const
{
	if (m_pszFormato == "24 HORAS")
		return true;
	else
		return false;
}


bool CHora::EsHoraCorrecta() const
{
	if (Formato24() == true)
		if (m_nHoras >= 0 && m_nHoras <= 23 && m_nMinutos >= 0 && m_nMinutos <= 59 && m_nSegundos >= 0 && m_nSegundos <= 59)
			return true;

	if (m_pszFormato == "AM" || m_pszFormato == "PM")
		if (m_nHoras >= 0 && m_nHoras <= 12 && m_nMinutos >= 0 && m_nMinutos <= 59 && m_nSegundos >= 0 && m_nSegundos <= 59)
			return true;

	return false;
}


void CHora::Iniciar()
{
	m_nHoras = 0;
	m_nMinutos = 0;
	m_nSegundos = 0;
	m_pszFormato = "0";
}


bool CHora::AsignarHora(int nHoras, int nMinutos, int nSegundos, string pszFormato)
{
	if (m_pszFormato != "0")	// resuelve falla al introducir una segunda hora
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


void CHora::ObtenerHora(int& nHoras, int& nMinutos, int& nSegundos, string& pszFormato) const
{
	nHoras = m_nHoras;
	nMinutos = m_nMinutos;
	nSegundos = m_nSegundos;

	// Revisar si el bucle if es correcto. 

	/*
	if (m_pszFormato == nullptr)
		strcpy(pszFormato, "0");	// resuelve falla de la visualizacion(pszformato vacio)
	else
	*/

	pszFormato = m_pszFormato;
}


void CHora::Destruir()
{
	if (m_pszFormato == "0") //check
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

	hora.ObtenerHora(nHoras, nMinutos, nSegundos, pszFormato);

	if (pszFormato == "0") //check hora
	{
		cout << "\n ERROR: No hay hora establecida." << endl;
		return;
	}

	cout << "\n HORA: " << nHoras << ":" << nMinutos << ":" << nSegundos << " " << pszFormato << endl;
	system("pause");
}


CHora::CHora(int hh, int mm, int ss, const string ff) : m_nHoras(hh), m_nMinutos(mm), m_nSegundos(ss), m_pszFormato(ff)
{
	AsignarFormato(ff);
	cout << "\n Constructor por omision invocado." << endl;
}
/**/


CHora::CHora(const CHora& obj) : m_nHoras(obj.m_nHoras), m_nMinutos(obj.m_nMinutos), m_nSegundos(obj.m_nSegundos)
{
	AsignarFormato(obj.m_pszFormato);
	cout << "\n Constructor copia invocado." << endl;
}


CHora& CHora::operator= (const CHora& obj_asg)
{
	if (this == &obj_asg) return *this;

	Destruir();	//Parametros a 0

	m_nHoras = obj_asg.m_nHoras;
	m_nMinutos = obj_asg.m_nMinutos;
	m_nSegundos = obj_asg.m_nSegundos;
	AsignarFormato(obj_asg.m_pszFormato);

	cout << "\n Operador de asignacion invocado." << endl;

	return *this;
}

CHora::~CHora()
{
	Destruir();
	cout << "\n Destructor invocado." << endl;
}