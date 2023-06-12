#include"CFicha.h"

using namespace utils;


CFicha::CFicha(const string& sNombre, int nEdad, int nHoras, int nMinutos, int nSegundos, const string & sFormato) : m_sNombre(sNombre), m_nEdad(nEdad), m_horaNacio(nHoras, nMinutos, nSegundos)
{
	AsignarNombre(sNombre);
	cout << "\n Constructor por omision invocado(CFicha)." << endl;
}


void CFicha::AsignarNombre(const string& sNombre)
{
	m_sNombre = sNombre;
}


string CFicha::ObtenerNombre() const
{
	return this->m_sNombre;
}


void CFicha::AsignarEdad(int nEdad)
{
	m_nEdad = nEdad;
}


int CFicha::ObtenerEdad() const
{
	return m_nEdad;
}


bool CFicha::AsignarNacio(int nHoras, int nMinutos, int nSegundos, const string& sFormato)
{
	return(m_horaNacio.AsignarHora(nHoras, nMinutos, nSegundos, sFormato));
}

//CHora& CFicha::ObtenerNacio()
CHora CFicha::ObtenerNacio() const
{
	return m_horaNacio;
}


CFicha::~CFicha(void)
{
	cout << "\n Destructor invocado(CFicha)." << endl;
}

void CFicha::Visualizar()
{
	cout << "\n Nombre: " << ObtenerNombre() << endl;
	cout << "\n Edad: " << ObtenerEdad() << endl;
	cout << "\n Hora de nacimiento: ";
	VisualizarHora(m_horaNacio);
}
